#include <macro.inc>
.set noat
.set noreorder
.section .text

function cursor_hook
    jal selectCpu
    nop