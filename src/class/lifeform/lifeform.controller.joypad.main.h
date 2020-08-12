.include "src/config/config.inc"


;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  oam INSTANCEOF oamStruct
  lifeform INSTANCEOF lifeformStruct
  this INSTANCEOF playerStruct
  zpLen ds 0
.ende


.base BSL
.bank BANK.DATA


.section "joypad.main.direction.4to8way.lut" superfree
joypad.main.direction.4to8way.lut:
  .dw JOY_DIR_RIGHT
  .dw JOY_DIR_LEFT
  .dw JOY_DIR_DOWN
  .dw JOY_DIR_UP
joypad.main.direction.4to8way.lut.end:
.ends

.base BSL
.bank BANK.PROGRAM