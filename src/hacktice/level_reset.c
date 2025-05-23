#include "level_reset.h"

#include "binary.h"
#include "types.h"
#include "game/camera.h"
#include "game/level_update.h"
#include "game/envfx_snow.h"
#include "object_constants.h"
#include "libc/stddef.h"

#include "cfg.h"
#include "timer.h"

static bool sTimerRunningDeferred = false;
static u32 sReloadObjectsAreasMask = 0;
static u32 sReloadObjectsFrame = 0;
extern u8 sTransitionFadeTimer;

#define container_of(ptr, type, member) ({ \
                const typeof( ((type *)0)->member ) *__mptr = (ptr); \
                (type *)( (char *)__mptr - offsetof(type,member) );})

static void resetCamera()
{
    struct MarioState* m = gMarioStates;
    if (CAMERA_MODE_BEHIND_MARIO  == gCamera->mode
     || CAMERA_MODE_WATER_SURFACE == gCamera->mode
     || CAMERA_MODE_INSIDE_CANNON == gCamera->mode
     || CAMERA_MODE_CLOSE         == gCamera->mode
     || CAMERA_MODE_C_UP          == gCamera->mode)
    {
        set_camera_mode(m->area->camera, m->area->camera->defMode, 1);
    }
    
    m->area->camera->cutscene = 0;
}

static void resetTransition()
{
    sTransitionFadeTimer = 0;
}

extern u8 g100CoinStarSpawned;
extern s8  gRedCoinsCollected;

static void miniResetCommon()
{
    g100CoinStarSpawned = FALSE;
    gRedCoinsCollected = 0;
    gMarioStates->health = 0x880;
    gHudDisplay.coins = 0;
    gMarioStates->numCoins = 0;
    gSnowParticleCount = 5;
    gHudDisplay.timer = 0;
    sTimerRunning = true;
    Timer_reset();
    sWarpDest.type = 2;
    resetCamera();
    resetTransition();
}

static void resetCommon()
{
    miniResetCommon();
    sTimerRunningDeferred = true;
    sReloadObjectsAreasMask = ~0;
}

void LevelReset_onNormal()
{
    if (sTimerRunningDeferred)
    {
        sTimerRunningDeferred = false;
        miniResetCommon();
    }

    Config_ButtonAction action = Config_action();
    if (Config_ButtonAction_LEVEL_RESET == action)
    {
        resetCommon();
    }
    
    if (Config_ButtonAction_LEVEL_RESET_WARP == action)
    {
        sWarpDest.areaIdx = 1;
        sWarpDest.nodeId = 0xa;
        resetCommon();
    }

    if (Config_ButtonAction_ACT_SELECT == action)
    {
        sWarpDest.type = 2;
        sWarpDest.areaIdx = 1;
        sWarpDest.nodeId = 0xa;
        gMarioStates->health = 0x880;
        sCurrPlayMode = 0x4;
        gHudDisplay.timer = 0;
        sTimerRunning = true;
        sTimerRunningDeferred = true;
        sReloadObjectsAreasMask = ~0;
    }

    LevelConv_PlainLevels warp = Config_warpIdAndReset();
    if (warp != LevelConv_PlainLevels_OFF)
    {
        LevelConv_SM64Levels sm64lvl = LevelConv_toSM64Level(warp);
        
        sWarpDest.levelNum = (u8) sm64lvl;
        sWarpDest.type = 2;
        sWarpDest.areaIdx = 1;
        sWarpDest.nodeId = 0xa;
        gMarioStates->health = 0x880;
        sCurrPlayMode = 0x4;
        gHudDisplay.timer = 0;
        sTimerRunning = true;
        sTimerRunningDeferred = true;
        sReloadObjectsAreasMask = ~0;
        Timer_reset();
        resetCamera();
    }
}

static inline bool isScroll(struct SpawnInfo* spawnInfo)
{
    (void) spawnInfo;

#ifdef BINARY
    // TODO: This is very hacky, do a more careful check
    if (spawnInfo->behaviorScript == (void*) 0x401700)
        return true;
#endif

    return false;
}

s32 LevelReset_onSpawnObjectsFromInfoHook(struct SpawnInfo* spawnInfo)
{
    u32 areaMask = 1 << gCurrAreaIndex;
    if (((sReloadObjectsAreasMask & areaMask) || sReloadObjectsFrame == gGlobalTimer) && !isScroll(spawnInfo))
    {
        sReloadObjectsFrame = gGlobalTimer;
        sReloadObjectsAreasMask &= ~areaMask;

#ifndef BINARY
        spawnInfo->respawnInfo = RESPAWN_INFO_NONE;
#endif

        spawnInfo->behaviorArg &= ~(RESPAWN_INFO_DONT_RESPAWN << 8);
        return true;
    }

#ifndef BINARY
    return (spawnInfo->respawnInfo & RESPAWN_INFO_DONT_RESPAWN) != RESPAWN_INFO_DONT_RESPAWN;
#else
    return (spawnInfo->behaviorArg & (RESPAWN_INFO_DONT_RESPAWN << 8)) != (RESPAWN_INFO_DONT_RESPAWN << 8);
#endif
}

#ifdef BINARY
void LevelReset_setObjectRespawnInfoBits(struct Object *obj, u8 bits) 
{
    switch (obj->respawnInfoType) 
    {
        case RESPAWN_INFO_TYPE_32:
        {
            u32* info32 = (u32 *) obj->respawnInfo;
            struct SpawnInfo* spawnInfo = container_of(info32, struct SpawnInfo, behaviorArg);
            if (!isScroll(spawnInfo))
            {
                *info32 |= bits << 8;
            }
        }
        break;

        case RESPAWN_INFO_TYPE_16:
        {
            u16* info16 = (u16 *) obj->respawnInfo;
            *info16 |= bits << 8;
        }
        break;
    }
}
#endif
