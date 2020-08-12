.include "src/config/config.inc"


.struct vars
  bg dw
  screen.current.x dw
  screen.current.y dw
  screen.last.x dw
  screen.last.y dw

.endst
		 
;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  background INSTANCEOF backgroundStruct
  this INSTANCEOF vars
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES OBJECT.PROPERTIES.isLevelSortable
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  background.generic.parameter.pos.x db
  background.generic.parameter.pos.y db
  background.generic.parameter.animation.id db
  background.generic.parameter.animation.speed db
  background.generic.parameter.animation.flags db
  background.generic.parameter.layer db
  background.generic.parameter.size.x db
  background.generic.parameter.size.y db
.ende

.base BSL
.bank BANK.PROGRAM

