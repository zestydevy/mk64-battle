#include <macro.inc>
.set noat
.set noreorder
.section .text

function obj_display_hook
    
    addiu $sp, $sp, -0x20
    sw    $ra, 0x1C($sp)
    
    jal display_object2
    nop

    lw    $ra, 0x1C($sp)
    addiu $sp, $sp, 0x20

    jr $ra
    nop