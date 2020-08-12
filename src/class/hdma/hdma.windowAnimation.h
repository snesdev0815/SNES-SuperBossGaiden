.include "src/config/config.inc"

.struct vars
	none ds 0
	callback dw
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

