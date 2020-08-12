.include "src/config/config.inc"

.def FIREBALL.JUMP.IMPULSE -800
.def FIREBALL.JUMP.ACCEL -5

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  oam INSTANCEOF oamStruct
  lifeform INSTANCEOF lifeformStruct
  this.age dw
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isSprite | OBJECT.PROPERTIES.isCollidable | OBJECT.PROPERTIES.isLifeform | OBJECT.PROPERTIES.isEnemy | OBJECT.PROPERTIES.isGrabbable | OBJECT.PROPERTIES.isLevelMember | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  lifeform.fireball.parameter.pos.x db
  lifeform.fireball.parameter.pos.y db
  lifeform.fireball.parameter.size.x db
  lifeform.fireball.parameter.size.y db
  lifeform.fireball.parameter.berzerk.yield db
  lifeform.fireball.parameter.timer db
.ende

.base BSL
.bank BANK.PROGRAM

