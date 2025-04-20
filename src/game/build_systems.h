#ifndef BUILD_SYSTEMS_H
#define BUILD_SYSTEMS_H

#include <PR/ultratypes.h>

// this setup uses up to 32kb of ram while keeping things persistent over the game
// saving to sram is possible but this will come later
#define GRID_SIZE 300 // size of each block placement
#define GRID_MAP_SIZE 64 // total size of grid in each stage
#define MAX_LEVELS 32 // do not put less then 31 or it can crash
#define MAX_PLACED_BLOCKS_PER_LEVEL 256 
#define MARKER_TYPE_COUNT 10 // preview object models
#define BLOCK_TYPE_COUNT 10 // types of objects to place

struct PlacedBlockInstance {
    u32 x:6 , y: 6, z: 6,
    type: 5, yaw: 2;
};

extern struct PlacedBlockInstance gPlacedBlocks[MAX_LEVELS][MAX_PLACED_BLOCKS_PER_LEVEL];
extern u16 gPlacedBlockCounts[MAX_LEVELS];

extern u8 gIsHotbar;
extern u8 gIsBlockType[BLOCK_TYPE_COUNT];

#endif // BUILD_SYSTEMS_H
