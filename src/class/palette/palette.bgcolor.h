.include "src/config/config.inc"

.struct palStruct
  palette.id dw
.endst

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  palette INSTANCEOF paletteStruct
  this INSTANCEOF palStruct

zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS (OBJECT.FLAGS.Present | OBJECT.FLAGS.Singleton)
.define CLASS.PROPERTIES 0
.define CLASS.ZP_LENGTH zpLen


.base BSL
.bank BANK.PROGRAM
