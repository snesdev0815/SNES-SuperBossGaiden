.include "src/config/config.inc"

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  oam INSTANCEOF oamStruct
  lifeform INSTANCEOF lifeformStruct
  this.class.key ds _sizeof_oopObjHash
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isSprite | OBJECT.PROPERTIES.isCollidable | OBJECT.PROPERTIES.isLifeform | OBJECT.PROPERTIES.isEnemy | OBJECT.PROPERTIES.isLevelMember | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  lifeform.block.parameter.pos.x db
  lifeform.block.parameter.pos.y db
  lifeform.block.parameter.size.x db
  lifeform.block.parameter.size.y db
  lifeform.block.parameter.berzerk.yield db
  lifeform.block.parameter.key db
.ende

.base BSL
.bank BANK.PROGRAM

