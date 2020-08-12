.include "src/config/config.inc"

.def LEMON.EXPLODE.AGE 180

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  oam INSTANCEOF oamStruct
  lifeform INSTANCEOF lifeformStruct
  this.timer dw
  this.obj.palette ds _sizeof_oopObjHash
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isSprite | OBJECT.PROPERTIES.isCollidable | OBJECT.PROPERTIES.isLifeform | OBJECT.PROPERTIES.isEnemy | OBJECT.PROPERTIES.isGrabbable | OBJECT.PROPERTIES.isLevelMember | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  lifeform.bomb.parameter.pos.x db
  lifeform.bomb.parameter.pos.y db
  lifeform.bomb.parameter.size.x db
  lifeform.bomb.parameter.size.y db
  lifeform.bomb.parameter.berzerk.yield db
.ende

.base BSL
.bank BANK.PROGRAM

