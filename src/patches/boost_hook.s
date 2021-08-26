#include <macro.inc>
.set noat
.set noreorder
.section .text

function boost_hook
    jal setDriftBoost
    nop