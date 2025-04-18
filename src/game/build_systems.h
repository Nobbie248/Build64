#ifndef BUILD_SYSTEMS_H
#define BUILD_SYSTEMS_H

#include <PR/ultratypes.h>

#define GRID_SIZE 300
#define GRID_MAP_SIZE 64

#define MAX_SAVED_BLOCKS 70

struct PlacedBlock {
    u8 type;
    s16 yaw;
};

extern struct PlacedBlock gPlacedObjectGridMap[GRID_MAP_SIZE][GRID_MAP_SIZE][GRID_MAP_SIZE];

#endif // BUILD_SYSTEMS_H
