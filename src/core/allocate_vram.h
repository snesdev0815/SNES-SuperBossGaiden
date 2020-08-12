.include "src/config/config.inc"

;defines
.def VRAM_ALLOCATION_BLOCKSIZE $80
.def VRAM_ALLOCATION_BLOCKS $200

.def VRAM_ALLOCATION_STEP.MIN VRAM_ALLOCATION_BLOCKSIZE
.def VRAM_ALLOCATION_STEP.MAX $4000


;ram buffers
.ramsection "global vram_allocate vars" bank 0 slot 1
VRAM_ALLOCATE.GLOBAL.START ds 0
GLOBAL.currentVramAllocationId db

GLOBAL.vramAllocation.input.stepsize dw
GLOBAL.vramAllocation.input.length dw
GLOBAL.vramAllocation.inputBig.length dw
GLOBAL.vramAllocation.temp.start dw
GLOBAL.vramAllocation.temp.stepsize dw
GLOBAL.vramAllocation.temp.length dw
GLOBAL.vramAllocation.result.normal.start dw
GLOBAL.vramAllocation.result.big.start dw
GLOBAL.vramAllocationBlocks ds VRAM_ALLOCATION_BLOCKS
GLOBAL.vramAllocation.dummy dw

VRAM_ALLOCATE.GLOBAL.END ds 0
.ends

.base BSL
.bank BANK.PROGRAM
