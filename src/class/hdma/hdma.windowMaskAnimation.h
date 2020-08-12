.include "src/config/config.inc"

.struct vars
  buffer.window12Sel db
  buffer.window34Sel db
  buffer.windowObjSel db
  buffer.windowMainscreen db
  buffer.windowSubscreen db
  buffer.windowBgLogic db
  buffer.windowObjLogic db
  buffer.cgwsel db
  buffer.cgadsub db
  callback dw
  brightness ds _sizeof_oopObjHash
.endst
		 
;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  hdma INSTANCEOF hdmaStruct
  this INSTANCEOF vars
zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS (OBJECT.FLAGS.Present | OBJECT.FLAGS.Singleton)
.define CLASS.PROPERTIES OBJECT.PROPERTIES.isHdma
.define CLASS.ZP_LENGTH zpLen

.base BSL
.bank BANK.PROGRAM
