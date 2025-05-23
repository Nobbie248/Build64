#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "macros.h"
#include "surface_terrains.h"
#include "types.h"
#include "make_const_nonconst.h"
#include "common1.h"

#include "mist/model.inc.c"
UNUSED static const u64 binid_0 = 0;

#include "explosion/model.inc.c"
UNUSED static const u64 binid_1 = 1;

#include "butterfly/model.inc.c"
#include "butterfly/anims/data.inc.c"
#include "butterfly/anims/table.inc.c"
UNUSED static const u64 binid_2 = 2;

#include "coin/model.inc.c"
UNUSED static const u64 binid_3 = 3;

#include "warp_pipe/model.inc.c"
#include "warp_pipe/collision.inc.c"
UNUSED static const u64 binid_4 = 4;

#include "door/model.inc.c"
#include "door/anims/data.inc.c"
#include "door/anims/table.inc.c"
#include "door/collision.inc.c"
UNUSED static const u64 binid_5 = 5;

#include "bowser_key/model.inc.c"
#include "bowser_key/anims/data.inc.c"
#include "bowser_key/anims/table.inc.c"
UNUSED static const u64 binid_6 = 6;

#include "flame/model.inc.c"
UNUSED static const u64 binid_7 = 7;

#include "blue_fish/model.inc.c"
#include "blue_fish/anims/data.inc.c"
#include "blue_fish/anims/table.inc.c"
UNUSED static const u64 binid_8 = 8;

#include "pebble/model.inc.c"
UNUSED static const u64 binid_9 = 9;

#include "leaves/model.inc.c"
UNUSED static const u64 binid_10 = 10;

UNUSED static const u64 binid_11 = 11;

#include "mario_cap/model.inc.c"
UNUSED static const u64 binid_12 = 12;

#include "power_meter/model.inc.c"
#ifdef BREATH_METER
#include "breath_meter/model.inc.c"
#endif
UNUSED static const u64 binid_13 = 13;

UNUSED static const u64 binid_14 = 14;

#include "mushroom_1up/model.inc.c"
UNUSED static const u64 binid_15 = 15;

#include "star/model.inc.c"
UNUSED static const u64 binid_16 = 16;

#include "sand/model.inc.c"
UNUSED static const u64 binid_17 = 17;

#include "dirt/model.inc.c"
UNUSED static const u64 binid_18 = 18;

#include "transparent_star/model.inc.c"
UNUSED static const u64 binid_19 = 19;

#include "white_particle/model.inc.c"
UNUSED static const u64 binid_20 = 20;

#include "wooden_signpost/model.inc.c"
#include "wooden_signpost/collision.inc.c"
UNUSED static const u64 binid_21 = 21;

#include "tree/model.inc.c"
UNUSED static const u64 binid_22 = 22;
#include "marker/collision.inc.c"
#include "marker/model.inc.c"
#include "block/collision.inc.c"
#include "block/model.inc.c"
#include "hotbar/model.inc.c"
#include "block2/collision.inc.c"
#include "block2/model.inc.c"
#include "marker2/collision.inc.c"
#include "marker2/model.inc.c"
#include "hotbar2/model.inc.c"
#include "hotbar3/model.inc.c"
#include "hotbar4/model.inc.c"
#include "hotbar5/model.inc.c"
#include "hotbar6/model.inc.c"
#include "hotbar7/model.inc.c"
#include "hotbar8/model.inc.c"
#include "hotbar9/model.inc.c"
#include "hotbar10/model.inc.c"
#include "hotbarinside/model.inc.c"

#include "block3/collision.inc.c"
#include "block3/model.inc.c"
#include "marker3/collision.inc.c"
#include "marker3/model.inc.c"
#include "block4/collision.inc.c"
#include "block4/model.inc.c"
#include "marker4/collision.inc.c"
#include "marker4/model.inc.c"
#include "block5/collision.inc.c"
#include "block5/model.inc.c"
#include "marker5/collision.inc.c"
#include "marker5/model.inc.c"
#include "block6/collision.inc.c"
#include "block6/model.inc.c"
#include "marker6/collision.inc.c"
#include "marker6/model.inc.c"
#include "block7/collision.inc.c"
#include "block7/model.inc.c"
#include "marker7/collision.inc.c"
#include "marker7/model.inc.c"
#include "marker8/collision.inc.c"
#include "marker8/model.inc.c"
#include "block8/collision.inc.c"
#include "block8/model.inc.c"
#include "block9/collision.inc.c"
#include "block9/model.inc.c"
#include "marker9/collision.inc.c"
#include "marker9/model.inc.c"
#include "marker10/collision.inc.c"
#include "marker10/model.inc.c"
#include "block10/collision.inc.c"
#include "block10/model.inc.c"
#include "block11/collision.inc.c"
#include "block11/model.inc.c"
#include "block12/collision.inc.c"
#include "block12/model.inc.c"
#include "block13/collision.inc.c"
#include "block13/model.inc.c"
#include "block14/collision.inc.c"
#include "block14/model.inc.c"
#include "block15/collision.inc.c"
#include "block15/model.inc.c"
#include "block16/collision.inc.c"
#include "block16/model.inc.c"
#include "block17/collision.inc.c"
#include "block17/model.inc.c"
#include "block18/collision.inc.c"
#include "block18/model.inc.c"
#include "block19/collision.inc.c"
#include "block19/model.inc.c"
#include "block20/collision.inc.c"
#include "block20/model.inc.c"
#include "marker11/collision.inc.c"
#include "marker11/model.inc.c"
#include "marker12/collision.inc.c"
#include "marker12/model.inc.c"
#include "marker13/collision.inc.c"
#include "marker13/model.inc.c"
#include "marker14/collision.inc.c"
#include "marker14/model.inc.c"
#include "marker15/collision.inc.c"
#include "marker15/model.inc.c"
#include "marker16/collision.inc.c"
#include "marker16/model.inc.c"
#include "marker17/collision.inc.c"
#include "marker17/model.inc.c"
#include "marker18/collision.inc.c"
#include "marker18/model.inc.c"
#include "marker19/collision.inc.c"
#include "marker19/model.inc.c"
#include "marker20/collision.inc.c"
#include "marker20/model.inc.c"