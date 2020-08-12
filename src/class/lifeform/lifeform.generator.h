.include "src/config/config.inc"

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  this.berzerk.yield dw
  this.arg.0 dw
  this.timer dw
  this.createTimer dw
  this.payload.class dw
  this.payload.object ds _sizeof_oopObjHash
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isLevelMember | OBJECT.PROPERTIES.isEnemy | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  lifeform.generator.parameter.pos.x db
  lifeform.generator.parameter.pos.y db
  lifeform.generator.parameter.size.x db
  lifeform.generator.parameter.size.y db
  lifeform.generator.parameter.berzerk.yield db
  lifeform.generator.parameter.payload db
  lifeform.generator.parameter.arg.0 db
  lifeform.generator.parameter.timer db
  lifeform.generator.parameter.count db
.ende

.base BSL
.bank BANK.PROGRAM

