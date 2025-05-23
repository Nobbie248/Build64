#ifndef BUFFERS_H
#define BUFFERS_H

#include <PR/ultratypes.h>
#include <hvqm2dec.h>

#include "game/save_file.h"
#include "game/game_init.h"
#include "game/main.h"
#include "config.h"
#include "audio/data.h"

extern u8 gAudioHeap[DOUBLE_SIZE_ON_64_BIT(AUDIO_HEAP_SIZE)];

extern u8 gIdleThreadStack[THREAD1_STACK] __attribute__((section(".bss.gIdleThreadStack")));
extern u8 gThread3Stack[THREAD3_STACK] __attribute__((section(".bss.gThread3Stack")));
extern u8 gThread4Stack[THREAD4_STACK] __attribute__((section(".bss.gThread4Stack")));
extern u8 gThread5Stack[THREAD5_STACK] __attribute__((section(".bss.gThread5Stack")));
#if ENABLE_RUMBLE
extern u8 gThread6Stack[THREAD6_STACK] __attribute__((section(".bss.gThread6Stack")));
#endif

extern u8 gGfxSPTaskYieldBuffer[];

extern struct SaveBuffer gSaveBuffer __attribute__((section(".bss.gSaveBuffer")));

extern u8 gGfxSPTaskStack[];

extern struct GfxPool gGfxPools[2];

extern u8 adpcmbuf[];		/* Buffer for audio records ADPCM) */

extern u64 hvq_yieldbuf[];	/* RSP task yield buffer */
extern HVQM2Info hvq_spfifo[];	/* Data area for HVQM2 microcode */
extern u16 hvqwork[];		/* Work buffer for HVQM2 decoder */
extern u8 hvqbuf[];		/* Buffer for video records (HVQM2) */

#endif // BUFFERS_H
