.include "src/config/config.inc"

.struct vars
  caller ds _sizeof_oopObjHash
  command dw
  value dw
  controller dw
.endst


;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  option INSTANCEOF optionStruct
  this INSTANCEOF vars
zpLen ds 0
.ende


;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES OBJECT.PROPERTIES.isOption
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

.base BSL
.bank BANK.PROGRAM
