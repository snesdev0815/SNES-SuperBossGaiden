.include "src/config/config.inc"

.struct vars
  void dw
.endst

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  oam INSTANCEOF oamStruct
  lifeform INSTANCEOF lifeformStruct
  this INSTANCEOF vars
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isSprite | OBJECT.PROPERTIES.isCollidable | OBJECT.PROPERTIES.isLifeform | OBJECT.PROPERTIES.isActionable | OBJECT.PROPERTIES.isLevelMember| OBJECT.PROPERTIES.isGrabbable | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  lifeform.npc.parameter.pos.x db
  lifeform.npc.parameter.pos.y db
  lifeform.npc.parameter.size.x db
  lifeform.npc.parameter.size.y db
  lifeform.npc.parameter.berzerk.yield db
  lifeform.npc.parameter.animation.id db
.ende

.base BSL
.bank BANK.PROGRAM

