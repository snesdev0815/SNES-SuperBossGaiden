.include "src/config/config.inc"

.define PALETTE.ROTATE.BLEND_STEPS 4

.struct palStruct
  targetPalette.id dw
  targetPalette.pointer ds 3
  counter dw
  state dw
.endst

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  palette INSTANCEOF paletteStruct
  this INSTANCEOF palStruct

zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES OBJECT.PROPERTIES.isLevelMember
.define CLASS.ZP_LENGTH zpLen

;external parameters
.enum 0 export
  palette.animation.parameter.animation.id db
  palette.animation.parameter.start db
  palette.animation.parameter.length db
  palette.animation.parameter.delay db
  palette.animation.parameter.notLevelMember db
  palette.animation.parameter.pos.x db
  palette.animation.parameter.pos.y db
  palette.animation.parameter.size.x db
  palette.animation.parameter.size.y db
.ende

.base BSL
.bank BANK.PROGRAM
