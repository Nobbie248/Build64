#include "game/behavior_actions.h"
#include "include/behavior_data.h"
#include "src/game/interaction.h"

struct ObjectHitbox sBlockHitbox = { 
    INTERACT_COIN, 0, 0, 1, 0, 60, 100, 0, 0,
};

struct ObjectHitbox sMarkerHitbox = { 
    INTERACT_DAMAGE, 0, 0, 1, 0, 60, 100, 60, 100,
};

void system_obj_loop(void) {
    o->oIntangibleTimer = 0;
    obj_set_hitbox(o, &sBlockHitbox);

    struct Object *marker = cur_obj_nearest_object_with_behavior(bhvMarker);

    if (obj_check_if_collided_with_object(o, marker) &&
        (gPlayer1Controller->buttonPressed & D_JPAD)) {
        
        obj_mark_for_deletion(o);
    }
}

void bhv_marker_loop(void) {
    o->oIntangibleTimer = 0;
    obj_set_hitbox(o, &sMarkerHitbox);
}
