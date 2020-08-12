.include "src/config/config.inc"

;defines
.def WRAM_ALLOCATION_BLOCKSIZE $100
.def WRAM_ALLOCATION_BLOCKS $30 ;$50 ;$c8*2

.def WRAM_ALLOCATION_STEP.MIN WRAM_ALLOCATION_BLOCKSIZE
.def WRAM_ALLOCATION_STEP.MAX $2000
.def GLOBAL.WRAM_ALLOCATION.STEPSIZE WRAM_ALLOCATION_STEP.MIN


;ram buffers
.ramsection "global wram_allocate vars" bank 0 slot 1
WRAM_ALLOCATE.GLOBAL.START ds 0
GLOBAL.currentWramAllocationId db
GLOBAL.wramAllocation.input.length dw
GLOBAL.wramAllocation.input.grantId dw
GLOBAL.wramAllocation.temp.start dw
GLOBAL.wramAllocation.temp.length dw
GLOBAL.wramAllocation.dummy.start dw
GLOBAL.wramAllocationBlocks ds WRAM_ALLOCATION_BLOCKS
GLOBAL.wramAllocation.dummy.end dw

WRAM_ALLOCATE.GLOBAL.END ds 0
.ends

.ramsection "wram buffer" bank 0 slot 1
GLOBAL.wramBuffer.start ds 0
GLOBAL.wramBuffer ds WRAM_ALLOCATION_BLOCKSIZE * WRAM_ALLOCATION_BLOCKS
GLOBAL.wramBuffer.end ds 0
.ends

.base BSL
.bank BANK.PROGRAM
