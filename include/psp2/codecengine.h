/**
 * \usergroup{SceCodecEngine}
 * \usage{psp2/codecengine.h,SceCodecEngine_stub}
 */

#ifndef _PSP2_CODECENGINE_H_
#define _PSP2_CODECENGINE_H_

#include <stdint.h>
#include <psp2/types.h>

#ifdef __cplusplus
extern "C" {
#endif

SceUID sceCodecEngineOpenUnmapMemBlock(void *addr, SceSize size);
int sceCodecEngineCloseUnmapMemBlock(SceUID uid);
uintptr_t sceCodecEngineAllocMemoryFromUnmapMemBlock(SceUID uid, SceSize size, SceSize align);
int sceCodecEngineFreeMemoryFromUnmapMemBlock(SceUID uid, uintptr_t addr);

#ifdef __cplusplus
}
#endif
#endif /* _PSP2_CODECENGINE_H_ */