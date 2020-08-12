.include "src/config/config.inc"

;defines
.def GLOBAL.OAM_TILES.POOL.ENTRIES 16

;ram buffers
.ramsection "global cgram pool vars" bank 0 slot 1
OAM_TILES.POOL.GLOBAL.START ds 0
  GLOBAL.oam_tiles.pool.hash.current dw
  GLOBAL.oam_tiles.pool INSTANCEOF poolEntry GLOBAL.OAM_TILES.POOL.ENTRIES
OAM_TILES.POOL.GLOBAL.END ds 0
.ends

.base BSL
.bank BANK.PROGRAM
