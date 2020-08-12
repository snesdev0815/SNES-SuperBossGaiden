.include "src/config/config.inc"

.def TARGET.DISTANCE 45
.def LIFEFORM.HITPOINTS 10

.def LIFEFORM.BALROG.CYCLES 3

.def BALROG.ATTACK.COUNTER 80

.def BALROG.INVINCIBLE.TIMER 80

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  oam INSTANCEOF oamStruct
  lifeform INSTANCEOF lifeformStruct
  this.target.pos.x dw
  this.target.pos.y dw
  this.target.direction dw
  this.cycle dw
  this.mode dw
  this.animationStuff dw
  this.targetDistance dw
  this.payload.class dw
  this.payload.object ds _sizeof_oopObjHash
  this.mg_rex ds _sizeof_oopObjHash
  this.attack.counter dw
  this.attack.wait dw
  zpLen ds 0
.ende

.enum 0
  BALROG.MODE.MOUNT db
  BALROG.MODE.RIDING db
  BALROG.MODE.ATTACK db
  BALROG.MODE.DIZZY db
  BALROG.MODE.WAIT db
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isSprite | OBJECT.PROPERTIES.isCollidable | OBJECT.PROPERTIES.isLifeform | OBJECT.PROPERTIES.isGrabbable | OBJECT.PROPERTIES.isLevelMember | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  lifeform.miniboss.parameter.pos.x db
  lifeform.miniboss.parameter.pos.y db
  lifeform.miniboss.parameter.size.x db
  lifeform.miniboss.parameter.size.y db
  lifeform.miniboss.parameter.berzerk.yield db
  lifeform.miniboss.parameter.animation.id db
  lifeform.miniboss.parameter.payload db
  lifeform.miniboss.parameter.attack.wait db
.ende

.base BSL
.bank BANK.PROGRAM

