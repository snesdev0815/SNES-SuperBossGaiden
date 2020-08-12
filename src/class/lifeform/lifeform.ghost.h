.include "src/config/config.inc"

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  oam INSTANCEOF oamStruct
  this.payload.class dw
  this.payload.obj ds _sizeof_oopObjHash
  this.timer dw
  this.throw dw
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isSprite | OBJECT.PROPERTIES.isLevelMember | OBJECT.PROPERTIES.isLifeform | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  lifeform.ghost.parameter.pos.x db
  lifeform.ghost.parameter.pos.y db
  lifeform.ghost.parameter.size.x db
  lifeform.ghost.parameter.size.y db
  lifeform.ghost.parameter.animation.id db
  lifeform.ghost.parameter.payload db
.ende

.base BSL
.bank BANK.PROGRAM

