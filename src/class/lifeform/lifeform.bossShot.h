.include "src/config/config.inc"

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  oam INSTANCEOF oamStruct
  this.timer dw
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isSprite | OBJECT.PROPERTIES.isCollidable | OBJECT.PROPERTIES.isLifeform | OBJECT.PROPERTIES.isEnemy | OBJECT.PROPERTIES.isLevelMember | OBJECT.PROPERTIES.hurts | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  lifeform.bossShot.parameter.pos.x db
  lifeform.bossShot.parameter.pos.y db
  lifeform.bossShot.parameter.size.x db
  lifeform.bossShot.parameter.size.y db
  lifeform.bossShot.parameter.angle db
.ende

.base BSL
.bank BANK.PROGRAM

