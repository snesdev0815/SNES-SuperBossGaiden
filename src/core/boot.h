.include "src/config/config.inc"

.base REGS
;direct page global defines ram $00:0000-$00:1fff
.ramsection "stack buffr" bank 0 slot 2
STACK_strt ds $c0
STACK db
STACK_end dw
.ends

.ramsection "zeropage vars" bank 0 slot 2
ZP ds kernelEnd-kernelStart
ZP.end ds 0
.ends

.ramsection "global vars" bank 0 slot 1
VARS									ds 0
OopObjCount						dw	;counts how many times createoopobj was called. used to generate fingerprint
GLOBAL.memsel	db
VARS_end							ds 0
.ends


.base BSL
.bank BANK.PROGRAM
