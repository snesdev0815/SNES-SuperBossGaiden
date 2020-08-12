.include "src/config/config.inc"


.def TEXTLAYER.WHITESPACE $20
.export TEXTLAYER.WHITESPACE

.def TEXTLAYER.DIGITS $30
.export TEXTLAYER.DIGITS

.def TEXTBOX.FLAGS.SKIPWHITESPACE 1 << 0
.export TEXTBOX.FLAGS.SKIPWHITESPACE

;zp-vars,just a reference
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
