#include "src/game/envfx_snow.h"

const GeoLayout block7_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, block7_block7_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, block7_block7_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
