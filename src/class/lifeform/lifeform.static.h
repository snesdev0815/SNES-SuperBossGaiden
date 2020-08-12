.include "src/config/config.inc"

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  oam INSTANCEOF oamStruct
  lifeform INSTANCEOF lifeformStruct
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isSprite | OBJECT.PROPERTIES.isCollidable | OBJECT.PROPERTIES.isLifeform | OBJECT.PROPERTIES.isEnemy | OBJECT.PROPERTIES.isGrabbable | OBJECT.PROPERTIES.isLevelMember | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  lifeform.static.parameter.pos.x db
  lifeform.static.parameter.pos.y db
  lifeform.static.parameter.size.x db
  lifeform.static.parameter.size.y db
  lifeform.static.parameter.berzerk.yield db
  lifeform.static.parameter.animation.id db
.ende

.enum 0 export
  lifeform.staticCutscene.parameter.pos.x db
  lifeform.staticCutscene.parameter.pos.y db
  lifeform.staticCutscene.parameter.size.x db
  lifeform.staticCutscene.parameter.size.y db
  lifeform.staticCutscene.parameter.berzerk.yield db
  lifeform.staticCutscene.parameter.animation.id db
.ende

.base BSL
.bank BANK.PROGRAM

