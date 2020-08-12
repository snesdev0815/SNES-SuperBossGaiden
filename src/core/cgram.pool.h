.include "src/config/config.inc"

;defines
.def GLOBAL.CGRAM.POOL.ENTRIES 8

;ram buffers
.ramsection "global cgram pool vars" bank 0 slot 1
CGRAM.POOL.GLOBAL.START ds 0
  GLOBAL.cgram.pool.hash.current dw
  GLOBAL.cgram.pool INSTANCEOF poolEntry GLOBAL.CGRAM.POOL.ENTRIES
CGRAM.POOL.GLOBAL.END ds 0
.ends

.base BSL
.bank BANK.PROGRAM
