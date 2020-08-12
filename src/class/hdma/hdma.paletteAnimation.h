.include "src/config/config.inc"

.struct vars
  void db
.endst
		 
;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  hdma INSTANCEOF hdmaStruct
  this INSTANCEOF vars
zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isHdma | OBJECT.PROPERTIES.isLevelMember)
.define CLASS.ZP_LENGTH zpLen

;external parameters
.enum 0 export
  hdma.paletteAnimation.parameter.pos.x db
  hdma.paletteAnimation.parameter.pos.y db
  hdma.paletteAnimation.parameter.animation.id db
  hdma.paletteAnimation.parameter.delay db
  hdma.paletteAnimation.parameter.size.x db
  hdma.paletteAnimation.parameter.size.y db
    
.ende
.base BSL
.bank BANK.PROGRAM

