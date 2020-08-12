.include "src/config/config.inc"

;ram buffers
.enum 0
  iterator INSTANCEOF iteratorStruct
  sort INSTANCEOF sortStruct
  zpLen ds 0
.ende

;zero page
.ramsection "oop obj ram zp" bank 0 slot 2
  ZP.SORT ds zpLen
.ends


.base BSL
.bank BANK.PROGRAM
