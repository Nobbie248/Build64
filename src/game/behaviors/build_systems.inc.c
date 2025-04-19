#include <PR/ultratypes.h>

#include "include/sm64.h"
#include "include/behavior_data.h"
#include "src/engine/graph_node.h"
#include "src/engine/math_util.h"
#include "src/engine/surface_collision.h"
#include "src/game/interaction.h"
#include "src/game/mario.h"
#include "src/game/memory.h"
#include "include/object_fields.h"
#include "src/game/object_helpers.h"
#include "src/game/object_list_processor.h"
#include "src/game/save_file.h"
#include "src/buffers/buffers.h"

// this setup uses up to 130kb of ram while keeping things persistent over the game
// saving to sram is possible but this will come later
#define GRID_SIZE 300 // size of each block placement
#define GRID_MAP_SIZE 64 // total size of grid in each stage
#define MAX_LEVELS 32 // do not put less then 31 or it can crash
#define MAX_PLACED_BLOCKS_PER_LEVEL 1024
#define MARKER_TYPE_COUNT 10 // preview object models
#define BLOCK_TYPE_COUNT 10 // types of objects to place

struct PlacedBlockInstance {
    u32 x:6 , y: 6, z: 6;
    u32 type: 5, yaw: 2;
};

static struct PlacedBlockInstance gPlacedBlocks[MAX_LEVELS][MAX_PLACED_BLOCKS_PER_LEVEL];
static u16 gPlacedBlockCounts[MAX_LEVELS];

struct Object *marker = NULL;
u8 gIsHotbar = FALSE;
s16 gBlockRotationYaw = 0;
u8 gSelectedBlockType = 0;
u8 gSelectedMarkerType = 0;
u8 gIsMarkerActive = FALSE;

static const u32 PreviewModels[MARKER_TYPE_COUNT] = {
    MODEL_MARKER, MODEL_MARKER2, MODEL_MARKER, MODEL_MARKER, MODEL_MARKER,
    MODEL_MARKER, MODEL_MARKER, MODEL_MARKER, MODEL_MARKER, MODEL_MARKER
};

static const BehaviorScript *PreviewBehaviors[MARKER_TYPE_COUNT] = { // dont need to change in most cases
    bhvMarker, bhvMarker, bhvMarker, bhvMarker, bhvMarker,
    bhvMarker, bhvMarker, bhvMarker, bhvMarker, bhvMarker
};

static const u32 BlockModels[BLOCK_TYPE_COUNT] = {
    MODEL_BLOCK, MODEL_BLOCK2, MODEL_BLOCK, MODEL_BLOCK, MODEL_BLOCK,
    MODEL_BLOCK, MODEL_BLOCK, MODEL_BLOCK, MODEL_BLOCK, MODEL_BLOCK
};

static const BehaviorScript *BlockBehaviors[BLOCK_TYPE_COUNT] = {
    bhvBlock, bhvBlock2, bhvBlock, bhvBlock, bhvBlock,
    bhvBlock, bhvBlock, bhvBlock, bhvBlock, bhvBlock
};

s32 to_grid_index(f32 pos) {
    return (s32)(roundf(pos / GRID_SIZE) + (GRID_MAP_SIZE / 2));
}

s32 from_grid_index(s32 i) {
    return i * GRID_SIZE - (GRID_MAP_SIZE / 2 * GRID_SIZE);
}

struct PlacedBlockInstance *find_placed_block(s32 level, u8 x, u8 y, u8 z) {
    for (s32 i = 0; i < gPlacedBlockCounts[level]; i++) {
        struct PlacedBlockInstance *b = &gPlacedBlocks[level][i];
        if (b->x == x && b->y == y && b->z == z) {
            return b;
        }
    }
    return NULL;
}

void place_block(s32 level, u8 x, u8 y, u8 z, u8 type, u8 yaw) {
    struct PlacedBlockInstance *b = find_placed_block(level, x, y, z);
    if (b) {
        b->type = type;
        b->yaw = yaw;
    } else if (gPlacedBlockCounts[level] < MAX_PLACED_BLOCKS_PER_LEVEL) {
        struct PlacedBlockInstance *newBlock = &gPlacedBlocks[level][gPlacedBlockCounts[level]++];
        newBlock->x = x;
        newBlock->y = y;
        newBlock->z = z;
        newBlock->type = type;
        newBlock->yaw = yaw;
    }
}

void remove_block(s32 level, u8 x, u8 y, u8 z) {
    for (s32 i = 0; i < gPlacedBlockCounts[level]; i++) {
        struct PlacedBlockInstance *b = &gPlacedBlocks[level][i];
        if (b->x == x && b->y == y && b->z == z) {
            gPlacedBlocks[level][i] = gPlacedBlocks[level][--gPlacedBlockCounts[level]];
            return;
        }
    }
}

void bhv_marker_loop(void) { // not in use yet
    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
}

// this is the ui for placing
void update_marker(struct MarioState *m) {
    if (((m->action == ACT_DISAPPEARED) ||
         (m->action == ACT_PUSHING_DOOR) ||
         (m->action == ACT_PULLING_DOOR) ||
         (m->flags & MARIO_TELEPORTING) ||
         (gPlayer1Controller->buttonPressed & B_BUTTON)) && marker != NULL) {
        gIsHotbar = FALSE;
        obj_mark_for_deletion(marker);
        marker = NULL;
        gIsMarkerActive = FALSE;
        return;
    }

    if ((gPlayer1Controller->buttonPressed & L_TRIG) && marker == NULL) {
        marker = spawn_object(m->marioObj, PreviewModels[gSelectedMarkerType], PreviewBehaviors[gSelectedMarkerType]);
        gIsHotbar = TRUE;
        gIsMarkerActive = TRUE;
    }

    if (marker != NULL) {
        f32 distance = 300.0f;
        f32 yaw = m->faceAngle[1] * (2.0f * M_PI / 65536.0f);

        f32 targetX = m->pos[0] + sinf(yaw) * distance;
        f32 targetZ = m->pos[2] + cosf(yaw) * distance;
        f32 targetY = m->pos[1] + 10.0f;

        s32 gridX = to_grid_index(targetX);
        s32 gridY = to_grid_index(targetY);
        s32 gridZ = to_grid_index(targetZ);

        if (gPlayer1Controller->buttonDown & Z_TRIG) {
            gridY -= 1;
        }

        marker->oPosX = from_grid_index(gridX);
        marker->oPosY = from_grid_index(gridY);
        marker->oPosZ = from_grid_index(gridZ);
        marker->oFaceAngleYaw = gBlockRotationYaw;
        marker->oFaceAnglePitch = 0;
        marker->oFaceAngleRoll = 0;
    }
}

// place object to grid
void update_player_object_placement(struct MarioState *m) {
    if (gCurrLevelNum >= MAX_LEVELS) return; // ram safty :)
    if (!gPlacedBlocks[gCurrLevelNum]) return; // more safty
    if (!marker) return;

    s32 markerGridX = to_grid_index(marker->oPosX);
    s32 markerGridY = to_grid_index(marker->oPosY);
    s32 markerGridZ = to_grid_index(marker->oPosZ);

    if (gPlayer1Controller->buttonPressed & L_TRIG) {
        if (!find_placed_block(gCurrLevelNum, markerGridX, markerGridY, markerGridZ)) {
            place_block(gCurrLevelNum, markerGridX, markerGridY, markerGridZ, gSelectedBlockType + 1, (gBlockRotationYaw >> 14) & 0x03);

            s32 x = from_grid_index(markerGridX);
            s32 y = from_grid_index(markerGridY);
            s32 z = from_grid_index(markerGridZ);

            spawn_object_abs_with_rot(
                m->marioObj, 0,
                BlockModels[gSelectedBlockType],
                BlockBehaviors[gSelectedBlockType],
                x, y, z,
                0, gBlockRotationYaw, 0
            );
        }
    }

    if (gPlayer1Controller->buttonPressed & U_JPAD) {
        gBlockRotationYaw = (gBlockRotationYaw - 0x4000) & 0xC000;
    }    

    if (gPlayer1Controller->buttonPressed & R_JPAD) { // cycle hot bar right and left
        gSelectedBlockType = (gSelectedBlockType + 1) % BLOCK_TYPE_COUNT;
        gSelectedMarkerType = (gSelectedMarkerType + 1) % MARKER_TYPE_COUNT;
        if (marker) {
            obj_mark_for_deletion(marker);
            marker = spawn_object(gMarioObject, PreviewModels[gSelectedMarkerType], PreviewBehaviors[gSelectedMarkerType]);
        }
    }

    if (gPlayer1Controller->buttonPressed & L_JPAD) {
        gSelectedBlockType = (gSelectedBlockType - 1 + BLOCK_TYPE_COUNT) % BLOCK_TYPE_COUNT;
        gSelectedMarkerType = (gSelectedMarkerType - 1 + MARKER_TYPE_COUNT) % MARKER_TYPE_COUNT;
        if (marker) {
            obj_mark_for_deletion(marker);
            marker = spawn_object(gMarioObject, PreviewModels[gSelectedMarkerType], PreviewBehaviors[gSelectedMarkerType]);
        }
    }
}

// ready to delete placed object if marker is on the same grid position, better then using hitbox detection for performance overall
void system_obj_loop(void) {
    if (marker != NULL && (gPlayer1Controller->buttonPressed & D_JPAD)) {
        s32 gx = to_grid_index(marker->oPosX);
        s32 gy = to_grid_index(marker->oPosY);
        s32 gz = to_grid_index(marker->oPosZ);
        s32 ox = to_grid_index(o->oPosX);
        s32 oy = to_grid_index(o->oPosY);
        s32 oz = to_grid_index(o->oPosZ);

        if (gx == ox && gy == oy && gz == oz) {
            remove_block(gCurrLevelNum, ox, oy, oz);
            obj_mark_for_deletion(o);
        }
    }
}

// load grid into level
void load_objects_from_grid(void) {
    for (s32 i = 0; i < gPlacedBlockCounts[gCurrLevelNum]; i++) {
        struct PlacedBlockInstance *b = &gPlacedBlocks[gCurrLevelNum][i];
        s32 worldX = from_grid_index(b->x);
        s32 worldY = from_grid_index(b->y);
        s32 worldZ = from_grid_index(b->z);

        struct Object *obj;
        s32 exists = FALSE;
        for (obj = gObjectPool; obj < &gObjectPool[OBJECT_POOL_CAPACITY]; obj++) {
            if (obj->activeFlags != ACTIVE_FLAG_ACTIVE) continue;
            if (obj->behavior != segmented_to_virtual(BlockBehaviors[b->type - 1])) continue;
            if (to_grid_index(obj->oPosX) == b->x && to_grid_index(obj->oPosY) == b->y && to_grid_index(obj->oPosZ) == b->z) {
                exists = TRUE;
                break;
            }
        }

        if (!exists) {
            spawn_object_abs_with_rot(
                gMarioObject, 0,
                BlockModels[b->type - 1],
                BlockBehaviors[b->type - 1],
                worldX, worldY, worldZ,
                0, b->yaw << 14, 0
            );
        }
    }
}