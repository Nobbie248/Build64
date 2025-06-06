#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/rr/header.h"


static const LevelScript script_rr_macro_objects[] = {
    // Macro objects
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -5850, -1000,   -50, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -2950,  -190,   -50, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -5850,  1150,    50, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -5050,   800,   -50, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -4550,   650,   -50, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -5300,   200,   -50, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -3550,  1000,   -50, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -5800,  -400,   -50, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_BOBOMB_BUDDY,      /*pos*/ -4200,  1648,     0, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvBobombBuddyOpensCannon),
    OBJECT(/*model*/ MODEL_DL_CANNON_LID,     /*pos*/  5545,  3333, -2345, /*angle*/ 0,   0, 0, /*behParam*/ (0xC0 << 16), /*beh*/ bhvCannonClosed),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,   /*pos*/ -6750,  2600,   -50, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_1UP_WALKING << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_AMP,               /*pos*/  6500,  -900,   900, /*angle*/ 0,   0, 0, /*behParam*/ (1 << 16), /*beh*/ bhvCirclingAmp),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/  6500, -1000,   900, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_RING                                 ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_ENEMY_LAKITU,      /*pos*/   615,  -584,     0, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvEnemyLakitu),
    OBJECT(/*model*/ MODEL_HEART,             /*pos*/  -550, -1050,   -50, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRecoveryHeart),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/   600, -1040,  1200, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_RING    ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/   600, -1040, -1300, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_RING    ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_HEART,             /*pos*/ -7071, -1705,   -31, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRecoveryHeart),
    OBJECT(/*model*/ MODEL_BLACK_BOBOMB,      /*pos*/ -3295, -1782,   524, /*angle*/ 0,   0, 0, /*behParam*/ (BOBOMB_BP_STYPE_GENERIC << 16), /*beh*/ bhvBobomb),
    OBJECT(/*model*/ MODEL_BLACK_BOBOMB,      /*pos*/ -5872, -1782,   572, /*angle*/ 0,   0, 0, /*behParam*/ (BOBOMB_BP_STYPE_GENERIC << 16), /*beh*/ bhvBobomb),
    OBJECT(/*model*/ MODEL_FLYGUY,            /*pos*/   971, -3059,  4912, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000,  /*beh*/ bhvFlyGuy),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/   615, -3275,  5660, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_NONE                                 ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/ -2203, -3500,  6572, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_VERTICAL) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/ -1866, -1116,  4933, /*angle*/ 0,  90, 0, /*behParam*/ ((COIN_FORMATION_FLAG_NONE                                 ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/   799, -1446,  6622, /*angle*/ 0,  90, 0, /*behParam*/ ((COIN_FORMATION_FLAG_NONE                                 ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_1UP,               /*pos*/  6666, -1000,  6533, /*angle*/ 0,   0, 0, /*behParam*/ (MUSHROOM_BP_REQUIRES_NONE << 16), /*beh*/ bhv1Up),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  3960,   -41, -3640, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvOneCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  5680,   600, -2400, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,     /*pos*/  2560,  1000, -1600, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/ -1440, -1960,  6640, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_1UP,               /*pos*/  5040,  2100,   280, /*angle*/ 0,   0, 0, /*behParam*/ (MUSHROOM_BP_REQUIRES_NONE << 16), /*beh*/ bhv1Up),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/  3542,  4892, -2371, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHidden1upInPoleSpawner),
    OBJECT(/*model*/ MODEL_ENEMY_LAKITU,      /*pos*/  4714,  3507, -2371, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvEnemyLakitu),
    OBJECT(/*model*/ MODEL_BLACK_BOBOMB,      /*pos*/  3485,  2889, -2057, /*angle*/ 0,   0, 0, /*behParam*/ (BOBOMB_BP_STYPE_GENERIC << 16), /*beh*/ bhvBobomb),
    OBJECT(/*model*/ MODEL_BLACK_BOBOMB,      /*pos*/  2628,  2893, -2371, /*angle*/ 0,   0, 0, /*behParam*/ (BOBOMB_BP_STYPE_GENERIC << 16), /*beh*/ bhvBobomb),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/  3542,  2923, -2371, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_RING                                 ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/ -3342,  3222, -5071, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_NONE                                 ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/ -7771,  4352, -3871, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_NONE                                 ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_AMP,               /*pos*/ -6571,  4000, -2328, /*angle*/ 0,   0, 0, /*behParam*/ (1  << 16), /*beh*/ bhvCirclingAmp),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/ -6057,  4676, -5242, /*angle*/ 0,  90, 0, /*behParam*/ ((COIN_FORMATION_FLAG_FLYING                               ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_CHUCKYA,           /*pos*/  5114,  3828,  4028, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvChuckya),
    OBJECT(/*model*/ MODEL_1UP,               /*pos*/  -165,  3543, -2352, /*angle*/ 0,   0, 0, /*behParam*/ (MUSHROOM_BP_REQUIRES_NONE << 16), /*beh*/ bhv1Up),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/   250,  1400,  -180, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_VERTICAL) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_1UP,               /*pos*/  -735,  2860,  -150, /*angle*/ 0,   0, 0, /*behParam*/ (MUSHROOM_BP_REQUIRES_NONE << 16), /*beh*/ bhv1Up),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/ -2175,  2365,   -60, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHidden1upInPoleSpawner),
    OBJECT(/*model*/ MODEL_BLUE_COIN_SWITCH,  /*pos*/ -6930, -1791,   521, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvBlueCoinSwitch),
    OBJECT(/*model*/ MODEL_BLUE_COIN,         /*pos*/ -6500,  1700,     0, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_BLUE_COIN,         /*pos*/ -6200,  1700,     0, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_BLUE_COIN,         /*pos*/ -5900,  1700,     0, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_BLUE_COIN,         /*pos*/ -5600,  1700,     0, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_BLUE_COIN,         /*pos*/ -6750, -1495,     0, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_BLUE_COIN,         /*pos*/ -5300,  1700,     0, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_BOWLING_BALL,      /*pos*/ -3233,  1291,   -52, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFireSpitter),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -7338, -2260,  6700, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -7338, -2260,  6350, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -6715, -1900,  6700, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -6715, -1900,  6350, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,   /*pos*/ -4844, -4240,  6622, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_1UP_RUNNING_AWAY << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,   /*pos*/ -3428,  6770, -5128, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_1UP_RUNNING_AWAY << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,   /*pos*/  5000,  4100,  4440, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_STAR_6           << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_BOWLING_BALL,      /*pos*/ -6000,  -440,   -40, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFireSpitter),
    // Special objects
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/  1902, -1833,  1063, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_04, /*pos*/  3803, -1833,  2036, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_05, /*pos*/ -4888, -2550,  5847, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_06, /*pos*/  5324, -2038,  6155, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_07, /*pos*/  -409, -3164,  5207, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_08, /*pos*/ -3193, -4726,  6670, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_08, /*pos*/ -4680, -1910,   296, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_09, /*pos*/  6506, -1295,   762, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0A, /*pos*/ -4629,   137,  -113, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0B, /*pos*/  2639,  2724,  -622, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0C, /*pos*/  3577,  2486, -2346, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0D, /*pos*/   614, -1116,  3671, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0D, /*pos*/  3554,  4276, -2346, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0E, /*pos*/  5280,  4937,   603, /*angle*/ 0, 180, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_0F, /*pos*/ -4197,  4608, -5119, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_10, /*pos*/  2628,  -143, -1611, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_11, /*pos*/  5094,  3440,  4029, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_12, /*pos*/ -3708,  2006,   270, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_13, /*pos*/  5994,  -988,  1341, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_14, /*pos*/  3917,   624, -1133, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_15, /*pos*/ -3981,  3328, -2736, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_16, /*pos*/ -6053,  4096, -3197, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    RETURN(),
};

static const LevelScript script_rr_objects_1[] = {
    OBJECT(/*model*/ MODEL_RR_SLIDING_PLATFORM,         /*pos*/ -3400, -2038,  6564, /*angle*/  0,   0,   0, /*behParam*/ 0x04560000, /*beh*/ bhvSlidingPlatform2),
    OBJECT(/*model*/ MODEL_RR_SLIDING_PLATFORM,         /*pos*/ -2684, -1423,   -36, /*angle*/  0,   0,   0, /*behParam*/ 0x04590000, /*beh*/ bhvSlidingPlatform2),
    OBJECT(/*model*/ MODEL_RR_FLYING_CARPET,            /*pos*/  4571, -1782,  2036, /*angle*/  0, 180,   0, /*behParam*/ 0x00000000, /*beh*/ bhvPlatformOnTrack),
    OBJECT(/*model*/ MODEL_RR_FLYING_CARPET,            /*pos*/   580,  -963, -3659, /*angle*/  0, 180,   0, /*behParam*/ 0x00010000, /*beh*/ bhvPlatformOnTrack),
    OBJECT(/*model*/ MODEL_RR_FLYING_CARPET,            /*pos*/  1567,   880,  -184, /*angle*/  0, 180,   0, /*behParam*/ 0x00070000, /*beh*/ bhvPlatformOnTrack),
    OBJECT(/*model*/ MODEL_RR_FLYING_CARPET,            /*pos*/   646,   880,  -184, /*angle*/  0,   0,   0, /*behParam*/ 0x00080000, /*beh*/ bhvPlatformOnTrack),
    OBJECT(/*model*/ MODEL_RR_OCTAGONAL_PLATFORM,       /*pos*/   644, -1321, -1301, /*angle*/  0, 180,   0, /*behParam*/ 0x03010000, /*beh*/ bhvOctagonalPlatformRotating),
    OBJECT(/*model*/ MODEL_RR_OCTAGONAL_PLATFORM,       /*pos*/  1797, -1321,   -56, /*angle*/  0,   0,   0, /*behParam*/ 0x00010000, /*beh*/ bhvOctagonalPlatformRotating),
    OBJECT(/*model*/ MODEL_RR_OCTAGONAL_PLATFORM,       /*pos*/   663, -1321,  1179, /*angle*/  0, 180,   0, /*behParam*/ 0x03010000, /*beh*/ bhvOctagonalPlatformRotating),
    OBJECT(/*model*/ MODEL_RR_OCTAGONAL_PLATFORM,       /*pos*/  -502, -1321,   -51, /*angle*/  0,   0,   0, /*behParam*/ 0x00010000, /*beh*/ bhvOctagonalPlatformRotating),
    OBJECT(/*model*/ MODEL_RR_ROTATING_BRIDGE_PLATFORM, /*pos*/  5043,  1342,   300, /*angle*/  0,   0,   0, /*behParam*/ 0x00010000, /*beh*/ bhvRrRotatingBridgePlatform),
    OBJECT(/*model*/ MODEL_RR_CRUISER_WING,             /*pos*/  3473,  2422, -1821, /*angle*/  0,   0,   0, /*behParam*/ 0x00000000, /*beh*/ bhvRrCruiserWing),
    OBJECT(/*model*/ MODEL_RR_CRUISER_WING,             /*pos*/  4084,  2431, -2883, /*angle*/ 45, 180, 180, /*behParam*/ 0x00010000, /*beh*/ bhvRrCruiserWing),
    OBJECT(/*model*/ MODEL_RR_CRUISER_WING,             /*pos*/  3470,  2420, -2869, /*angle*/ 45, 180, 180, /*behParam*/ 0x00010000, /*beh*/ bhvRrCruiserWing),
    OBJECT(/*model*/ MODEL_RR_CRUISER_WING,             /*pos*/  2856,  2410, -2855, /*angle*/ 45, 180, 180, /*behParam*/ 0x00010000, /*beh*/ bhvRrCruiserWing),
    OBJECT(/*model*/ MODEL_RR_CRUISER_WING,             /*pos*/  4101,  2435, -1813, /*angle*/  0,   0,   0, /*behParam*/ 0x00000000, /*beh*/ bhvRrCruiserWing),
    OBJECT(/*model*/ MODEL_RR_CRUISER_WING,             /*pos*/  2859,  2411, -1834, /*angle*/  0,   0,   0, /*behParam*/ 0x00000000, /*beh*/ bhvRrCruiserWing),
    OBJECT(/*model*/ MODEL_RR_SEESAW_PLATFORM,          /*pos*/ -6013, -2857,  6564, /*angle*/  0, 270,   0, /*behParam*/ 0x00050000, /*beh*/ bhvSeesawPlatform),
    OBJECT(/*model*/ MODEL_RR_SEESAW_PLATFORM,          /*pos*/   614, -3574,  6564, /*angle*/  0, 270,   0, /*behParam*/ 0x00050000, /*beh*/ bhvSeesawPlatform),
    OBJECT(/*model*/ MODEL_RR_SWINGING_PLATFORM,        /*pos*/ -3557,  -809,  4619, /*angle*/  0,   0,   0, /*behParam*/ 0x00000000, /*beh*/ bhvSwingPlatform),
    OBJECT(/*model*/ MODEL_RR_SWINGING_PLATFORM,        /*pos*/ -2213, -2582,  6257, /*angle*/  0,   0,   0, /*behParam*/ 0x00000000, /*beh*/ bhvSwingPlatform),
    OBJECT(/*model*/ MODEL_NONE,                        /*pos*/     0,     0,     0, /*angle*/  0,   0,   0, /*behParam*/ 0x00000000, /*beh*/ bhvDonutPlatformSpawner),
    OBJECT(/*model*/ MODEL_RR_ELEVATOR_PLATFORM,        /*pos*/ -2684,  1546,   -36, /*angle*/  0,   0,   0, /*behParam*/ 0x00050000, /*beh*/ bhvRrElevatorPlatform),
    OBJECT(/*model*/ MODEL_RR_TRICKY_TRIANGLES,         /*pos*/  5862, -1347,  6564, /*angle*/  0,   0,   0, /*behParam*/ 0x00020000, /*beh*/ bhvAnimatesOnFloorSwitchPress),
    OBJECT(/*model*/ MODEL_PURPLE_SWITCH,               /*pos*/  4428, -1936,  6564, /*angle*/  0,   0,   0, /*behParam*/ 0x00000000, /*beh*/ bhvFloorSwitchAnimatesObject),
    OBJECT(/*model*/ MODEL_NONE,                        /*pos*/   614, -2857,  3671, /*angle*/  0,   0,   0, /*behParam*/ 0x00CC0000, /*beh*/ bhvPoleGrabbing),
    OBJECT(/*model*/ MODEL_NONE,                        /*pos*/   621, -4598,  7362, /*angle*/  0,   0,   0, /*behParam*/ 0x00750000, /*beh*/ bhvPoleGrabbing),
    OBJECT(/*model*/ MODEL_NONE,                        /*pos*/  5119,  3819,  3325, /*angle*/  0,   0,   0, /*behParam*/ 0x00610000, /*beh*/ bhvPoleGrabbing),
    OBJECT(/*model*/ MODEL_NONE,                        /*pos*/  3554,  2891, -2327, /*angle*/  0,   0,   0, /*behParam*/ 0x00C10000, /*beh*/ bhvPoleGrabbing),
    OBJECT(/*model*/ MODEL_NONE,                        /*pos*/  2680,   214,   295, /*angle*/  0,   0,   0, /*behParam*/ 0x00620000, /*beh*/ bhvPoleGrabbing),
    OBJECT(/*model*/ MODEL_NONE,                        /*pos*/  3811,  1033,   295, /*angle*/  0,   0,   0, /*behParam*/ 0x00620000, /*beh*/ bhvPoleGrabbing),
    RETURN(),
};

static const LevelScript script_rr_objects_2[] = {
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ -5809, -1834,  5719, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFlamethrower),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ -4838, -1015,  4081, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFlamethrower),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/  3301, -1834,  5617, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFlamethrower),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/  6772,  -757,  -606, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFlamethrower),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ -4187,  3213, -6630, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFlamethrower),
    RETURN(),
};

static const LevelScript script_rr_objects_3[] = {
    OBJECT_WITH_ACTS(/*model*/ MODEL_STAR, /*pos*/  1450,  3400, -2352, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStar,                 /*acts*/ ALL_ACTS),
    OBJECT_WITH_ACTS(/*model*/ MODEL_STAR, /*pos*/ -4200,  6700, -4450, /*angle*/ 0, 0, 0, /*behParam*/ 0x01000000, /*beh*/ bhvStar,                 /*acts*/ ALL_ACTS),
    OBJECT_WITH_ACTS(/*model*/ MODEL_NONE, /*pos*/ -5150, -1400,     0, /*angle*/ 0, 0, 0, /*behParam*/ 0x02000000, /*beh*/ bhvHiddenRedCoinStar, /*acts*/ ALL_ACTS),
    OBJECT_WITH_ACTS(/*model*/ MODEL_STAR, /*pos*/ -5850,  -700,  4950, /*angle*/ 0, 0, 0, /*behParam*/ 0x03000000, /*beh*/ bhvStar,                 /*acts*/ ALL_ACTS),
    OBJECT_WITH_ACTS(/*model*/ MODEL_STAR, /*pos*/  3700,  -400,  6600, /*angle*/ 0, 0, 0, /*behParam*/ 0x04000000, /*beh*/ bhvStar,                 /*acts*/ ALL_ACTS),
    RETURN(),
};

const LevelScript level_rr_entry[] = {
    INIT_LEVEL(),
#include "levels/rr/areas/script_vanilla_load.inc.c"
    ALLOC_LEVEL_POOL(),
    MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
#include "levels/rr/areas/script_vanilla.inc.c"

    AREA(/*index*/ 1, rr_geo_0009D0),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ 2599, -833, 2071, /*angle*/ 0, 90, 0, /*behParam*/ 0x000A0000, /*beh*/ bhvSpinAirborneWarp),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ -7092, 2364, -63, /*angle*/ 0, 90, 0, /*behParam*/ 0x000B0000, /*beh*/ bhvFadingWarp),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ -4213, 3379, -2815, /*angle*/ 0, 180, 0, /*behParam*/ 0x000C0000, /*beh*/ bhvFadingWarp),
        WARP_NODE(/*id*/ 0x0A, /*destLevel*/ LEVEL_RR, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x0B, /*destLevel*/ LEVEL_RR, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x0C, /*destLevel*/ LEVEL_RR, /*destArea*/ 0x01, /*destNode*/ 0x0B, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF0, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x02, /*destNode*/ 0x3A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF1, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x02, /*destNode*/ 0x6C, /*flags*/ WARP_NO_CHECKPOINT),
        JUMP_LINK(script_rr_objects_1),
        JUMP_LINK(script_rr_objects_2),
        JUMP_LINK(script_rr_objects_3),
        TERRAIN(/*terrainData*/ rr_seg7_collision_level),
        JUMP_LINK(script_rr_macro_objects),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0000, /*seq*/ SEQ_LEVEL_SLIDE),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_STONE),
    END_AREA(),

    FREE_LEVEL_POOL(),
    MARIO_POS(/*area*/ 1, /*yaw*/ 90, /*pos*/ 2599, -1833, 2071),
    CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
    CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(/*frames*/ 1),
    EXIT(),
};
