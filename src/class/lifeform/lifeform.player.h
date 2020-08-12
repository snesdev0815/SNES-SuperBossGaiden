.include "src/config/config.inc"

.def PLAYER.TIMER.INVINCIBLE 90
.export PLAYER.TIMER.INVINCIBLE

.def SPRITE.PLAYER.DEFAULT.SPEED $200
.export SPRITE.PLAYER.DEFAULT.SPEED

.def SPRITE.PLAYER.MAX.SPEED SPRITE.PLAYER.DEFAULT.SPEED*1.6

.def PLAYER.HURT.BERZERK_MINUS 50

.def BOSS.POWER 2

.ramsection "global vars nmi" bank 0 slot 1
GLOBAL.battle.hit.perfect dw
GLOBAL.battle.hit.ok dw
GLOBAL.battle.hit.miss dw

.ends

.enum 0 export
  PLAYER.MODE.NORMAL db
  PLAYER.MODE.SUPER db
.ende
		 
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
.define CLASS.FLAGS (OBJECT.FLAGS.Present | OBJECT.FLAGS.Singleton)
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isSprite | OBJECT.PROPERTIES.isCollidable | OBJECT.PROPERTIES.isPlayer | OBJECT.PROPERTIES.isLifeform | OBJECT.PROPERTIES.isGrabbable | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  lifeform.player.parameter.pos.x db
  lifeform.player.parameter.pos.y db
  lifeform.player.parameter.size.x db
  lifeform.player.parameter.size.y db
  lifeform.player.parameter.input.id db
  lifeform.player.parameter.input.type db
.ende

.base BSL
.bank BANK.PROGRAM

