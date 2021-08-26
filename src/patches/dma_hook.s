#include <macro.inc>
.set noat
.set noreorder
.section .text

function dma_hook
    jal dmaCustomCode
    nop