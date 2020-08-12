.include "src/config/config.inc"

.define PALETTE.ROTATE.BLEND_STEPS 4

.enum 0
  PALETTE_FADE.STATE.VOID db
  PALETTE_FADE.STATE.WAIT db
  PALETTE_FADE.STATE.FETCH db
  PALETTE_FADE.STATE.WAIT2 db
  PALETTE_FADE.STATE.PRIME db
  PALETTE_FADE.STATE.FADE db
  PALETTE_FADE.STATE.IDLE db

  PALETTE_FADE.STATE.WAIT3 db  
  PALETTE_FADE.STATE.FETCH2 db
  PALETTE_FADE.STATE.WAIT4 db  
  PALETTE_FADE.STATE.PRIME2 db
  PALETTE_FADE.STATE.FADE2 db
  PALETTE_FADE.STATE.IDLE2 db

  PALETTE_FADE.STATE.WAIT5 db  
  PALETTE_FADE.STATE.FETCH3 db
  PALETTE_FADE.STATE.WAIT6 db  
  PALETTE_FADE.STATE.PRIME3 db
  PALETTE_FADE.STATE.FADE3 db
  PALETTE_FADE.STATE.IDLE3 db
  
.ende

.struct palStruct
  delay dw
  palette.pointer.0 dw
  palette.pointer.1 dw
  palette.pointer.2 dw
  target.pointer dw
  counter dw
  state dw
  target.color dw
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
.define CLASS.PROPERTIES 0
.define CLASS.ZP_LENGTH zpLen


.base BSL
.bank BANK.PROGRAM
