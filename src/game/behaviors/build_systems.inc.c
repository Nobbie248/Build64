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
#include "src/game/build_systems.h"
#include "src/game/save_file.h"
#include "src/game/ingame_menu.h"
#include "src/game/hud.h"

struct PlacedBlockInstance gPlacedBlocks[MAX_LEVELS][MAX_PLACED_BLOCKS_PER_LEVEL];
u16 gPlacedBlockCounts[MAX_LEVELS];

extern u32 gFileSelectTimer __attribute__((section(".bss")));
struct Object *marker = NULL;
s16 gBlockRotationYaw = 0;
u8 gSelectedBlockType = 0;
u8 gSelectedMarkerType = 0;
u8 gIsMarkerActive = FALSE;
u8 gIsBlockType[BLOCK_TYPE_COUNT] = { 0 };
u8 gIsHotbar;
s32 blockLimitTextTimer = 0;

static const u32 PreviewModels[MARKER_TYPE_COUNT] = {
    MODEL_MARKER, MODEL_MARKER2, MODEL_MARKER3, MODEL_MARKER4, MODEL_MARKER5,
    MODEL_MARKER6, MODEL_MARKER7, MODEL_MARKER8, MODEL_MARKER9, MODEL_MARKER10
};

static const BehaviorScript *PreviewBehaviors[MARKER_TYPE_COUNT] = { // dont need to change in most cases
    bhvMarker, bhvMarker, bhvMarker, bhvMarker, bhvMarker,
    bhvMarker, bhvMarker, bhvMarker, bhvMarker, bhvMarker
};

static const u32 BlockModels[BLOCK_TYPE_COUNT] = {
    MODEL_BLOCK, MODEL_BLOCK2, MODEL_BLOCK3, MODEL_BLOCK4, MODEL_BLOCK5,
    MODEL_BLOCK6, MODEL_BLOCK7, MODEL_BLOCK8, MODEL_BLOCK9, MODEL_BLOCK10
};

static const BehaviorScript *BlockBehaviors[BLOCK_TYPE_COUNT] = {
    bhvBlock, bhvBlock2, bhvBlock3, bhvBlock4, bhvBlock5,
    bhvBlock6, bhvBlock7, bhvBlock8, bhvBlock9, bhvBlock10
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

// just flag for ui
void update_selected_block_flags(void) {
    for (int i = 0; i < BLOCK_TYPE_COUNT; i++) {
        gIsBlockType[i] = FALSE;
    }
    gIsBlockType[gSelectedBlockType] = TRUE;
}

void bhv_marker_loop(void) { // not in use yet
    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
}

// this is the preview for placing
void update_marker(struct MarioState *m) {
    if (((m->action == ACT_DISAPPEARED) ||
         (m->action == ACT_PUSHING_DOOR) ||
         (m->action == ACT_PULLING_DOOR) ||
         (m->action == ACT_STAR_DANCE_EXIT) ||
         (m->action == ACT_DEATH_EXIT) ||
         (m->action == ACT_EXIT_AIRBORNE) ||
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
        update_selected_block_flags();
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

    if (gCurrLevelNum >= MAX_LEVELS) return; // safty :)
    if (!marker) return;

    s32 markerGridX = to_grid_index(marker->oPosX);
    s32 markerGridY = to_grid_index(marker->oPosY);
    s32 markerGridZ = to_grid_index(marker->oPosZ);

    if (gPlayer1Controller->buttonPressed & L_TRIG) {
        if (gPlacedBlockCounts[gCurrLevelNum] >= MAX_PLACED_BLOCKS_PER_LEVEL) {
            blockLimitTextTimer = 40;
            return;
        }
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

    if (gPlayer1Controller->buttonPressed & R_JPAD) {
        gSelectedBlockType = (gSelectedBlockType + 1) % BLOCK_TYPE_COUNT;
        gSelectedMarkerType = (gSelectedMarkerType + 1) % MARKER_TYPE_COUNT;
        update_selected_block_flags();
        if (marker) {
            obj_mark_for_deletion(marker);
            marker = spawn_object(gMarioObject, PreviewModels[gSelectedMarkerType], PreviewBehaviors[gSelectedMarkerType]);
        }
    }

    if (gPlayer1Controller->buttonPressed & L_JPAD) {
        gSelectedBlockType = (gSelectedBlockType - 1 + BLOCK_TYPE_COUNT) % BLOCK_TYPE_COUNT;
        gSelectedMarkerType = (gSelectedMarkerType - 1 + MARKER_TYPE_COUNT) % MARKER_TYPE_COUNT;
        update_selected_block_flags();
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

void system_obj_loop_door(void) {
    if (o->oAction == 0) {
        // Spawn door in front of this object based on its yaw
        s16 yaw = o->oFaceAngleYaw;
        f32 offset = 115.0f;
        f32 dx = offset * sins(yaw);
        f32 dz = offset * coss(yaw);

        spawn_object_abs_with_rot(
            o, 0,
            MODEL_UNKNOWN_DOOR_21,
            bhvDoor,
            o->oPosX + dx, o->oPosY, o->oPosZ + dz,
            0, yaw, 0
        );
        o->oAction = 1;
    }

    if (marker != NULL && (gPlayer1Controller->buttonPressed & D_JPAD)) {
        s32 gx = to_grid_index(marker->oPosX);
        s32 gy = to_grid_index(marker->oPosY);
        s32 gz = to_grid_index(marker->oPosZ);
        s32 ox = to_grid_index(o->oPosX);
        s32 oy = to_grid_index(o->oPosY);
        s32 oz = to_grid_index(o->oPosZ);

        if (gx == ox && gy == oy && gz == oz) {
            struct Object *door = cur_obj_nearest_object_with_behavior(bhvDoor);
            if (door != NULL) {
                // Compare door position with calculated door offset
                s16 yaw = o->oFaceAngleYaw;
                f32 offset = 115.0f;
                f32 dx = offset * sins(yaw);
                f32 dz = offset * coss(yaw);
                s32 tx = (s32)(o->oPosX + dx);
                s32 tz = (s32)(o->oPosZ + dz);

                if ((s32)door->oPosX == tx &&
                    (s32)door->oPosY == o->oPosY &&
                    (s32)door->oPosZ == tz) {
                    obj_mark_for_deletion(door);
                }
            }

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

// used for load limits and testing
void spawn_random_blocks(void) {
    static s16 lastLevel = -1;
    static u8 isSpawning = FALSE;
    static s32 totalSpawned = 0;
    static u16 entropy_seed = 0;
    static s32 attempts = 0;

    if (gCurrLevelNum != lastLevel) {
        lastLevel = gCurrLevelNum;
        isSpawning = TRUE;
        totalSpawned = 0;
        attempts = 0;
        entropy_seed = (u16)((gFileSelectTimer ^ 0xA5A5) ^ get_entropy_seed_from_save());
    }

    if (!gMarioState || !gMarioState->marioObj || gCurrLevelNum >= MAX_LEVELS) return;

    if (!isSpawning) return;

    s32 blocksThisFrame = 0;
    while (blocksThisFrame < 32 && totalSpawned < 256 && gPlacedBlockCounts[gCurrLevelNum] < MAX_PLACED_BLOCKS_PER_LEVEL && attempts < 1024) {
        attempts++;

        u8 x = ((random_u16() ^ entropy_seed) + attempts) % GRID_MAP_SIZE;
        u8 y = ((random_u16() ^ (entropy_seed >> 3)) + attempts) % GRID_MAP_SIZE;
        u8 z = ((random_u16() ^ (entropy_seed >> 5)) + attempts) % GRID_MAP_SIZE;

        if (find_placed_block(gCurrLevelNum, x, y, z)) continue;

        u8 type = (random_u16() ^ (entropy_seed >> 2)) % BLOCK_TYPE_COUNT;
        u8 yaw = (random_u16() + entropy_seed) % 4;

        place_block(gCurrLevelNum, x, y, z, type + 1, yaw);

        s32 wx = from_grid_index(x);
        s32 wy = from_grid_index(y);
        s32 wz = from_grid_index(z);

        spawn_object_abs_with_rot(
            gMarioObject, 0,
            BlockModels[type],
            BlockBehaviors[type],
            wx, wy, wz,
            0, yaw << 14, 0
        );

        blocksThisFrame++;
        totalSpawned++;
    }

    if (totalSpawned >= 256 || gPlacedBlockCounts[gCurrLevelNum] >= MAX_PLACED_BLOCKS_PER_LEVEL) {
        isSpawning = FALSE;
    }
}
