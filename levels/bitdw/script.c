#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/bitdw/header.h"


static const LevelScript script_bitdw_macro_objects[] = {
    // Macro objects
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,   /*pos*/ -6420, -2900,  3880, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_METAL_CAP << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/ -1660, -3000,  3900, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_RING) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/ -2400,  -800,  1900, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_NONE                             ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_AMP,               /*pos*/ -5300,    20,  1000, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvCirclingAmp),
    OBJECT(/*model*/ MODEL_AMP,               /*pos*/ -7140,   500,   380, /*angle*/ 0,   0, 0, /*behParam*/ (1 << 16), /*beh*/ bhvCirclingAmp),
    OBJECT(/*model*/ MODEL_AMP,               /*pos*/ -7120,  1050, -2080, /*angle*/ 0,   0, 0, /*behParam*/ (1 << 16), /*beh*/ bhvCirclingAmp),
    OBJECT(/*model*/ MODEL_AMP,               /*pos*/ -6480,   240,  1000, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvCirclingAmp),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/ -2060,  1200,  -940, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_RING) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  -170,  1070,   300, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  -170,  1070,   700, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  1450,  1400,   300, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  1450,  1400,   700, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/  1660, -1980,  3660, /*angle*/ 0,  90, 0, /*behParam*/ ((COIN_FORMATION_FLAG_NONE                             ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/  3180,  1020,   240, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/  2860,  1020,   580, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  4640,  2360,     0, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  4900,  2600,     0, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  5180,  2820,     0, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  2760,  1940,   500, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  2760,  1940,   180, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -2460,   812,   800, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvOneCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -3080,   813,   840, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvOneCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -3660,   873,   620, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvOneCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -4060,  1011,   240, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvOneCoin),
    OBJECT(/*model*/ MODEL_AMP,               /*pos*/ -4620,  1220,  -300, /*angle*/ 0,   0, 0, /*behParam*/ (2 << 16), /*beh*/ bhvCirclingAmp),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/ -4620,  1220,  -300, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_RING                             ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,   /*pos*/ -4860,  1380,  -300, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_1UP_WALKING << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  -150, -1200,  3660, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,   /*pos*/ -5120,  1460, -2140, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_COINS_3     << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  4380,  2120,     0, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  5420,  3000,     0, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -2357,  1200, -2454, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -2357,  1300, -2454, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/ -2560, -1433,  3280, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/ -2060, -1433,  3540, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/ -2720, -1433,  3860, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/ -1680,  1024,   580, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -3100, -2900,  4520, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -4740,  1050, -2130, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -3120,  1160, -2570, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -4613,  1220,  -427, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -1000,  1933,   466, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_1UP,               /*pos*/    33,  1900,   333, /*angle*/ 0,   0, 0, /*behParam*/ (MUSHROOM_BP_REQUIRES_BOWSER_1 << 16), /*beh*/ bhv1Up),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -6475,   125,   890, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -7810, -3100,  4900, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/  1500,  1066,  -166, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_WOODEN_SIGNPOST,   /*pos*/  5940,  2765,  -280, /*angle*/ 0,   0, 0, /*behParam*/ (DIALOG_066 << 16), /*beh*/ bhvMessagePanel),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -2357,  1400, -2454, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  -170,  1070,   500, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  1450,  1400,   500, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_1UP,               /*pos*/   610,  1045,  -167, /*angle*/ 0,   0, 0, /*behParam*/ (MUSHROOM_BP_REQUIRES_NONE     << 16), /*beh*/ bhv1Up),
    OBJECT(/*model*/ MODEL_1UP,               /*pos*/  -485,  1054,  -167, /*angle*/ 0,   0, 0, /*behParam*/ (MUSHROOM_BP_REQUIRES_BOWSER_1 << 16), /*beh*/ bhv1Up),
    OBJECT(/*model*/ MODEL_1UP,               /*pos*/  1100,  2080,   363, /*angle*/ 0,   0, 0, /*behParam*/ (MUSHROOM_BP_REQUIRES_BOWSER_2 << 16), /*beh*/ bhv1Up),
    OBJECT(/*model*/ MODEL_PURPLE_SWITCH,     /*pos*/ -3100, -2946,  3530, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFloorSwitchHiddenObjects),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,     /*pos*/ -7810, -3360,  4500, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,     /*pos*/ -7810, -3360,  4700, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,     /*pos*/ -7810, -3360,  4900, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,     /*pos*/ -3100, -3145,  4518, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,   /*pos*/ -2420, -1140,  3700, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_1UP_RUNNING_AWAY << 16), /*beh*/ bhvExclamationBox),
    // Special objects
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ -6368, -3972,  3883, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_04, /*pos*/ -3245, -3358,  3893, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_05, /*pos*/ -2405, -1228,  1740, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_06, /*pos*/ -5861,  -434,   306, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_07, /*pos*/ -5062,   922, -1895, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_08, /*pos*/ -7116,   717,  -819, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_09, /*pos*/ -4601,     0,  -312, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0A, /*pos*/   797, -3282,  3868, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0B, /*pos*/ -2047, -1868,  3685, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0C, /*pos*/  -966,   922,    44, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0D, /*pos*/  2207,   922,    44, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0E, /*pos*/ -7108,   209,   356, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0E, /*pos*/ -7103,   844, -2088, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0E, /*pos*/ -6466,     9,   986, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0E, /*pos*/ -4013,  -670,   990, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0E, /*pos*/ -5251,  -276,   967, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0E, /*pos*/ -7665,   502,  -251, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0F, /*pos*/  5382,  1536,    -6, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_10, /*pos*/ -1658, -3281,  3893, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_10, /*pos*/ -2656,   889, -2156, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_10, /*pos*/ -2052,   889,  -928, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_11, /*pos*/ -3168,   710,   607, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    RETURN(),
};

static const LevelScript script_bitdw_objects_1[] = {
    OBJECT(/*model*/ MODEL_BITDW_SQUARE_PLATFORM,   /*pos*/ -1966, -3154,  3586, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00000000, /*beh*/ bhvSquarishPathMoving),
    OBJECT(/*model*/ MODEL_BITDW_SQUARE_PLATFORM,   /*pos*/ -1352, -3154,  4200, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00020000, /*beh*/ bhvSquarishPathMoving),
    OBJECT(/*model*/ MODEL_BITDW_SQUARE_PLATFORM,   /*pos*/ -2963,  1017, -2464, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00000000, /*beh*/ bhvSquarishPathMoving),
    OBJECT(/*model*/ MODEL_BITDW_SQUARE_PLATFORM,   /*pos*/ -2349,  1017, -1849, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00020000, /*beh*/ bhvSquarishPathMoving),
    OBJECT(/*model*/ MODEL_BITDW_SQUARE_PLATFORM,   /*pos*/ -2349,  1017, -1235, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00000000, /*beh*/ bhvSquarishPathMoving),
    OBJECT(/*model*/ MODEL_BITDW_SQUARE_PLATFORM,   /*pos*/ -1735,  1017,  -621, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00020000, /*beh*/ bhvSquarishPathMoving),
    OBJECT(/*model*/ MODEL_BITDW_SEESAW_PLATFORM,   /*pos*/  1491,  1273,   512, /*angle*/ 0, 90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSeesawPlatform),
    OBJECT(/*model*/ MODEL_BITDW_SEESAW_PLATFORM,   /*pos*/  -147,   894,   512, /*angle*/ 0, 90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSeesawPlatform),
    OBJECT(/*model*/ MODEL_BITDW_SLIDING_PLATFORM,  /*pos*/ -5728,   819, -2151, /*angle*/ 0, 0, 0,  /*behParam*/ 0x074E0000, /*beh*/ bhvSlidingPlatform2),
    OBJECT(/*model*/ MODEL_BITDW_FERRIS_WHEEL_AXLE, /*pos*/  -204, -1924,  3381, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00010000, /*beh*/ bhvFerrisWheelAxle),
    OBJECT(/*model*/ MODEL_BITDW_STAIRCASE,         /*pos*/  5279,  1740,    -6, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00010000, /*beh*/ bhvAnimatesOnFloorSwitchPress),
    OBJECT(/*model*/ MODEL_PURPLE_SWITCH,           /*pos*/  3922,  1740,    -7, /*angle*/ 0, 0, 0,  /*behParam*/ 0x00000000, /*beh*/ bhvFloorSwitchAnimatesObject),
    RETURN(),
};

static const LevelScript script_bitdw_objects_2[] = {
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ -3092, -2795, 2842, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFlamethrower),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/  2463, -2386, 2844, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFlamethrower),
    RETURN(),
};

static const LevelScript script_bitdw_objects_3[] = {
    OBJECT(/*model*/ MODEL_NONE, /*pos*/  7180,  3000,    0, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvBowserCourseRedCoinStar),
    RETURN(),
};

const LevelScript level_bitdw_entry[] = {
    INIT_LEVEL(),
#include "levels/bitdw/areas/script_vanilla_load.inc.c"
    ALLOC_LEVEL_POOL(),
    MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
#include "levels/bitdw/areas/script_vanilla.inc.c" 

    AREA(/*index*/ 1, geo_bitdw_000618),
        OBJECT(/*model*/ MODEL_NONE,            /*pos*/ -7443, -2153, 3886, /*angle*/ 0, 90, 0, /*behParam*/ 0x000A0000, /*beh*/ bhvAirborneWarp),
        OBJECT(/*model*/ MODEL_BITDW_WARP_PIPE, /*pos*/  6816,  2860,   -7, /*angle*/ 0, 0, 0,  /*behParam*/ 0x000B0000, /*beh*/ bhvWarpPipe),
        OBJECT(/*model*/ MODEL_NONE,            /*pos*/  5910,  3500,   -7, /*angle*/ 0, 90, 0, /*behParam*/ 0x000C0000, /*beh*/ bhvDeathWarp),
        WARP_NODE(/*id*/ 0x0A, /*destLevel*/ LEVEL_BITDW, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x0B, /*destLevel*/ LEVEL_BOWSER_1, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x0C, /*destLevel*/ LEVEL_BITDW, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF1, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x01, /*destNode*/ 0x25, /*flags*/ WARP_NO_CHECKPOINT),
        JUMP_LINK(script_bitdw_objects_1),
        JUMP_LINK(script_bitdw_objects_2),
        JUMP_LINK(script_bitdw_objects_3),
        TERRAIN(/*terrainData*/ bitdw_seg7_collision_level),
        JUMP_LINK(script_bitdw_macro_objects),
        SHOW_DIALOG(/*index*/ 0x00, DIALOG_090),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0000, /*seq*/ SEQ_LEVEL_KOOPA_ROAD),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_STONE),
    END_AREA(),

    FREE_LEVEL_POOL(),
    MARIO_POS(/*area*/ 1, /*yaw*/ 90, /*pos*/ -7443, -3153, 3886),
    CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
    CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(/*frames*/ 1),
    EXIT(),
};
