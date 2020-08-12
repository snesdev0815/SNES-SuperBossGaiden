.include "src/config/config.inc"

.def CANNON.SHOOT.AGE 30
.def CANNON.SHOOT.DELAY 10

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  oam INSTANCEOF oamStruct
  lifeform INSTANCEOF lifeformStruct
  this.payload.class dw
  this.payload.object ds _sizeof_oopObjHash
  this.arg.0 dw
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isSprite | OBJECT.PROPERTIES.isCollidable | OBJECT.PROPERTIES.isLifeform | OBJECT.PROPERTIES.isEnemy | OBJECT.PROPERTIES.isLevelMember | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  lifeform.cannon.parameter.pos.x db
  lifeform.cannon.parameter.pos.y db
  lifeform.cannon.parameter.size.x db
  lifeform.cannon.parameter.size.y db
  lifeform.cannon.parameter.berzerk.yield db
  lifeform.cannon.parameter.payload db
  lifeform.cannon.parameter.arg.0 db
.ende

.base BSL
.bank BANK.PROGRAM

