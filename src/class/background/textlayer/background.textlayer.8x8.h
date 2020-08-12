.include "src/config/config.inc"

.def GLOBAL.TEXTLAYER.8x8.FONT.SIZE.X 8
.def GLOBAL.TEXTLAYER.8x8.FONT.SIZE.Y 8

.export GLOBAL.TEXTLAYER.8x8.FONT.SIZE.X
.export GLOBAL.TEXTLAYER.8x8.FONT.SIZE.Y

.struct vars
  bg db
.endst
		 
;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  background INSTANCEOF backgroundStruct
  textlayer INSTANCEOF textlayerStruct
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES OBJECT.PROPERTIES.isLevelSortable
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

.base BSL
.bank BANK.PROGRAM

