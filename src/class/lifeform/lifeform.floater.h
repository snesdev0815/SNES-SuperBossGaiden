.include "src/config/config.inc"

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  oam INSTANCEOF oamStruct
  lifeform INSTANCEOF lifeformStruct
  this.position.original.y dw
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isSprite | OBJECT.PROPERTIES.isCollidable | OBJECT.PROPERTIES.isLifeform | OBJECT.PROPERTIES.isEnemy | OBJECT.PROPERTIES.isGrabbable | OBJECT.PROPERTIES.isLevelMember | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  lifeform.floater.parameter.pos.x db
  lifeform.floater.parameter.pos.y db
  lifeform.floater.parameter.size.x db
  lifeform.floater.parameter.size.y db
  lifeform.floater.parameter.berzerk.yield db
  lifeform.floater.parameter.angle db
.ende

.base BSL
.bank BANK.PROGRAM

