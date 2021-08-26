OUTPUT_ARCH (mips)

#define BEGIN_SEG(name, addr) \
    _##name##SegmentStart = ADDR(.name); \
    _##name##SegmentRomStart = __romPos; \
    .name addr : AT(__romPos)

#define END_SEG(name) \
    _##name##SegmentEnd = ADDR(.name) + SIZEOF(.name); \
    _##name##SegmentRomEnd = __romPos + SIZEOF(.name); \
    _##name##SegmentSize = _##name##SegmentEnd - _##name##SegmentStart; \
    __romPos += SIZEOF(.name);

#define BEGIN_NOLOAD(name) \
    _##name##SegmentNoloadStart = ADDR(.name.noload); \
    .name.noload (NOLOAD) :

#define END_NOLOAD(name) \
    _##name##SegmentNoloadEnd = ADDR(.name.noload) + SIZEOF(.name.noload);

#define PATCH(segment, symbol, offset) \
    .segment##symbol##offset##_patch symbol + offset : AT(_##segment##SegmentRomStart + symbol - _##segment##SegmentStart + offset)
    
#define CODE_PATCH(segment, symbol, offset) \
    .segment##symbol##offset##_patch symbol + offset : AT(code_##segment##_ROM_START + symbol - code_##segment##_VRAM + offset)

#define JAL_HOOK(segment, symbol, offset, helper, name) \
    .segment##symbol##offset##_patch symbol + offset : AT(code_##segment##_ROM_START + symbol - code_##segment##_VRAM + offset) \
    { \
        name = .; \
        BYTE(0x0C); \
        BYTE((helper >> 18) & 0xFF); \
        BYTE((helper >> 10) & 0xFF); \
        BYTE((helper >> 2)  & 0xFF); \
    }
    
#define ROM_PATCH(address) \
    .rom##address##_patch : AT(address)

SECTIONS
{
    __romPos = 0;

    BEGIN_SEG(baserom, 0)
    {
        BASEROM;
    }
    END_SEG(baserom)
    baseromEnd = __romPos;
    extRamStart = 0xFFFFFFFF800E8E58;
    . = extRamStart;

    ROM_PATCH(0x001E6C)
    {
        BUILD_DIR/src/patches/dma_hook.o(.text);
    }
    ROM_PATCH(0xE9A60)
    {
        BUILD_DIR/src/patches/dma.o(.text);
        BUILD_DIR/src/patches/dma.o(.*data*);
    }
    /* replace object display with custom update */
    ROM_PATCH(0x10C544)
    {
        BUILD_DIR/src/patches/obj_display_hook.o(.text);
    }
    /* replace object update with custom update */
    ROM_PATCH(0x10CB58)
    {
        BUILD_DIR/src/patches/obj_update_hook.o(.text);
    }

    /*
    ROM_PATCH(0x02B428)
    {
        BUILD_DIR/src/patches/boost_hook.o(.text);
    }
    */

    . = 0xFFFFFFFF80400000;
    BEGIN_SEG(object, .)
    {
        BUILD_DIR/src/custom/update_objects.o(.text);
        BUILD_DIR/src/custom/update_objects.o(.*data*);
    }
    END_SEG(object)

    /* Discard everything not specifically mentioned above. */
    /DISCARD/ :
    {
        *(*);
    }
}
