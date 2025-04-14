#include "game/level_update.h"
#include "game/behavior_actions.h"
#include "include/behavior_data.h"
#include "src/game/ingame_menu.h"
#include "src/game/interaction.h"
#include "game/save_file.h"
#include "game/hud.h"
#include "src/game/print.h"
#include "src/game/spawn_object.h"

struct ObjectHitbox sBlockHitbox = { 
    /* interactType: */ INTERACT_COIN,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 60,
    /* height: */ 100,
    /* hurtboxRadius: */ 0,
    /* hurtboxHeight: */ 0,
};

struct ObjectHitbox sMarkerHitbox = { 
    /* interactType: */ INTERACT_DAMAGE,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 60,
    /* height: */ 100,
    /* hurtboxRadius: */ 0,
    /* hurtboxHeight: */ 0,
};
extern struct Object *marker;
void system_obj_loop(void) {
    obj_set_hitbox(o, &sBlockHitbox);
    struct Object* marker = cur_obj_nearest_object_with_behavior(bhvMarker);

    if (obj_check_if_collided_with_object(o, marker) &&
        (gPlayer1Controller->buttonPressed & D_JPAD)) {
        
        obj_mark_for_deletion(o);
    }
}

void bhv_marker_loop(void) {
    obj_set_hitbox(o, &sMarkerHitbox);
}
