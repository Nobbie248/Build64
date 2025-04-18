#include <PR/ultratypes.h>

#include "include/sm64.h"
#include "src/game/area.h"
#include "src/audio/external.h"
#include "src/game/behavior_actions.h"
#include "include/behavior_data.h"
#include "src/game/camera.h"
#include "src/engine/graph_node.h"
#include "src/engine/math_util.h"
#include "src/engine/surface_collision.h"
#include "src/game/game_init.h"
#include "src/game/interaction.h"
#include "src/game/level_update.h"
#include "src/game/main.h"
#include "src/game/mario.h"
#include "src/game/mario_actions_airborne.h"
#include "src/game/mario_actions_automatic.h"
#include "src/game/mario_actions_cutscene.h"
#include "src/game/mario_actions_moving.h"
#include "src/game/mario_actions_object.h"
#include "src/game/mario_actions_stationary.h"
#include "src/game/mario_actions_submerged.h"
#include "src/game/mario_misc.h"
#include "src/game/mario_step.h"
#include "src/game/memory.h"
#include "include/object_fields.h"
#include "src/game/object_helpers.h"
#include "src/game/object_list_processor.h"
#include "src/game/print.h"
#include "src/game/save_file.h"
#include "src/game/rumble_init.h"
#include "src/game/hud.h"
#include <string.h>
#include "src/buffers/buffers.h"

static struct Object *marker = NULL;
s8 gIsHotbar = FALSE;
static s16 gBlockRotationYaw = 0;
static s8 gSelectedBlockType = 0;
static s8 gSelectedMarkerType = 0;
u8 gIsMarkerActive = FALSE;

#define GRID_SIZE 300
#define GRID_MAP_SIZE 64 // size of world grid
#define MARKER_TYPE_COUNT 10
#define BLOCK_TYPE_COUNT 10

struct PlacedBlock {
    u8 type;
    s16 yaw;
};

static const u32 PreviewModels[MARKER_TYPE_COUNT] = {
    MODEL_MARKER, MODEL_MARKER2, MODEL_MARKER, MODEL_MARKER, MODEL_MARKER,
    MODEL_MARKER, MODEL_MARKER, MODEL_MARKER, MODEL_MARKER, MODEL_MARKER
};

static const BehaviorScript *PreviewBehaviors[MARKER_TYPE_COUNT] = {
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

struct PlacedBlock gPlacedObjectGridMap[GRID_MAP_SIZE][GRID_MAP_SIZE][GRID_MAP_SIZE];


s32 to_grid_index(f32 pos) {
    return (s32)(roundf(pos / GRID_SIZE) + (GRID_MAP_SIZE / 2));
}

s32 from_grid_index(s32 i) {
    return i * GRID_SIZE - (GRID_MAP_SIZE / 2 * GRID_SIZE);
}

void system_obj_loop(void) {
    if (marker != NULL && (gPlayer1Controller->buttonPressed & D_JPAD)) {
        s32 markerGX = to_grid_index(marker->oPosX);
        s32 markerGY = to_grid_index(marker->oPosY);
        s32 markerGZ = to_grid_index(marker->oPosZ);

        s32 objGX = to_grid_index(o->oPosX);
        s32 objGY = to_grid_index(o->oPosY);
        s32 objGZ = to_grid_index(o->oPosZ);

        if (markerGX == objGX && markerGY == objGY && markerGZ == objGZ) {
            gPlacedObjectGridMap[objGX][objGY][objGZ].type = 0;
            gPlacedObjectGridMap[objGX][objGY][objGZ].yaw = 0;
            obj_mark_for_deletion(o);
        }
    }
}

void bhv_marker_loop(void) {
    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
}

void update_player_object_placement(struct MarioState *m) {
    s16 yaw = m->faceAngle[1];
    f32 distance = 160.0f;

    f32 offsetX = (f32)(sins(yaw)) * distance / 32768.0f;
    f32 offsetZ = (f32)(coss(yaw)) * distance / 32768.0f;

    f32 rawX = m->pos[0] + offsetX;
    f32 rawZ = m->pos[2] + offsetZ;
    f32 rawY = m->pos[1];

    s32 gridX = to_grid_index(rawX);
    s32 gridY = to_grid_index(rawY);
    s32 gridZ = to_grid_index(rawZ);

    if (gridX < 0 || gridX >= GRID_MAP_SIZE ||
        gridY < 0 || gridY >= GRID_MAP_SIZE ||
        gridZ < 0 || gridZ >= GRID_MAP_SIZE)
        return;

    s32 snappedX = gridX * GRID_SIZE - (GRID_MAP_SIZE / 2 * GRID_SIZE);
    s32 snappedY = gridY * GRID_SIZE - (GRID_MAP_SIZE / 2 * GRID_SIZE);
    s32 snappedZ = gridZ * GRID_SIZE - (GRID_MAP_SIZE / 2 * GRID_SIZE);

    if ((gPlayer1Controller->buttonPressed & L_TRIG) && marker != NULL) {
        s32 markerGridX = to_grid_index(marker->oPosX);
        s32 markerGridY = to_grid_index(marker->oPosY);
        s32 markerGridZ = to_grid_index(marker->oPosZ);

        if (gPlacedObjectGridMap[markerGridX][markerGridY][markerGridZ].type == 0) {
            gPlacedObjectGridMap[markerGridX][markerGridY][markerGridZ].type = gSelectedBlockType + 1;
            gPlacedObjectGridMap[markerGridX][markerGridY][markerGridZ].yaw = gBlockRotationYaw;


            s32 snappedX = from_grid_index(markerGridX);
            s32 snappedY = from_grid_index(markerGridY);
            s32 snappedZ = from_grid_index(markerGridZ);

            spawn_object_abs_with_rot(
                m->marioObj, 0,
                BlockModels[gSelectedBlockType],
                BlockBehaviors[gSelectedBlockType],
                snappedX, snappedY, snappedZ,
                0, gBlockRotationYaw, 0
            );
        }
    }
    if (gPlayer1Controller->buttonPressed & U_JPAD) {
        gBlockRotationYaw -= 0x4000;
    }

    if (gPlayer1Controller->buttonPressed & R_JPAD) {
        gSelectedBlockType = (gSelectedBlockType + 1) % BLOCK_TYPE_COUNT;
        gSelectedMarkerType = (gSelectedMarkerType + 1) % MARKER_TYPE_COUNT;
        if (marker != NULL) {
            obj_mark_for_deletion(marker);
            marker = spawn_object(gMarioObject, PreviewModels[gSelectedMarkerType], PreviewBehaviors[gSelectedMarkerType]);
        }
    }
    if (gPlayer1Controller->buttonPressed & L_JPAD) {
        gSelectedBlockType = (gSelectedBlockType - 1 + BLOCK_TYPE_COUNT) % BLOCK_TYPE_COUNT;
        gSelectedMarkerType = (gSelectedMarkerType - 1 + MARKER_TYPE_COUNT) % MARKER_TYPE_COUNT;
        if (marker != NULL) {
            obj_mark_for_deletion(marker);
            marker = spawn_object(gMarioObject, PreviewModels[gSelectedMarkerType], PreviewBehaviors[gSelectedMarkerType]);
        }
    }    
}

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
        marker->oFaceAngleYaw = 0;
        marker->oFaceAngleYaw = gBlockRotationYaw;
        marker->oFaceAnglePitch = 0;
        marker->oFaceAngleRoll = 0;
    }
}

void load_objects_from_grid(void) {
    for (s32 x = 0; x < GRID_MAP_SIZE; x++) {
        for (s32 y = 0; y < GRID_MAP_SIZE; y++) {
            for (s32 z = 0; z < GRID_MAP_SIZE; z++) {
                u8 blockIndex = gPlacedObjectGridMap[x][y][z].type;
                s16 blockYaw = gPlacedObjectGridMap[x][y][z].yaw;
                if (blockIndex) {
                    s32 worldX = from_grid_index(x);
                    s32 worldY = from_grid_index(y);
                    s32 worldZ = from_grid_index(z);

                    struct Object *obj;
                    s32 exists = FALSE;
                    for (obj = gObjectPool; obj < &gObjectPool[OBJECT_POOL_CAPACITY]; obj++) {
                        if (obj->activeFlags != ACTIVE_FLAG_ACTIVE) continue;
                        if (obj->behavior != segmented_to_virtual(BlockBehaviors[blockIndex - 1])) continue;
                        if (to_grid_index(obj->oPosX) == x &&
                            to_grid_index(obj->oPosY) == y &&
                            to_grid_index(obj->oPosZ) == z) {
                            exists = TRUE;
                            break;
                        }
                    }

                    if (!exists) {
                        spawn_object_abs_with_rot(
                            gMarioObject, 0,
                            BlockModels[blockIndex - 1],
                            BlockBehaviors[blockIndex - 1],
                            worldX, worldY, worldZ,
                            0, blockYaw, 0
                        );                        
                    }
                }
            }
        }
    }
}