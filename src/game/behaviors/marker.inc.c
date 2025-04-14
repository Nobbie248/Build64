struct ObjectHitbox sMarkerHitbox = { 
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

void bhv_marker_loop(void) {
    o->oIntangibleTimer = 0;
    obj_set_hitbox(o, &sMarkerHitbox);
}
