.include "src/config/config.inc"

.def SPRITE.TILE.MAX 100
.def SPRITE.TILE_BIG.MAX 8
.def SPRITE.DMA_UNROLLED.THRESHOLD 5
/*
.def SCREEN.MARGIN.X TILE.SIZE.X
.def SCREEN.MARGIN.Y TILE.SIZE.Y
*/
.def SPRITE.HIOAM.SIZE %10
.export SPRITE.HIOAM.SIZE

;zp-vars,just a reference
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  oam INSTANCEOF oamStruct
zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES 0
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;.base BSL
;.bank STATIC.32X32_LUT >> 16
;.org 0
;.section "sprite32x32id.lut" force
.base BSL
.bank BANK.DATA
.section "sprite32x32id.lut" superfree
	.include "src/class/sprite/32x32id.lut"
.ends

.include "src/include/sprite.include"

.base BSL
.bank BANK.PROGRAM