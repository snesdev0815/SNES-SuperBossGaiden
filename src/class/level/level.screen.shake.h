.include "src/config/config.inc"


.struct vars
  age dw
  intensity dw
  speed dw
  counter dw
.endst
		 
;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  this INSTANCEOF vars
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES OBJECT.PROPERTIES.isLevelMember
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  level.screen.shake.parameter.pos.x db
  level.screen.shake.parameter.pos.y db
  level.screen.shake.parameter.size.x db
  level.screen.shake.parameter.size.y db
  level.screen.shake.parameter.intensity db
  level.screen.shake.parameter.speed db
.ende

.base BSL
.bank BANK.PROGRAM

