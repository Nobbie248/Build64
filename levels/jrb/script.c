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
#include "levels/jrb/header.h"


static const LevelScript script_jrb_area_1_macro_objects[] = {
    // Macro objects
    OBJECT(/*model*/ MODEL_WOODEN_SIGNPOST,  /*pos*/ -6325,  1126,  1730, /*angle*/ 0, 250, 0, /*behParam*/ (DIALOG_060 << 16), /*beh*/ bhvMessagePanel),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/  5060, -4420,   720, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_RING | COIN_FORMATION_FLAG_VERTICAL) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,  /*pos*/  2077,  1832,  7465, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_METAL_CAP << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/ -1780,  -650,  4200, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_RING) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_PURPLE_SWITCH,    /*pos*/  2260,  1536,  6854, /*angle*/ 0,  45, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFloorSwitchHiddenObjects),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/  4269,  1336,  4866, /*angle*/ 0,  45, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/  4128,  1336,  5007, /*angle*/ 0,  45, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/  3400,  1336,  5155, /*angle*/ 0,  45, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/  3261,  1336,  5294, /*angle*/ 0,  45, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/  3120,  1336,  5435, /*angle*/ 0,  45, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/  3551, -5120,  2744, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSeaweedBundle),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/  4201, -5120,  3863, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSeaweedBundle),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/ -2440, -2980, -4120, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_RING) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,  /*pos*/   279, -2600, -7340, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_METAL_CAP << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/  4846, -5119,  1213, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSeaweedBundle),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/  -800, -1023,  4040, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSeaweedBundle),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/  3621,  1336,  6529, /*angle*/ 0,  45, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/  3485,  1336,  6665, /*angle*/ 0,  45, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/  2671,  1336,  6459, /*angle*/ 0,  45, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_RED_COIN,         /*pos*/  4900,  1800,  4700, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,         /*pos*/ -2535,  2110,  6113, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,         /*pos*/ -1845, -1003,  3518, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,         /*pos*/  -546,   530,  5930, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,         /*pos*/   648,  -490,  4256, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,         /*pos*/  3642, -5103,  3175, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,         /*pos*/  4400,  2200,  1300, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,         /*pos*/  5400,  2200,  1300, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_WOODEN_SIGNPOST,  /*pos*/  -900, -2966, -2200, /*angle*/ 0, 180, 0, /*behParam*/ (DIALOG_073 << 16), /*beh*/ bhvMessagePanel),
    OBJECT(/*model*/ MODEL_WOODEN_SIGNPOST,  /*pos*/ -2552,  1331,  6573, /*angle*/ 0,  80, 0, /*behParam*/ (DIALOG_051 << 16), /*beh*/ bhvMessagePanel),
    OBJECT(/*model*/ MODEL_CLAM_SHELL,       /*pos*/ -1800, -1023,  3500, /*angle*/ 0, 315, 0, /*behParam*/ 0x00000000, /*beh*/ bhvClamShell),
    OBJECT(/*model*/ MODEL_CLAM_SHELL,       /*pos*/  -480,   512,  5980, /*angle*/ 0, 225, 0, /*behParam*/ 0x00000000, /*beh*/ bhvClamShell),
    OBJECT(/*model*/ MODEL_CLAM_SHELL,       /*pos*/   700,  -511,  4250, /*angle*/ 0, 270, 0, /*behParam*/ 0x00000000, /*beh*/ bhvClamShell),
    OBJECT(/*model*/ MODEL_CLAM_SHELL,       /*pos*/  3600, -5119,  3200, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvClamShell),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/ -2523,  -246,  4676, /*angle*/ 0,   0, 0, /*behParam*/ (FISH_SPAWNER_BP_FEW_BLUE << 16), /*beh*/ bhvFishSpawner),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/  5876, -4738,  3476, /*angle*/ 0,   0, 0, /*behParam*/ (FISH_SPAWNER_BP_FEW_BLUE << 16), /*beh*/ bhvFishSpawner),
    OBJECT(/*model*/ MODEL_BLUE_COIN_SWITCH, /*pos*/  6011, -2966, -5511, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvBlueCoinSwitch),
    OBJECT(/*model*/ MODEL_BLUE_COIN,        /*pos*/  5900, -2966, -7347, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_BLUE_COIN,        /*pos*/  5300, -2966, -7347, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_BLUE_COIN,        /*pos*/  4700, -2966, -7347, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_BLUE_COIN,        /*pos*/  4100, -2966, -7347, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_BLUE_COIN,        /*pos*/  3500, -2966, -7347, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_BLUE_COIN,        /*pos*/  2900, -2966, -7347, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/  3305, -2966, -6147, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvGoombaTripletSpawner),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/   255,  1160,  7633, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_VERTICAL) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/    51,   960,  2744, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_RING    ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/  5060, -4220,   720, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHidden1upTrigger),
    OBJECT(/*model*/ MODEL_1UP,              /*pos*/  5140, -4380,     0, /*angle*/ 0,   0, 0, /*behParam*/ (1 << 16), /*beh*/ bhvHidden1up),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/  4072, -4463,  2027, /*angle*/ 0,   0, 0, /*behParam*/ (FISH_SPAWNER_BP_FEW_CYAN << 16), /*beh*/ bhvFishSpawner),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/  -290,   190,  4645, /*angle*/ 0,   0, 0, /*behParam*/ (FISH_SPAWNER_BP_FEW_CYAN << 16), /*beh*/ bhvFishSpawner),
    OBJECT(/*model*/ MODEL_DL_CANNON_LID,    /*pos*/ -4235,  1247,  2137, /*angle*/ 0,   0, 0, /*behParam*/ (0x00 << 16), /*beh*/ bhvCannonClosed),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/  2536,  1336,  6594, /*angle*/ 0,  45, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/  4220,  1536,  5700, /*angle*/ 0,  45, 0, /*behParam*/ ((COIN_FORMATION_FLAG_NONE                                 ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/  3987,  1336,  5148, /*angle*/ 0,  45, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/  3280,  1536,  5940, /*angle*/ 0,  45, 0, /*behParam*/ ((COIN_FORMATION_FLAG_NONE                                 ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/  3200,  1536,  6720, /*angle*/ 0,  45, 0, /*behParam*/ ((COIN_FORMATION_FLAG_NONE                                 ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,  /*pos*/ -7160,  1340,  2580, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_METAL_CAP << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_WOODEN_SIGNPOST,  /*pos*/ -6910,  1120,  2380, /*angle*/ 0, 180, 0, /*behParam*/ (DIALOG_113 << 16), /*beh*/ bhvMessagePanel),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,  /*pos*/ -5800,  1340,  -750, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_COINS_3   << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_1UP,              /*pos*/   670,  3000,  3315, /*angle*/ 0,   0, 0, /*behParam*/ (MUSHROOM_BP_REQUIRES_NONE << 16), /*beh*/ bhv1Up),
    OBJECT(/*model*/ MODEL_KOOPA_SHELL,      /*pos*/ -1480, -1000,  4820, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvKoopaShellUnderwater),
    OBJECT(/*model*/ MODEL_CLAM_SHELL,       /*pos*/ -1480, -1040,  4820, /*angle*/ 0, 180, 0, /*behParam*/ 0x00000000, /*beh*/ bhvClamShell),
    OBJECT(/*model*/ MODEL_WOODEN_SIGNPOST,  /*pos*/  5290, -2966, -4740, /*angle*/ 0,   0, 0, /*behParam*/ (DIALOG_169 << 16), /*beh*/ bhvMessagePanel),
    RETURN(),
};

static const LevelScript script_jrb_area_2_macro_objects[] = {
    // Macro objects
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX, /*pos*/     0,  1600,  3000, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_STAR_1 << 16), /*beh*/ bhvExclamationBox),
    RETURN(),
};

static const LevelScript script_jrb_area_1_objects_1[] = {
    OBJECT_WITH_ACTS(/*model*/ MODEL_JRB_SUNKEN_SHIP,          /*pos*/  2385,  3589,  3727, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSunkenShipPart,         /*acts*/ ACT_1),
    OBJECT_WITH_ACTS(/*model*/ MODEL_JRB_SUNKEN_SHIP_BACK,     /*pos*/  2385,  3589,  3727, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSunkenShipPart,         /*acts*/ ACT_1),
    OBJECT_WITH_ACTS(/*model*/ MODEL_JRB_SHIP_LEFT_HALF_PART,  /*pos*/  5385, -5520,  2428, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSunkenShipPart2,        /*acts*/ ACT_1),
    OBJECT_WITH_ACTS(/*model*/ MODEL_JRB_SHIP_RIGHT_HALF_PART, /*pos*/  5385, -5520,  2428, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSunkenShipPart2,        /*acts*/ ACT_1),
    OBJECT_WITH_ACTS(/*model*/ MODEL_NONE,                     /*pos*/  5385, -5520,  2428, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvInSunkenShip,           /*acts*/ ACT_1),
    OBJECT_WITH_ACTS(/*model*/ MODEL_NONE,                     /*pos*/  5385, -5520,  2428, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvInSunkenShip2,          /*acts*/ ACT_1),
    OBJECT_WITH_ACTS(/*model*/ MODEL_JRB_SHIP_LEFT_HALF_PART,  /*pos*/  4880,   820,  2375, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvShipPart3,              /*acts*/ ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
    OBJECT_WITH_ACTS(/*model*/ MODEL_JRB_SHIP_BACK_LEFT_PART,  /*pos*/  4880,   820,  2375, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvShipPart3,              /*acts*/ ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
    OBJECT_WITH_ACTS(/*model*/ MODEL_JRB_SHIP_RIGHT_HALF_PART, /*pos*/  4880,   820,  2375, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvShipPart3,              /*acts*/ ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
    OBJECT_WITH_ACTS(/*model*/ MODEL_JRB_SHIP_BACK_RIGHT_PART, /*pos*/  4880,   820,  2375, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvShipPart3,              /*acts*/ ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
    OBJECT_WITH_ACTS(/*model*/ MODEL_NONE,                     /*pos*/  4880,   820,  2375, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvInSunkenShip3,          /*acts*/ ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
    OBJECT_WITH_ACTS(/*model*/ MODEL_JRB_SLIDING_BOX,          /*pos*/  4668,  1434,  2916, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvJrbSlidingBox,          /*acts*/ ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
    OBJECT_WITH_ACTS(/*model*/ MODEL_UNAGI,                    /*pos*/  6048, -5381,  1154, /*angle*/ 0, 340, 0, /*behParam*/ 0x00000000, /*beh*/ bhvUnagi,                  /*acts*/ ACT_1),
    OBJECT_WITH_ACTS(/*model*/ MODEL_UNAGI,                    /*pos*/  8270, -3130,  1846, /*angle*/ 0, 285, 0, /*behParam*/ 0x01010000, /*beh*/ bhvUnagi,                  /*acts*/ ACT_2),
    OBJECT_WITH_ACTS(/*model*/ MODEL_UNAGI,                    /*pos*/  6048, -5381,  1154, /*angle*/ 0, 340, 0, /*behParam*/ 0x02020000, /*beh*/ bhvUnagi,                  /*acts*/ ACT_3 | ACT_4 | ACT_5 | ACT_6),
    OBJECT_WITH_ACTS(/*model*/ MODEL_NONE,                     /*pos*/  4988, -5221,  2473, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvJetStream,              /*acts*/ ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
    OBJECT(          /*model*/ MODEL_NONE,                     /*pos*/ -1800, -2812, -2100, /*angle*/ 0,   0, 0, /*behParam*/ 0x02000000, /*beh*/ bhvTreasureChestsJrb),
    OBJECT_WITH_ACTS(/*model*/ MODEL_BOBOMB_BUDDY,             /*pos*/ -1956,  1331,  6500, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvBobombBuddyOpensCannon, /*acts*/ ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
    RETURN(),
};

static const LevelScript script_jrb_area_1_objects_2[] = {
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  1834, -2556, -7090, /*angle*/ 0, 194, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/ -2005, -2556, -3506, /*angle*/ 0, 135, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  1578, -2556, -5554, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/    42, -2556, -6578, /*angle*/ 0, 135, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  -981, -2556, -5298, /*angle*/ 0, 255, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/ -6549,  1536,  4343, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  1322, -2556, -3506, /*angle*/ 0, 165, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  6442, -2556, -6322, /*angle*/ 0, 135, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  3882, -2556, -5042, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  1497,  1741,  7810, /*angle*/ 0,  14, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/ -3978,  1536,   -85, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/ -5228,  1230,  2106, /*angle*/ 0, 323, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/ -7481,  1536,   185, /*angle*/ 0, 149, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/ -5749,  1536, -1113, /*angle*/ 0, 255, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/ -5332,  1434,  1023, /*angle*/ 0, 315, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  -815,  -613,  3556, /*angle*/ 0, 315, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/ -3429,   819,  4948, /*angle*/ 0, 284, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/ -1940,   410,  2377, /*angle*/ 0, 194, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/ -1798,  -716,  4330, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  -845,   922,  7668, /*angle*/ 0, 315, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  6741, -2886,  3556, /*angle*/ 0, 135, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/   255,  -101,  4719, /*angle*/ 0,  45, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  1787,  -306,  5133, /*angle*/ 0, 315, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  1079,  -613,  2299, /*angle*/ 0,  75, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  2931, -1697,   980, /*angle*/ 0, 315, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  3036, -4709,  4027, /*angle*/ 0, 315, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  4222, -1125,  7083, /*angle*/ 0, 104, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  6650,  -613,  4941, /*angle*/ 0, 315, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  5764, -4709,  4427, /*angle*/ 0, 315, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  3693, -4709,   856, /*angle*/ 0, 135, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  7981,   410,  2704, /*angle*/ 0, 165, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  2917, -3046,  4818, /*angle*/ 0, 241, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_JRB_ROCK,                 /*pos*/  5896,  -393,  -123, /*angle*/ 0, 315, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRockSolid),
    OBJECT(/*model*/ MODEL_NONE,                     /*pos*/    53,  2355,  2724, /*angle*/ 0,   0, 0, /*behParam*/ 0x00290000, /*beh*/ bhvPoleGrabbing),
    OBJECT(/*model*/ MODEL_NONE,                     /*pos*/   659,  2560,  3314, /*angle*/ 0,   0, 0, /*behParam*/ 0x00290000, /*beh*/ bhvPoleGrabbing),
    OBJECT(/*model*/ MODEL_NONE,                     /*pos*/  1087,  2150,  3798, /*angle*/ 0,   0, 0, /*behParam*/ 0x00290000, /*beh*/ bhvPoleGrabbing),
    OBJECT(/*model*/ MODEL_NONE,                     /*pos*/ -2535,  1075,  6113, /*angle*/ 0,   0, 0, /*behParam*/ 0x00610000, /*beh*/ bhvPoleGrabbing),
    OBJECT(/*model*/ MODEL_JRB_FALLING_PILLAR,       /*pos*/  2078, -2863, -4696, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFallingPillar),
    OBJECT(/*model*/ MODEL_JRB_FALLING_PILLAR,       /*pos*/ -1403, -2863, -4696, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFallingPillar),
    OBJECT(/*model*/ MODEL_JRB_FALLING_PILLAR,       /*pos*/ -1096, -2863, -3262, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFallingPillar),
    OBJECT(/*model*/ MODEL_JRB_FALLING_PILLAR,       /*pos*/   337, -2863, -5106, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFallingPillar),
    OBJECT(/*model*/ MODEL_JRB_FALLING_PILLAR,       /*pos*/  2078, -2863, -6232, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFallingPillar),
    OBJECT(/*model*/ MODEL_JRB_FALLING_PILLAR,       /*pos*/  4330, -2863, -5618, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFallingPillar),
    OBJECT(/*model*/ MODEL_JRB_FALLING_PILLAR_BASE,  /*pos*/  2078, -2966, -4696, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvPillarBase),
    OBJECT(/*model*/ MODEL_JRB_FALLING_PILLAR_BASE,  /*pos*/ -1403, -2966, -4696, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvPillarBase),
    OBJECT(/*model*/ MODEL_JRB_FALLING_PILLAR_BASE,  /*pos*/ -1096, -2966, -3262, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvPillarBase),
    OBJECT(/*model*/ MODEL_JRB_FALLING_PILLAR_BASE,  /*pos*/   337, -2966, -5106, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvPillarBase),
    OBJECT(/*model*/ MODEL_JRB_FALLING_PILLAR_BASE,  /*pos*/  2078, -2966, -6232, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvPillarBase),
    OBJECT(/*model*/ MODEL_JRB_FALLING_PILLAR_BASE,  /*pos*/  4330, -2966, -5618, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvPillarBase),
    OBJECT(/*model*/ MODEL_JRB_FLOATING_PLATFORM,    /*pos*/ -1059,  1025,  7072, /*angle*/ 0, 247, 0, /*behParam*/ 0x00000000, /*beh*/ bhvJrbFloatingPlatform),
    RETURN(),
};

static const LevelScript script_jrb_area_1_objects_3[] = {
    OBJECT_WITH_ACTS(/*model*/ MODEL_NONE,            /*pos*/ 4900,  2400,   800, /*angle*/ 0, 0, 0, /*behParam*/ 0x03000000, /*beh*/ bhvHiddenRedCoinStar, /*acts*/ ALL_ACTS),
#if defined(VERSION_JP) || defined(VERSION_SH)
    OBJECT_WITH_ACTS(/*model*/ MODEL_STAR,            /*pos*/ 1540,  2160,  2130, /*angle*/ 0, 0, 0, /*behParam*/ 0x04000000, /*beh*/ bhvStar,                 /*acts*/ ALL_ACTS),
#else
    OBJECT_WITH_ACTS(/*model*/ MODEL_EXCLAMATION_BOX, /*pos*/ 1540,  2160,  2130, /*angle*/ 0, 0, 0, /*behParam*/ 0x04080000, /*beh*/ bhvExclamationBox,      /*acts*/ ALL_ACTS),
#endif
    OBJECT_WITH_ACTS(/*model*/ MODEL_STAR,            /*pos*/ 5000, -4800,  2500, /*angle*/ 0, 0, 0, /*behParam*/ 0x05000000, /*beh*/ bhvStar,                 /*acts*/ ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
    RETURN(),
};

static const LevelScript script_jrb_area_2_objects_1[] = {
    OBJECT(/*model*/ MODEL_NONE,            /*pos*/  400,  -350, -2700, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvTreasureChestsShip),
    RETURN(),
};

const LevelScript level_jrb_entry[] = {
    INIT_LEVEL(),
#include "levels/jrb/areas/script_vanilla_load.inc.c"
    ALLOC_LEVEL_POOL(),
    MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
#include "levels/jrb/areas/script_vanilla.inc.c"

    AREA(/*index*/ 1, jrb_geo_000A18),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ -6750, 2126, 1482, /*angle*/ 0, 90, 0, /*behParam*/ 0x000A0000, /*beh*/ bhvSpinAirborneWarp),
        WARP_NODE(/*id*/ 0x0A, /*destLevel*/ LEVEL_JRB, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF3, /*destLevel*/ LEVEL_JRB, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF0, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x01, /*destNode*/ 0x35, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF1, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x01, /*destNode*/ 0x67, /*flags*/ WARP_NO_CHECKPOINT),
        WHIRLPOOL(/*index*/ 0, /*acts*/ ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6, /*pos*/ 4979, -5222, 2482, /*strength*/ -30),
        JUMP_LINK(script_jrb_area_1_objects_1),
        JUMP_LINK(script_jrb_area_1_objects_2),
        JUMP_LINK(script_jrb_area_1_objects_3),
        TERRAIN(/*terrainData*/ jrb_seg7_area_1_collision),
        JUMP_LINK(script_jrb_area_1_macro_objects),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0003, /*seq*/ SEQ_LEVEL_WATER),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_WATER),
    END_AREA(),

    AREA(/*index*/ 2, jrb_geo_000AFC),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ 928, 1050, -1248, /*angle*/ 0, 180, 0, /*behParam*/ 0x000A0000, /*beh*/ bhvSwimmingWarp),
        WARP_NODE(/*id*/ 0x0A, /*destLevel*/ LEVEL_JRB, /*destArea*/ 0x02, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF0, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x01, /*destNode*/ 0x35, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF1, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x01, /*destNode*/ 0x67, /*flags*/ WARP_NO_CHECKPOINT),
        JUMP_LINK(script_jrb_area_2_objects_1),
        TERRAIN(/*terrainData*/ jrb_seg7_area_2_collision),
        JUMP_LINK(script_jrb_area_2_macro_objects),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0003, /*seq*/ SEQ_LEVEL_WATER),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_WATER),
    END_AREA(),

    FREE_LEVEL_POOL(),
    MARIO_POS(/*area*/ 1, /*yaw*/ 90, /*pos*/ -6750, 1126, 1482),
    CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
    CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(/*frames*/ 1),
    EXIT(),
};
