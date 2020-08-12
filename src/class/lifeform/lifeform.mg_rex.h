.include "src/config/config.inc"

.def MG_REX.JUMP.IMPULSE -1400
.def MG_REX.JUMP.ACCEL -20

.def MG_REX.WALK.AGE 120
.def MG_REX.PAUSE2.AGE 60
.def MG_REX.PAUSE.AGE 120

.def MG_REX.ROAR.AGE 120

.def MG_REX.DIZZY.AGE 240

.def MG_REX.HP 30

.enum 0
  MG_REX.MODE.AWAIT_STASH db
  MG_REX.MODE.ROAR db
  MG_REX.MODE.LASER db
  MG_REX.MODE.PAUSE db
  MG_REX.MODE.WALK db
  MG_REX.MODE.SHOOT db
.ende

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  oam INSTANCEOF oamStruct
  lifeform INSTANCEOF lifeformStruct
  this.passenger ds _sizeof_oopObjHash
  this.projectile ds _sizeof_oopObjHash
  this.mode dw
  this.age dw
  this.cycle dw
  this.origin.x dw
  this.generatorIndex dw
  this.animationStuff dw
  this.shootingAngle db
  this.targetAngle db
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isSprite | OBJECT.PROPERTIES.isCollidable | OBJECT.PROPERTIES.isLifeform | OBJECT.PROPERTIES.isEnemy | OBJECT.PROPERTIES.isGrabbable | OBJECT.PROPERTIES.isLevelMember | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  lifeform.mg_rex.parameter.pos.x db
  lifeform.mg_rex.parameter.pos.y db
  lifeform.mg_rex.parameter.size.x db
  lifeform.mg_rex.parameter.size.y db
  lifeform.mg_rex.parameter.berzerk.yield db
  lifeform.mg_rex.parameter.passenger.lo db
  lifeform.mg_rex.parameter.passenger.hi db
.ende

.base BSL
.bank BANK.PROGRAM

