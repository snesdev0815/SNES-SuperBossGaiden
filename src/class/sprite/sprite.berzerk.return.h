.include "src/config/config.inc"

.def BERZERK.RETURN.AGE 180

.struct vars
  age dw
  value dw
  ;direction.target dw
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
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isSprite | OBJECT.PROPERTIES.isLevelMember | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  sprite.berzerk.return.parameter.pos.x db
  sprite.berzerk.return.parameter.pos.y db
  sprite.berzerk.return.parameter.value db
  sprite.berzerk.return.parameter.size.x db
  sprite.berzerk.return.parameter.size.y db
.ende

.base BSL
.bank BANK.PROGRAM

