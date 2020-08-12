.include "src/config/config.inc"

.def UMBRELLA.JUMP.IMPULSE -1400
.def UMBRELLA.JUMP.ACCEL -20

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  oam INSTANCEOF oamStruct
  lifeform INSTANCEOF lifeformStruct
  this.mode dw
  this.wait dw
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isSprite | OBJECT.PROPERTIES.isCollidable | OBJECT.PROPERTIES.isLifeform | OBJECT.PROPERTIES.isEnemy | OBJECT.PROPERTIES.isGrabbable | OBJECT.PROPERTIES.isLevelMember | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  lifeform.parappa.parameter.pos.x db
  lifeform.parappa.parameter.pos.y db
  lifeform.parappa.parameter.size.x db
  lifeform.parappa.parameter.size.y db
  lifeform.parappa.parameter.berzerk.yield db
.ende

.base BSL
.bank BANK.PROGRAM

