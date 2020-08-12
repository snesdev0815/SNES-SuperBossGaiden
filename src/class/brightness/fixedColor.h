.include "src/config/config.inc"


.def FIXED_COLOR.SPEED.DEFAULT $3

.def FIXED_COLOR.BLACK $0
.def FIXED_COLOR.RED COLDATA_INTENSITY << 0
.def FIXED_COLOR.GREEN COLDATA_INTENSITY << 5
.def FIXED_COLOR.BLUE COLDATA_INTENSITY << 10
.def FIXED_COLOR.WHITE (FIXED_COLOR.RED | FIXED_COLOR.GREEN | FIXED_COLOR.BLUE)
.def FIXED_COLOR.TEXTBOX ((7<<0) | (10<<5) | (8<<10))

.export FIXED_COLOR.BLACK
.export FIXED_COLOR.RED
.export FIXED_COLOR.GREEN
.export FIXED_COLOR.BLUE
.export FIXED_COLOR.WHITE
.export FIXED_COLOR.TEXTBOX
		 
.struct brightStruct
  speed db
  current dw
  target dw
.endst

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  this INSTANCEOF brightStruct

zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS (OBJECT.FLAGS.Present | OBJECT.FLAGS.Singleton)
.define CLASS.PROPERTIES 0
.define CLASS.ZP_LENGTH zpLen


.base BSL
.bank BANK.PROGRAM
