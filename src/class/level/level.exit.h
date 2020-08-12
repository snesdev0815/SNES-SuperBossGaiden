.include "src/config/config.inc"

.def EXIT.LOCKED_BY.NONE  0
.def EXIT.LOCKED_BY.BIT_AND 2
.def EXIT.LOCKED_BY.BIT_OR  3
.def EXIT.LOCKED_BY.ENEMY 5
.def EXIT.LOCKED_BY.PERSISTENT_FLAG 6
.def EXIT.LOCKED_BY.MASK 7

.def EXIT.LIFEFORM.MASK 24

.def EXIT.STATUS.LOCKED 32
.def EXIT.STATUS.UNLOCK_HIDDEN 64
.def EXIT.STATUS.INITIALIZED 128

.def EXIT.ENTRANCE.NONE 0 << 8
.def EXIT.ENTRANCE.DARK 1 << 8
.def EXIT.ENTRANCE.WARP 2 << 8
.def EXIT.ENTRANCE.FALL 3 << 8
.def EXIT.ENTRANCE.MASK 3 << 8

.def EXIT.CONFIRM_ENTER 1024

.def EXIT.REVERSE_LOCK 2048

.def EXIT.ANIMATION.NONE 0

.def LEVEL.EXIT.ENTRANCE.DARK.TIMEOUT 30

.export EXIT.LOCKED_BY.NONE
.export EXIT.LOCKED_BY.BIT_AND
.export EXIT.LOCKED_BY.BIT_OR
.export EXIT.LOCKED_BY.ENEMY
.export EXIT.LOCKED_BY.PERSISTENT_FLAG
.export EXIT.LOCKED_BY.MASK
.export EXIT.LIFEFORM.MASK
.export EXIT.STATUS.LOCKED
.export EXIT.STATUS.UNLOCK_HIDDEN
.export EXIT.ENTRANCE.NONE
.export EXIT.ENTRANCE.DARK
.export EXIT.ENTRANCE.WARP
.export EXIT.ENTRANCE.FALL
.export EXIT.ENTRANCE.MASK
.export EXIT.CONFIRM_ENTER
.export EXIT.REVERSE_LOCK



.enum 0
  LEVEL.EXIT.STATE.PLAY db
  LEVEL.EXIT.STATE.WAITSCRIPT db
  LEVEL.EXIT.STATE.FADEOUT db
.ende

.struct vars
  target.level dw
  target.player.pos.x dw
  target.player.pos.y dw
  target.script dw
  timer dw
  flags dw
  lockedBy dw
  animation.size.x dw
  animation.size.y dw
  scriptObj ds _sizeof_oopObjHash
  persistency ds _sizeof_oopObjHash
.endst
		 
;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  oam INSTANCEOF oamStruct
  this INSTANCEOF vars
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isLevelMember | OBJECT.PROPERTIES.isSprite | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  level.exit.parameter.pos.x db
  level.exit.parameter.pos.y db
  level.exit.parameter.size.x db
  level.exit.parameter.size.y db
  level.exit.parameter.target.level db
  level.exit.parameter.target.pos.x db
  level.exit.parameter.target.pos.y db
  level.exit.parameter.script db
  level.exit.parameter.flags db
  level.exit.parameter.lockedBy db
.ende

.base BSL
.bank BANK.PROGRAM

