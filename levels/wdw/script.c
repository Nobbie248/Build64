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
#include "levels/wdw/header.h"


static const LevelScript script_wdw_area_1_macro_objects[] = {
    // Macro objects
    OBJECT(/*model*/ MODEL_WOODEN_SIGNPOST,  /*pos*/ -2077,  2816,  -660, /*angle*/ 0,   0, 0, /*behParam*/ (DIALOG_081 << 16), /*beh*/ bhvMessagePanel),
    OBJECT(/*model*/ MODEL_BOBOMB_BUDDY,     /*pos*/    -2,  3200,  3583, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvBobombBuddyOpensCannon),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/ -2057,  2800,  -500, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_RING) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/  1500,  1741,  2191, /*angle*/ 0,  90, 0, /*behParam*/ ((COIN_FORMATION_FLAG_NONE) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_BLUE_COIN_SWITCH, /*pos*/   500,   384,   250, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvBlueCoinSwitch),
    OBJECT(/*model*/ MODEL_BLUE_COIN,        /*pos*/  1124,   400,  -218, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_BLUE_COIN,        /*pos*/  1124,   400,   830, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_BLUE_COIN,        /*pos*/   832,   400,  1194, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_BLUE_COIN,        /*pos*/  1124,   400,   282, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,  /*pos*/ -2200,  2600,  3500, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_STAR_1 << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_AMP,              /*pos*/ -1360,  3880, -1340, /*angle*/ 0,   0, 0, /*behParam*/ (2 << 16), /*beh*/ bhvCirclingAmp),
    OBJECT(/*model*/ MODEL_AMP,              /*pos*/   640,   700,  3720, /*angle*/ 0,   0, 0, /*behParam*/ (2 << 16), /*beh*/ bhvCirclingAmp),
    OBJECT(/*model*/ MODEL_AMP,              /*pos*/ -2100,  2400,  -500, /*angle*/ 0,   0, 0, /*behParam*/ (2 << 16), /*beh*/ bhvCirclingAmp),
    OBJECT(/*model*/ MODEL_HEAVE_HO,         /*pos*/ -2656,  2300, -1352, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHeaveHo),
    OBJECT(/*model*/ MODEL_HEAVE_HO,         /*pos*/ -2909,  1140,   442, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHeaveHo),
    OBJECT(/*model*/ MODEL_DL_CANNON_LID,    /*pos*/ -2688,  3328,  3198, /*angle*/ 0,   0, 0, /*behParam*/ (0x40 << 16), /*beh*/ bhvCannonClosed),
    OBJECT(/*model*/ MODEL_METAL_BOX,        /*pos*/ -2200,   384,  1145, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvPushableMetalBox),
    OBJECT(/*model*/ MODEL_1UP,              /*pos*/ -1129,  3857,  1404, /*angle*/ 0,   0, 0, /*behParam*/ (MUSHROOM_BP_REQUIRES_NONE << 16), /*beh*/ bhv1Up),
    OBJECT(/*model*/ MODEL_1UP,              /*pos*/  -882,  4018,  1164, /*angle*/ 0,   0, 0, /*behParam*/ (MUSHROOM_BP_REQUIRES_NONE << 16), /*beh*/ bhv1Up),
    OBJECT(/*model*/ MODEL_CHUCKYA,          /*pos*/ -2963,  3840, -3063, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvChuckya),
    OBJECT(/*model*/ MODEL_HEAVE_HO,         /*pos*/ -3040,   384,  1840, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHeaveHo),
    OBJECT(/*model*/ MODEL_METAL_BOX,        /*pos*/ -1843,  2304, -3694, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvPushableMetalBox),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/   943,  3830, -1779, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenStarTrigger),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/ -2200,   384,  1145, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenStarTrigger),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/ -2075,  3000,  -524, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenStarTrigger),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/ -3760,   650,  4120, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenStarTrigger),
    OBJECT(/*model*/ MODEL_AMP,              /*pos*/  -827,  3880,  -827, /*angle*/ 0,   0, 0, /*behParam*/ (2 << 16), /*beh*/ bhvCirclingAmp),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/  1360,   205, -1384, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_PURPLE_SWITCH,    /*pos*/   920,  2300,  -840, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFloorSwitchHiddenObjects),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/   470,  2300, -1310, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/   470,  2500, -1510, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/   470,  2700, -1710, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/   470,  2900, -1910, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/   470,  3100, -2110, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_BOWLING_BALL,     /*pos*/  3140,  1300,  2040, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFireSpitter),
    OBJECT(/*model*/ MODEL_BOWLING_BALL,     /*pos*/   -20,   400,  1520, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFireSpitter),
    OBJECT(/*model*/ MODEL_BOWLING_BALL,     /*pos*/ -1780,  1160,   -40, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFireSpitter),
    OBJECT(/*model*/ MODEL_BOWLING_BALL,     /*pos*/ -2280,  2320, -2280, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFireSpitter),
    OBJECT(/*model*/ MODEL_BOWLING_BALL,     /*pos*/  1240,  2340, -3300, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFireSpitter),
    OBJECT(/*model*/ MODEL_BOWLING_BALL,     /*pos*/ -2240,  2320,  3820, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFireSpitter),
    OBJECT(/*model*/ MODEL_BOWLING_BALL,     /*pos*/  -220,  3860,    60, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFireSpitter),
    OBJECT(/*model*/ MODEL_BOWLING_BALL,     /*pos*/  -240,   400,  -440, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFireSpitter),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/  4509,     0,  3069, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_3_COINS << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/  4509,     0,  2873, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_3_COINS << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_METAL_BOX,        /*pos*/ -3689,     0,  3205, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvPushableMetalBox),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/   470,  3100, -2310, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/ -3093,   300,  3300, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_LARGE   << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_AMP,              /*pos*/ -1500,  2360,  3120, /*angle*/ 0,   0, 0, /*behParam*/ (2 << 16), /*beh*/ bhvCirclingAmp),
    OBJECT(/*model*/ MODEL_BLUE_COIN,        /*pos*/   420,   400,  1504, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_BLUE_COIN,        /*pos*/   -12,   400,  1808, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenBlueCoin),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,  /*pos*/ -2075,  3050,  -524, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_COINS_10 << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,  /*pos*/   943,  3880, -1779, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_COINS_10 << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/ -3689,     0,  3205, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHiddenStarTrigger),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/  4500,     0,  1240, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_3_COINS << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,  /*pos*/ -2200,  3060, -3700, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_COINS_3  << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,  /*pos*/ -3760,   700,  4120, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_COINS_10 << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,  /*pos*/  3388,  1600,  1155, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_COINS_3  << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_NONE,             /*pos*/   740,  3072, -3560, /*angle*/ 0,  90, 0, /*behParam*/ ((COIN_FORMATION_FLAG_NONE) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX,  /*pos*/  1550,  4350,   100, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_STAR_2   << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_WOODEN_SIGNPOST,  /*pos*/   740,  3060, -3680, /*angle*/ 0,   0, 0, /*behParam*/ (DIALOG_053 << 16), /*beh*/ bhvMessagePanel),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,    /*pos*/  4500,     0,  1040, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_3_COINS << 16), /*beh*/ bhvBreakableBox),
    RETURN(),
};

static const LevelScript script_wdw_area_2_macro_objects[] = {
    // Macro objects
    OBJECT(/*model*/ MODEL_RED_COIN,        /*pos*/ -3720, -1131,   520, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,        /*pos*/ -2930,  -850,  2560, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,        /*pos*/   100, -1771, -1500, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,        /*pos*/  1820, -1387,  1020, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,        /*pos*/  -370, -1795,  -180, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,        /*pos*/ -1180, -1795,  -180, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,        /*pos*/  -780, -2155,  2860, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_RED_COIN,        /*pos*/  -780, -1020,  3400, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvRedCoin),
    OBJECT(/*model*/ MODEL_NONE,            /*pos*/  -772, -2320,   772, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_RING) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_NONE,            /*pos*/  -524, -2560,   524, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHidden1upTrigger),
    OBJECT(/*model*/ MODEL_NONE,            /*pos*/ -1034, -2560,   524, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHidden1upTrigger),
    OBJECT(/*model*/ MODEL_NONE,            /*pos*/ -1034, -2560,  1034, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHidden1upTrigger),
    OBJECT(/*model*/ MODEL_NONE,            /*pos*/  -524, -2560,  1034, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvHidden1upTrigger),
    OBJECT(/*model*/ MODEL_1UP,             /*pos*/  -772, -2180,   772, /*angle*/ 0,   0, 0, /*behParam*/ (4 << 16), /*beh*/ bhvHidden1up),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,   /*pos*/  -870,  -300,   870, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,   /*pos*/  -670,  -300,   870, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,   /*pos*/  -670,  -300,   670, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,   /*pos*/  -870,  -300,   670, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX, /*pos*/  -770,    80,   770, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_METAL_CAP        << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX, /*pos*/ -1779, -2240,  3644, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_VANISH_CAP       << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_NONE,            /*pos*/  1089, -1279,   968, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_NONE                             ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_SKEETER,         /*pos*/ -1240,  -520,   540, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSkeeter),
    OBJECT(/*model*/ MODEL_SKEETER,         /*pos*/  -260,  -620,  1560, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSkeeter),
    OBJECT(/*model*/ MODEL_PURPLE_SWITCH,   /*pos*/ -1520, -2516, -1940, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFloorSwitchHiddenObjects),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,   /*pos*/  2200, -2559,  3240, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_NO_COINS << 16), /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX, /*pos*/  1300, -2260,  3740, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_VANISH_CAP       << 16), /*beh*/ bhvExclamationBox),
    OBJECT(/*model*/ MODEL_BOWLING_BALL,    /*pos*/ -2060, -1580, -1260, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFireSpitter),
    OBJECT(/*model*/ MODEL_BOWLING_BALL,    /*pos*/  2240, -1420,  2140, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFireSpitter),
    OBJECT(/*model*/ MODEL_BOWLING_BALL,    /*pos*/  2280, -1400,  -100, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFireSpitter),
    OBJECT(/*model*/ MODEL_BOWLING_BALL,    /*pos*/ -2280, -2520,  -740, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFireSpitter),
    OBJECT(/*model*/ MODEL_BOWLING_BALL,    /*pos*/   720, -2520,  -740, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFireSpitter),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,   /*pos*/ -2930, -1000,  2560, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_LARGE    << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,   /*pos*/ -3690, -1151,   520, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_LARGE    << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,   /*pos*/ -1180, -1945,  -180, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_LARGE    << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,   /*pos*/  -370, -1945,  -180, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_LARGE    << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,   /*pos*/   100, -1791, -1500, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_LARGE    << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,   /*pos*/  1820, -1407,  1020, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_LARGE    << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_BREAKABLE_BOX,   /*pos*/  -780, -2175,  2810, /*angle*/ 0,   0, 0, /*behParam*/ (BREAKABLE_BOX_BP_LARGE    << 16), /*beh*/ bhvBreakableBox),
    OBJECT(/*model*/ MODEL_NONE,            /*pos*/   100, -1791, -2100, /*angle*/ 0,  90, 0, /*behParam*/ ((COIN_FORMATION_FLAG_NONE                             ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_NONE,            /*pos*/  -770,  -320,  2820, /*angle*/ 0,   0, 0, /*behParam*/ ((COIN_FORMATION_FLAG_NONE                             ) << 16), /*beh*/ bhvCoinFormation),
    OBJECT(/*model*/ MODEL_EXCLAMATION_BOX, /*pos*/  1655, -2160, -1293, /*angle*/ 0,   0, 0, /*behParam*/ (EXCLAMATION_BOX_BP_1UP_RUNNING_AWAY << 16), /*beh*/ bhvExclamationBox),
    // Special objects
    OBJECT(/*model*/ MODEL_BOB_BUBBLY_TREE, /*pos*/  1664, -2457,  -946, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvTree),
    OBJECT(/*model*/ MODEL_BOB_BUBBLY_TREE, /*pos*/  1664, -2457, -1637, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvTree),
    RETURN(),
};

static const LevelScript script_wdw_area_1_objects_1[] = {
    OBJECT(/*model*/ MODEL_WDW_SQUARE_FLOATING_PLATFORM,      /*pos*/  3390,    0,   384, /*angle*/ 0, 180, 0, /*behParam*/ 0x00000000, /*beh*/ bhvWdwSquareFloatingPlatform),
    OBJECT(/*model*/ MODEL_WDW_SQUARE_FLOATING_PLATFORM,      /*pos*/  -767,  384,  3584, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvWdwSquareFloatingPlatform),
    OBJECT(/*model*/ MODEL_WDW_SQUARE_FLOATING_PLATFORM,      /*pos*/  -767,  384,  1536, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvWdwSquareFloatingPlatform),
    OBJECT(/*model*/ MODEL_WDW_SQUARE_FLOATING_PLATFORM,      /*pos*/  -767, 2304, -1279, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvWdwSquareFloatingPlatform),
    OBJECT(/*model*/ MODEL_WDW_ARROW_LIFT,                    /*pos*/  -578, 2177,  3009, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvArrowLift),
    OBJECT(/*model*/ MODEL_WDW_ARROW_LIFT,                    /*pos*/ -1474, 2177,  3393, /*angle*/ 0, 270, 0, /*behParam*/ 0x00000000, /*beh*/ bhvArrowLift),
    OBJECT(/*model*/ MODEL_WDW_ARROW_LIFT,                    /*pos*/ -1602, 2177,  3009, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvArrowLift),
    OBJECT(/*model*/ MODEL_WDW_ARROW_LIFT,                    /*pos*/ -1090, 2177,  3521, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvArrowLift),
    OBJECT(/*model*/ MODEL_WDW_ARROW_LIFT,                    /*pos*/  -962, 2177,  3137, /*angle*/ 0,  90, 0, /*behParam*/ 0x00000000, /*beh*/ bhvArrowLift),
    OBJECT(/*model*/ MODEL_NONE,                              /*pos*/     0,    0,     0, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvInitializeChangingWaterLevel),
    OBJECT(/*model*/ MODEL_WDW_WATER_LEVEL_DIAMOND,           /*pos*/  1920, 2560, -3583, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvWaterLevelDiamond),
    OBJECT(/*model*/ MODEL_WDW_WATER_LEVEL_DIAMOND,           /*pos*/  3328,  256,  2918, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvWaterLevelDiamond),
    OBJECT(/*model*/ MODEL_WDW_WATER_LEVEL_DIAMOND,           /*pos*/  2048, 1792,  2176, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvWaterLevelDiamond),
    OBJECT(/*model*/ MODEL_WDW_WATER_LEVEL_DIAMOND,           /*pos*/   640, 1024,  3712, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvWaterLevelDiamond),
    OBJECT(/*model*/ MODEL_WDW_WATER_LEVEL_DIAMOND,           /*pos*/  1810,   40, -3118, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvWaterLevelDiamond),
    OBJECT(/*model*/ MODEL_PURPLE_SWITCH,                     /*pos*/  3360, 1280,  3420, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFloorSwitchHiddenObjects),
    OBJECT(/*model*/ MODEL_WDW_HIDDEN_PLATFORM,               /*pos*/  2239, 1126,  3391, /*angle*/ 0,   0, 0, /*behParam*/ 0x00010000, /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_WDW_HIDDEN_PLATFORM,               /*pos*/  1215, 1357,  2751, /*angle*/ 0,   0, 0, /*behParam*/ 0x00010000, /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_WDW_HIDDEN_PLATFORM,               /*pos*/  1215, 1229,  3391, /*angle*/ 0,   0, 0, /*behParam*/ 0x00010000, /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_WDW_HIDDEN_PLATFORM,               /*pos*/  1599, 1101,  3391, /*angle*/ 0,   0, 0, /*behParam*/ 0x00010000, /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_WDW_HIDDEN_PLATFORM,               /*pos*/  2879, 1152,  3391, /*angle*/ 0,   0, 0, /*behParam*/ 0x00010000, /*beh*/ bhvHiddenObject),
    OBJECT(/*model*/ MODEL_WDW_EXPRESS_ELEVATOR,              /*pos*/  1024, 3277, -2112, /*angle*/ 0,   0, 0, /*behParam*/ 0x00320000, /*beh*/ bhvWdwExpressElevatorPlatform),
    OBJECT(/*model*/ MODEL_WDW_EXPRESS_ELEVATOR,              /*pos*/  1024, 3277, -1663, /*angle*/ 0,   0, 0, /*behParam*/ 0x00320000, /*beh*/ bhvWdwExpressElevator),
    OBJECT(/*model*/ MODEL_WDW_RECTANGULAR_FLOATING_PLATFORM, /*pos*/  -767, 1152,   128, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvWdwRectangularFloatingPlatform),
    OBJECT(/*model*/ MODEL_WDW_RECTANGULAR_FLOATING_PLATFORM, /*pos*/  -767, 2304, -2687, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvWdwRectangularFloatingPlatform),
    OBJECT(/*model*/ MODEL_WDW_ROTATING_PLATFORM,             /*pos*/   734, 3840,    84, /*angle*/ 0,   0, 0, /*behParam*/ 0x46010000, /*beh*/ bhvRotatingPlatform),
    OBJECT(/*model*/ MODEL_SKEETER,                           /*pos*/  2956,  288,  -468, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSkeeter),
    OBJECT(/*model*/ MODEL_SKEETER,                           /*pos*/   184,  384,   621, /*angle*/ 0,   0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvSkeeter),
    RETURN(),
};

static const LevelScript script_wdw_area_2_objects_1[] = {
    OBJECT(/*model*/ MODEL_NONE,                    /*pos*/     0,     0,     0, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvInitializeChangingWaterLevel),
    OBJECT(/*model*/ MODEL_WDW_WATER_LEVEL_DIAMOND, /*pos*/ -3583, -2508, -2047, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvWaterLevelDiamond),
    OBJECT(/*model*/ MODEL_WDW_WATER_LEVEL_DIAMOND, /*pos*/  -767,  -127,  1792, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvWaterLevelDiamond),
    OBJECT(/*model*/ MODEL_NONE,                    /*pos*/  -768,  -665,  3584, /*angle*/ 0, 0, 0, /*behParam*/ 0x005C0000, /*beh*/ bhvPoleGrabbing),
    RETURN(),
};

static const LevelScript script_wdw_area_1_objects_2[] = {
    OBJECT_WITH_ACTS(/*model*/ MODEL_NONE, /*pos*/ 3360,  1580,  2660, /*angle*/ 0, 0, 0, /*behParam*/ 0x02000000, /*beh*/ bhvHiddenStar,          /*acts*/ ALL_ACTS),
    OBJECT_WITH_ACTS(/*model*/ MODEL_STAR, /*pos*/  890,  3400, -2040, /*angle*/ 0, 0, 0, /*behParam*/ 0x03000000, /*beh*/ bhvStar,                 /*acts*/ ALL_ACTS),
    RETURN(),
};

static const LevelScript script_wdw_area_2_objects_2[] = {
    OBJECT_WITH_ACTS(/*model*/ MODEL_NONE, /*pos*/ -770, -1600,  3600, /*angle*/ 0, 0, 0, /*behParam*/ 0x04000000, /*beh*/ bhvHiddenRedCoinStar, /*acts*/ ALL_ACTS),
    OBJECT_WITH_ACTS(/*model*/ MODEL_STAR, /*pos*/ 2180,  -840,  3720, /*angle*/ 0, 0, 0, /*behParam*/ 0x05000000, /*beh*/ bhvStar,                 /*acts*/ ALL_ACTS),
    RETURN(),
};

const LevelScript level_wdw_entry[] = {
    INIT_LEVEL(),
#include "levels/wdw/areas/script_vanilla_load.inc.c"
    ALLOC_LEVEL_POOL(),
    MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
#include "levels/wdw/areas/script_vanilla.inc.c"

    AREA(/*index*/ 1, wdw_geo_000658),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/  3395, 3580,  384, /*angle*/ 0, 180, 0, /*behParam*/ 0x000A0000, /*beh*/ bhvSpinAirborneWarp),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/   818,    0, 3634, /*angle*/ 0,  45, 0, /*behParam*/ 0x000B0000, /*beh*/ bhvFadingWarp),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ -2865, 3328, 3065, /*angle*/ 0,   0, 0, /*behParam*/ 0x000C0000, /*beh*/ bhvFadingWarp),
        WARP_NODE(/*id*/ 0x0A, /*destLevel*/ LEVEL_WDW, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x0B, /*destLevel*/ LEVEL_WDW, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x0C, /*destLevel*/ LEVEL_WDW, /*destArea*/ 0x01, /*destNode*/ 0x0B, /*flags*/ WARP_NO_CHECKPOINT),
        JUMP_LINK(script_wdw_area_1_objects_1),
        JUMP_LINK(script_wdw_area_1_objects_2),
        WARP_NODE(/*id*/ 0xF0, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x02, /*destNode*/ 0x32, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF1, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x02, /*destNode*/ 0x64, /*flags*/ WARP_NO_CHECKPOINT),
        INSTANT_WARP(/*index*/ 1, /*destArea*/ 2, /*displace*/ 0, 0, 0),
        TERRAIN(/*terrainData*/ wdw_seg7_area_1_collision),
        JUMP_LINK(script_wdw_area_1_macro_objects),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0003, /*seq*/ SEQ_LEVEL_UNDERGROUND),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_STONE),
    END_AREA(),

    AREA(/*index*/ 2, wdw_geo_000724),
        JUMP_LINK(script_wdw_area_2_objects_1),
        JUMP_LINK(script_wdw_area_2_objects_2),
        WARP_NODE(/*id*/ 0xF0, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x02, /*destNode*/ 0x32, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF1, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x02, /*destNode*/ 0x64, /*flags*/ WARP_NO_CHECKPOINT),
        INSTANT_WARP(/*index*/ 0, /*destArea*/ 1, /*displace*/ 0, 0, 0),
        TERRAIN(/*terrainData*/ wdw_seg7_area_2_collision),
        JUMP_LINK(script_wdw_area_2_macro_objects),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0003, /*seq*/ SEQ_LEVEL_UNDERGROUND),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_WATER),
    END_AREA(),

    FREE_LEVEL_POOL(),
    MARIO_POS(/*area*/ 1, /*yaw*/ 180, /*pos*/ 3395, 2580, 384),
    CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
    CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(/*frames*/ 1),
    EXIT(),
};
