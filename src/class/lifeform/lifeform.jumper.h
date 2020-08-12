.include "src/config/config.inc"

.def APPLE.JUMP.IMPULSE -1200
.def APPLE.JUMP.ACCEL -20

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  oam INSTANCEOF oamStruct
  lifeform INSTANCEOF lifeformStruct
  this.jump.count dw
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isSprite | OBJECT.PROPERTIES.isCollidable | OBJECT.PROPERTIES.isLifeform | OBJECT.PROPERTIES.isEnemy | OBJECT.PROPERTIES.isGrabbable | OBJECT.PROPERTIES.isLevelMember | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  lifeform.jumper.parameter.pos.x db
  lifeform.jumper.parameter.pos.y db
  lifeform.jumper.parameter.size.x db
  lifeform.jumper.parameter.size.y db
  lifeform.jumper.parameter.berzerk.yield db
.ende

.base BSL
.bank BANK.PROGRAM
