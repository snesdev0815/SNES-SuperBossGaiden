.include "src/config/config.inc"


.struct vars
  ;currentSpeed dw
  ;currentAnimation dw
  ;age dw
  ;speed dw
  turnRate dw
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
  sprite.directed.parameter.pos.x db
  sprite.directed.parameter.pos.y db
  sprite.directed.parameter.animation.id db
  sprite.directed.parameter.animation.speed db
  sprite.directed.parameter.direction db
  sprite.directed.parameter.speed db
  sprite.directed.parameter.size.x db
  sprite.directed.parameter.size.y db
.ende

.base BSL
.bank BANK.PROGRAM

