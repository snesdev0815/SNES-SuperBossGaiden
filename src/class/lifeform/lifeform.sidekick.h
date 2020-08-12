.include "src/config/config.inc"


.def SPRITE.PLAYER.MAX.SPEED SPRITE.PLAYER.DEFAULT.SPEED*1.6

.def SIDEKICK.OFFSCREEN.WARP_THRESHOLD 128

.def PLAYER.HURT.BERZERK_MINUS 50

.def BOSS.POWER 2


;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  oam INSTANCEOF oamStruct
  lifeform INSTANCEOF lifeformStruct
  this INSTANCEOF playerStruct
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isSprite | OBJECT.PROPERTIES.isCollidable | OBJECT.PROPERTIES.isPlayer | OBJECT.PROPERTIES.isLifeform | OBJECT.PROPERTIES.isGrabbable | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  lifeform.sidekick.parameter.pos.x db
  lifeform.sidekick.parameter.pos.y db
  lifeform.sidekick.parameter.size.x db
  lifeform.sidekick.parameter.size.y db
  lifeform.sidekick.parameter.input.id db
  lifeform.sidekick.parameter.animation.id db
.ende

.base BSL
.bank BANK.PROGRAM

