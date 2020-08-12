.include "src/config/config.inc"


.struct vars
  currentSpeed dw
  currentAnimation dw
  age dw
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
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isSprite | OBJECT.PROPERTIES.isCollidable | OBJECT.PROPERTIES.isLevelMember | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  sprite.once.parameter.pos.x db
  sprite.once.parameter.pos.y db
  sprite.once.parameter.animation.id db
  sprite.once.parameter.animation.speed db
  sprite.once.parameter.size.x db
  sprite.once.parameter.size.y db
.ende

.base BSL
.bank BANK.PROGRAM

