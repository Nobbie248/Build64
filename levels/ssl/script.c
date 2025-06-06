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
#include "levels/ssl/header.h"


static const LevelScript script_ssl_area_1_macro_objects[] = {
    // Macro objects
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/  6068,    51,  2800, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/  5535,    51,  3377, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/  5980,    51,  3911, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/  4602,    40,  4622, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvPokey),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/  5057,   143,   256, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvPokey),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/ -6858,     8, -3711, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvPokey),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/ -5372,    64,  3083, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvPokey),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,     /*pos*/  5900,    51,  4400, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,     /*pos*/  5900,    51,  2311, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_BOBOMB_BUDDY,      /*pos*/ -5990,     0, -3871, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvBobombBuddyOpensCannon),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -5869,  1200, -2535, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -5896,  1200,   773, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  1800,  1200,   800, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  1805,  1200, -2536, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,   /*pos*/  6900,   350, -5400, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_WING_CAP << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,   /*pos*/ -3000,   500,   800, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_WING_CAP << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_DL_CANNON_LID,     /*pos*/  6863,     0, -6860, /*angle*/ 0,   0, 0, /*behParam*/ (0xC0 << 16), /*beh*/ bhvCannonClosed),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,     /*pos*/  5900,    50,  3440, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvBreakableBoxSmall),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -4500,  1500, -3500, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -4500,  1500,  1500, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/   500,  1500, -3500, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/   500,  1500,  1500, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/  3380,    10, -4900, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -5270,  -170, -6780, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/ -7450,    10,  7560, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,          /*pos*/  5900,    70,  2311, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,   /*pos*/  5840,   940,  2500, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_KOOPA_SHELL << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,   /*pos*/  5860,   940,  4180, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_WING_CAP    << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_WOODEN_SIGNPOST,   /*pos*/  5702,   614,  2974, /*angle*/ 0,   0, 0, /*behParam*/ (DIALOG_016 << 16), /*beh*/ bhvMessagePanel),
    OBJECT(/*model*/ MODEL_WOODEN_SIGNPOST,   /*pos*/ -3260,   256,   800, /*angle*/ 0,   0, 0, /*behParam*/ (DIALOG_032 << 16), /*beh*/ bhvMessagePanel),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/ -6000,   600, -4800, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHidden1upInPoleSpawner),
    OBJECT(/*model*/ MODEL_1UP,               /*pos*/  -250,     0,  4200, /*angle*/ 0,   0, 0, /*behParam*/ (MUSHROOM_BP_REQUIRES_NONE << 16), /*beh*/ bhv1Up),
    OBJECT(/*model*/ MODEL_FLYGUY,            /*pos*/  3500,   149,  5600, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFlyGuy),
    OBJECT(/*model*/ MODEL_BLACK_BOBOMB,      /*pos*/  3800,     0,  6000, /*angle*/ 0,   0, 0, /*behParam*/ (BOBOMB_BP_STYPE_GENERIC << 16), /*beh*/ bhvBobomb),
    OBJECT(/*model*/ MODEL_BLACK_BOBOMB,      /*pos*/  1750,     0,  6450, /*angle*/ 0,   0, 0, /*behParam*/ (BOBOMB_BP_STYPE_GENERIC << 16), /*beh*/ bhvBobomb),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/ -5920,   200,  -920, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_NONE) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_BOWLING_BALL,      /*pos*/  -386,   512, -2228, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFireSpitter),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/ -2290,   787, -2180, /*angle*/ 0,  90, 0, /*behParam*/ ((COIN_FORMATION_FLAG_NONE) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_FLYGUY,            /*pos*/  1440,   800,  -960, /*angle*/ 0,   0, 0, /*behParam*/ (FLY_GUY_BP_SHOOTS_FIRE << 16), /*beh*/ bhvFlyGuy),
    OBJECT(/*model*/ MODEL_FLYGUY,            /*pos*/ -3400,  1160, -1120, /*angle*/ 0,   0, 0, /*behParam*/ (FLY_GUY_BP_SHOOTS_FIRE << 16), /*beh*/ bhvFlyGuy),
    OBJECT(/*model*/ MODEL_BOWLING_BALL,      /*pos*/ -5125,   135, -3138, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFireSpitter),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,     /*pos*/  1120,     0,  6480, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvJumpingBox),
    OBJECT(/*model*/ MODEL_1UP,               /*pos*/  5757,   230,  5761, /*angle*/ 0,   0, 0, /*behParam*/ (MUSHROOM_BP_REQUIRES_NONE << 16), /*beh*/ bhv1Up),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,     /*pos*/ -5200,     0,  1700, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvJumpingBox),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,   /*pos*/ -1200,   500,   800, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_1UP_RUNNING_AWAY << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_WOODEN_SIGNPOST,   /*pos*/  5130,    26,  -370, /*angle*/ 0,   0, 0, /*behParam*/ (DIALOG_157 << 16), /*beh*/ bhvMessagePanel),
    // Special objects
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/  5760,     0,  5751, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/ -3583,     0,  2935, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/  -511,     0,  2935, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/  1024,     0,  3822, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_03, /*pos*/  3072,     0,   375, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_SSL_PALM_TREE,     /*pos*/ -5989,     0, -4850, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvTree),
    RETURN(),
};

static const LevelScript script_ssl_area_2_macro_objects[] = {
    // Macro objects
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/  3263,   778,  3157, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_WOODEN_SIGNPOST,   /*pos*/  2196,   640, -3329, /*angle*/ 0, 270, 0, /*behParam*/ (DIALOG_043 << 16), /*beh*/ bhvMessagePanel),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,   /*pos*/ -3536,   252, -3705, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_1UP_WALKING << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/  3389,     0, -1978, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/ -3638,     0,  1928, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,   /*pos*/ -1242,   252, -3957, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_1UP_WALKING << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  1873,     0, -3495, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvOneCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  1200,     0, -3495, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvOneCoin),
    OBJECT(/*model*/ MODEL_AMP,               /*pos*/  3056,   736, -3267, /*angle*/ 0,   0, 0, /*behParam*/ (1 << 16), /*beh*/ bhvCirclingAmp),
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/  3263,   652,  2200, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/  3431,   673, -1373, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/    -2,  1774,  2794, /*angle*/ 0,  90, 0, /*behParam*/ ((COIN_FORMATION_FLAG_FLYING                               ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/  2694,   850, -2889, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_RING    ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_HEART,             /*pos*/  -400,  1978, -2250, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRecoveryHeart),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/   736,  2652, -2250, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/   736,  2546, -2250, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  1368,  3263, -2250, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  1368,  3135, -2250, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_AMP,               /*pos*/  1621,  3368, -1142, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHomingAmp),
    OBJECT(/*model*/ MODEL_AMP,               /*pos*/  1621,  3389,   478, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHomingAmp),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/  -210,  4521,  -994, /*angle*/ 0,  90, 0, /*behParam*/ ((COIN_FORMATION_FLAG_NONE                                 ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_GOOMBA,            /*pos*/ -2100,     0,  3316, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGoomba),
    OBJECT(/*model*/ MODEL_BLUE_COIN_SWITCH,  /*pos*/  -719,     0,  4772, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvBlueCoinSwitch),
    OBJECT(/*model*/ MODEL_BLUE_COIN,         /*pos*/     0,     0,  2381, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_BLUE_COIN,         /*pos*/     0,   100,  2381, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_BLUE_COIN,         /*pos*/     0,   200,  2381, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/  2064,   -81, -1901, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHidden1upTrigger),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/  2569,   -81, -2022, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHidden1upTrigger),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/  2698,   -81, -2535, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHidden1upTrigger),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/  2698,   -81, -3049, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHidden1upTrigger),
    OBJECT(/*model*/ MODEL_1UP,               /*pos*/  1940,   -81, -1360, /*angle*/ 0,   0, 0, /*behParam*/ (4 << 16), /*beh*/ bhvHidden1up),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/  -260,  2940,  -600, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenStarTrigger),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/   260,  1967,  -600, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenStarTrigger),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/ -1940,  1229,  -600, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenStarTrigger),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/ -1940,  1229,  2320, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenStarTrigger),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/   290,  4479,  -940, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_VERTICAL) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_WOODEN_SIGNPOST,   /*pos*/ -3560,     0, -4065, /*angle*/ 0,   0, 0, /*behParam*/ (DIALOG_103 << 16), /*beh*/ bhvMessagePanel),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/   260,  3913,  -600, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenStarTrigger),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/  -260,  2950,  -600, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/   260,  1977,  -600, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -1940,  1239,  -600, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -1940,  1239,  2320, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/   260,  3923,  -600, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvYellowCoin),
    OBJECT(/*model*/ MODEL_NONE,              /*pos*/  3181,     0,  3587, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGoombaTripletSpawner),
    OBJECT(/*model*/ MODEL_1UP,               /*pos*/ -3350,   980, -1240, /*angle*/ 0,   0, 0, /*behParam*/ (MUSHROOM_BP_REQUIRES_NONE << 16), /*beh*/ bhv1Up),
    OBJECT(/*model*/ MODEL_1UP,               /*pos*/  2870,  1050, -2640, /*angle*/ 0,   0, 0, /*behParam*/ (MUSHROOM_BP_REQUIRES_NONE << 16), /*beh*/ bhv1Up),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -2047,  1664,  3076, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvOneCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -2047,  1536,  2870, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvOneCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -1840,  1357,  3076, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvOneCoin),
    OBJECT(/*model*/ MODEL_YELLOW_COIN,       /*pos*/ -1840,  1408,  2870, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvOneCoin),
    // Special objects
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_04, /*pos*/  1741,  -101,  1843, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_04, /*pos*/     0,  -101,   528, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    OBJECT(/*model*/ MODEL_LEVEL_GEOMETRY_04, /*pos*/ -1740,  -101,  1843, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvStaticObject),
    RETURN(),
};

static const LevelScript script_ssl_area_1_objects_1[] = {
    OBJECT(/*model*/ MODEL_SSL_PYRAMID_TOP, /*pos*/ -2047, 1536, -1023, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvPyramidTop),
    RETURN(),
};

static const LevelScript script_ssl_area_1_objects_2[] = {
    OBJECT(/*model*/ MODEL_SSL_TOX_BOX,     /*pos*/ -1284,    0, -5895, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvToxBox),
    OBJECT(/*model*/ MODEL_SSL_TOX_BOX,     /*pos*/  1283,    0, -4865, /*angle*/ 0, 0, 0, /*behParam*/ 0x00010000, /*beh*/ bhvToxBox),
    OBJECT(/*model*/ MODEL_SSL_TOX_BOX,     /*pos*/  4873,    0, -3335, /*angle*/ 0, 0, 0, /*behParam*/ 0x00020000, /*beh*/ bhvToxBox),
    OBJECT(/*model*/ MODEL_TWEESTER,        /*pos*/ -3600, -200,  2940, /*angle*/ 0, 0, 0, /*behParam*/ 0x00120000, /*beh*/ bhvTweester),
    OBJECT_WITH_ACTS(/*model*/ MODEL_TWEESTER,        /*pos*/  1017, -200,  3832, /*angle*/ 0, 0, 0, /*behParam*/ 0x00190000, /*beh*/ bhvTweester, /*acts*/ ACT_4 | ACT_5 | ACT_6),
    OBJECT_WITH_ACTS(/*model*/ MODEL_TWEESTER,        /*pos*/  3066, -200,   400, /*angle*/ 0, 0, 0, /*behParam*/ 0x00190000, /*beh*/ bhvTweester, /*acts*/ ACT_4 | ACT_5 | ACT_6),
    OBJECT_WITH_ACTS(/*model*/ MODEL_KLEPTO,          /*pos*/  2200, 1174, -2820, /*angle*/ 0, 0, 0, /*behParam*/ 0x00010000, /*beh*/ bhvKlepto,   /*acts*/ ACT_1),
    OBJECT_WITH_ACTS(/*model*/ MODEL_KLEPTO,          /*pos*/ -5963,  573, -4784, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvKlepto,   /*acts*/ ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
    RETURN(),
};

static const LevelScript script_ssl_area_1_objects_3[] = {
    OBJECT_WITH_ACTS(/*model*/ MODEL_STAR, /*pos*/ -2050, 1200, -580, /*angle*/ 0, 0, 0, /*behParam*/ 0x01000000, /*beh*/ bhvStar,                 /*acts*/ ALL_ACTS),
    OBJECT_WITH_ACTS(/*model*/ MODEL_NONE, /*pos*/  6000,  800, 3500, /*angle*/ 0, 0, 0, /*behParam*/ 0x04000000, /*beh*/ bhvHiddenRedCoinStar, /*acts*/ ALL_ACTS),
    RETURN(),
};

static const LevelScript script_ssl_area_2_objects_1[] = {
    OBJECT(/*model*/ MODEL_NONE,                    /*pos*/  2867,  640,  2867, /*angle*/ 0,   0, 0, /*behParam*/ 0x004D0000, /*beh*/ bhvPoleGrabbing),
    OBJECT(/*model*/ MODEL_NONE,                    /*pos*/     0, 3200,  1331, /*angle*/ 0,   0, 0, /*behParam*/ 0x005C0000, /*beh*/ bhvPoleGrabbing),
    OBJECT(/*model*/ MODEL_SSL_GRINDEL,             /*pos*/  3297,    0,    95, /*angle*/ 0,   0, 0, /*behParam*/ 0x001C0000, /*beh*/ bhvGrindel),
    OBJECT(/*model*/ MODEL_SSL_GRINDEL,             /*pos*/  -870, 3840,   105, /*angle*/ 0, 180, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHorizontalGrindel),
    OBJECT(/*model*/ MODEL_SSL_GRINDEL,             /*pos*/ -3362,    0, -1385, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHorizontalGrindel),
    OBJECT(/*model*/ MODEL_SSL_SPINDEL,             /*pos*/ -2458, 2109, -1430, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSpindel),
    OBJECT(/*model*/ MODEL_SSL_MOVING_PYRAMID_WALL, /*pos*/   858, 1927, -2307, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSslMovingPyramidWall),
    OBJECT(/*model*/ MODEL_SSL_MOVING_PYRAMID_WALL, /*pos*/   730, 1927, -2307, /*angle*/ 0,   0, 0, /*behParam*/ 0x00010000, /*beh*/ bhvSslMovingPyramidWall),
    OBJECT(/*model*/ MODEL_SSL_MOVING_PYRAMID_WALL, /*pos*/  1473, 2567, -2307, /*angle*/ 0,   0, 0, /*behParam*/ 0x00010000, /*beh*/ bhvSslMovingPyramidWall),
    OBJECT(/*model*/ MODEL_SSL_MOVING_PYRAMID_WALL, /*pos*/  1345, 2567, -2307, /*angle*/ 0,   0, 0, /*behParam*/ 0x00020000, /*beh*/ bhvSslMovingPyramidWall),
    OBJECT(/*model*/ MODEL_SSL_PYRAMID_ELEVATOR,    /*pos*/     0, 4966,   256, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvPyramidElevator),
    OBJECT(/*model*/ MODEL_NONE,                    /*pos*/  1198, -133,  2396, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSandSoundLoop),
    OBJECT(/*model*/ MODEL_NONE,                    /*pos*/     7, 1229,  -708, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSandSoundLoop),
    OBJECT(/*model*/ MODEL_NONE,                    /*pos*/     7, 4317,  -708, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSandSoundLoop),
    RETURN(),
};

static const LevelScript script_ssl_area_2_objects_2[] = {
    OBJECT_WITH_ACTS(/*model*/ MODEL_STAR, /*pos*/ 500, 5050, -500, /*angle*/ 0, 0, 0, /*behParam*/ 0x02000000, /*beh*/ bhvStar,        /*acts*/ ALL_ACTS),
    OBJECT_WITH_ACTS(/*model*/ MODEL_NONE, /*pos*/ 900, 1400, 2350, /*angle*/ 0, 0, 0, /*behParam*/ 0x05040000, /*beh*/ bhvHiddenStar, /*acts*/ ALL_ACTS),
    RETURN(),
};

static const LevelScript script_ssl_area_3_objects_1[] = {
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ 0, -1534, -3693, /*angle*/ 0, 0, 0, /*behParam*/ 0x03000000, /*beh*/ bhvEyerokBoss),
    RETURN(),
};

const LevelScript level_ssl_entry[] = {
    INIT_LEVEL(),
#include "levels/ssl/areas/script_vanilla_load.inc.c"
    ALLOC_LEVEL_POOL(),
    MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
#include "levels/ssl/areas/script_vanilla.inc.c"

    AREA(/*index*/ 1, ssl_geo_000648),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/   653, 1038,  6566, /*angle*/ 0,  90, 0, /*behParam*/ 0x000A0000, /*beh*/ bhvSpinAirborneWarp),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ -2048,    0,    56, /*angle*/ 0,   0, 0, /*behParam*/ 0x00140000, /*beh*/ bhvWarp),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ -2048,  768, -1024, /*angle*/ 0,   0, 0, /*behParam*/ 0x0F1E0000, /*beh*/ bhvWarp),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/  6930,    0, -4871, /*angle*/ 0, 159, 0, /*behParam*/ 0x001F0000, /*beh*/ bhvFadingWarp),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ -5943,    0, -4903, /*angle*/ 0,  49, 0, /*behParam*/ 0x00200000, /*beh*/ bhvFadingWarp),
        WARP_NODE(/*id*/ 0x0A, /*destLevel*/ LEVEL_SSL, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x14, /*destLevel*/ LEVEL_SSL, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*flags*/ WARP_CHECKPOINT),
        WARP_NODE(/*id*/ 0x1E, /*destLevel*/ LEVEL_SSL, /*destArea*/ 0x02, /*destNode*/ 0x14, /*flags*/ WARP_CHECKPOINT),
        WARP_NODE(/*id*/ 0x1F, /*destLevel*/ LEVEL_SSL, /*destArea*/ 0x01, /*destNode*/ 0x20, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x20, /*destLevel*/ LEVEL_SSL, /*destArea*/ 0x01, /*destNode*/ 0x1F, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF0, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x03, /*destNode*/ 0x33, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF1, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x03, /*destNode*/ 0x65, /*flags*/ WARP_NO_CHECKPOINT),
        JUMP_LINK(script_ssl_area_1_objects_1),
        JUMP_LINK(script_ssl_area_1_objects_2),
        JUMP_LINK(script_ssl_area_1_objects_3),
        TERRAIN(/*terrainData*/ ssl_seg7_area_1_collision),
        JUMP_LINK(script_ssl_area_1_macro_objects),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0000, /*seq*/ SEQ_LEVEL_HOT),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_SAND),
    END_AREA(),

    AREA(/*index*/ 2, ssl_geo_0007CC),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/    0,  300,  6451, /*angle*/ 0, 180, 0, /*behParam*/ 0x000A0000, /*beh*/ bhvAirborneWarp),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/    0, 5500,   256, /*angle*/ 0, 180, 0, /*behParam*/ 0x00140000, /*beh*/ bhvAirborneWarp),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ 3070, 1280,  2900, /*angle*/ 0, 180, 0, /*behParam*/ 0x00150000, /*beh*/ bhvFadingWarp),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ 2546, 1150, -2647, /*angle*/ 0,  78, 0, /*behParam*/ 0x00160000, /*beh*/ bhvFadingWarp),
        WARP_NODE(/*id*/ 0x0A, /*destLevel*/ LEVEL_SSL, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x14, /*destLevel*/ LEVEL_SSL, /*destArea*/ 0x02, /*destNode*/ 0x14, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x15, /*destLevel*/ LEVEL_SSL, /*destArea*/ 0x02, /*destNode*/ 0x16, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x16, /*destLevel*/ LEVEL_SSL, /*destArea*/ 0x02, /*destNode*/ 0x15, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF0, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x03, /*destNode*/ 0x33, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF1, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x03, /*destNode*/ 0x65, /*flags*/ WARP_NO_CHECKPOINT),
        JUMP_LINK(script_ssl_area_2_objects_1),
        JUMP_LINK(script_ssl_area_2_objects_2),
        INSTANT_WARP(/*index*/ 3, /*destArea*/ 3, /*displace*/ 0, 0, 0),
        TERRAIN(/*terrainData*/ ssl_seg7_area_2_collision),
        JUMP_LINK(script_ssl_area_2_macro_objects),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0004, /*seq*/ SEQ_LEVEL_UNDERGROUND),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_STONE),
    END_AREA(),

    AREA(/*index*/ 3, ssl_geo_00088C),
        WARP_NODE(/*id*/ 0xF0, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x03, /*destNode*/ 0x33, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF1, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x03, /*destNode*/ 0x65, /*flags*/ WARP_NO_CHECKPOINT),
        JUMP_LINK(script_ssl_area_3_objects_1),
        TERRAIN(/*terrainData*/ ssl_seg7_area_3_collision),
        INSTANT_WARP(/*index*/ 2, /*destArea*/ 2, /*displace*/ 0, 0, 0),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0004, /*seq*/ SEQ_LEVEL_UNDERGROUND),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_STONE),
    END_AREA(),

    FREE_LEVEL_POOL(),
    MARIO_POS(/*area*/ 1, /*yaw*/ 88, /*pos*/ 653, 38, 6566),
    CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
    CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(/*frames*/ 1),
    EXIT(),
};
