.include "src/config/config.inc"

.def BRIGHTNESS.TABLE.LENGTH $60
.def BRIGHTNESS.VALUE_TABLE.LENGTH $10

.enum 0
  BRIGHTNESS.INDIRECT_TABLE ds BRIGHTNESS.TABLE.LENGTH
  BRIGHTNESS.VALUE_TABLE ds BRIGHTNESS.VALUE_TABLE.LENGTH
  BRIGHTNESS.VALUE_TABLE.LENGTH_TOTAL ds 0
.ende

.struct vars
  brightness db
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
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isHdma | OBJECT.PROPERTIES.isLevelMember)
.define CLASS.ZP_LENGTH zpLen

;external parameters
.enum 0 export
  hdma.brightness.parameter.pos.x db
  hdma.brightness.parameter.pos.y db
  hdma.brightness.parameter.size.x db
  hdma.brightness.parameter.size.y db
.ende

.base BSL
.bank BANK.PROGRAM

