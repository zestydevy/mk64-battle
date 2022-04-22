#include <ultra64.h>
#include "macros.h"

extern u8 _objectSegmentRomStart[];
extern u8 _objectSegmentRomEnd[];
extern u8 _objectSegmentStart[];

void func_800010CC(void);
void dma_copy(u32 dest, u32 src, u32 size);

void dmaCustomCode()
{
    osInvalDCache((void *)_objectSegmentStart, ALIGN16((_objectSegmentRomEnd - _objectSegmentRomStart)));
    osInvalICache((void *)_objectSegmentStart, ALIGN16((_objectSegmentRomEnd - _objectSegmentRomStart)));
    dma_copy((u32)_objectSegmentStart, (u32)_objectSegmentRomStart, ALIGN16((u32)(_objectSegmentRomEnd - _objectSegmentRomStart)));
    func_800010CC();
}