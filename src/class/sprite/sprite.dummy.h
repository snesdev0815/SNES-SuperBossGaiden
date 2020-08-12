.include "src/config/config.inc"


.struct vars
  currentAnimation dw
.endst
		 
;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  oam INSTANCEOF oamStruct
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
  sprite.dummy.parameter.animation.id db
  sprite.dummy.parameter.pos.x db
  sprite.dummy.parameter.pos.y db
  sprite.dummy.parameter.size.x db
  sprite.dummy.parameter.size.y db  
.ende

.base BSL
.bank BANK.PROGRAM

