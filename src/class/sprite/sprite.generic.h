.include "src/config/config.inc"


.struct vars
  currentSpeed dw
  currentAnimation dw
  age dw
  shaker dw
  buffer.pos.x dw
  buffer.pos.y dw
  counter dw
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
  sprite.generic.parameter.pos.x db
  sprite.generic.parameter.pos.y db
  sprite.generic.parameter.animation.id db
  sprite.generic.parameter.animation.speed db
  sprite.generic.parameter.animation.flags db
  sprite.generic.parameter.size.x db
  sprite.generic.parameter.size.y db
.ende

.base BSL
.bank BANK.PROGRAM

