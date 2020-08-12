.include "src/config/config.inc"

.def VWF.WIDTH_TABLE.BREAKABLE $80

.def VWF.MAGIC.VALUE $4656
.export VWF.MAGIC.VALUE

.enum 0
  VWF.STATE.RENDER db
  VWF.STATE.WAIT db
  VWF.STATE.DONE db
  VWF.STATE.KILL db
  VWF.STATE.MAX ds 0
.ende

;vwf font file format
.enum 0 export
  VWF.MAGIC dw
  VWF.TILE_WIDTH db
  VWF.TILE_HEIGHT db
  VWF.BPP db
  VWF.PALETTE_ID db
  VWF.TILE_SIZE db
  VWF.TILE_COUNT dw
  VWF.PALETTE_HASH dw
  VWF.PALETTE ds 32
  VWF.WIDTH_TABLE db
.ende

.struct vars
  source.pointer ds 3
  font.pointer ds 3
  char.current dw
  char.current.font.pointer ds 3
  char.current.width dw
  bpp dw
  master ds _sizeof_oopObjHash
  timer db  ;<--
  delay db
  charspeed db
  state dw
  busy dw
  counter dw
  vram.target.start dw
  vram.target.length dw
  wram.buffer.id db
  wram.buffer.start dw
  wram.buffer.size dw
  wram.buffer.index dw
  buffer dw
.endst
		 
;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  this INSTANCEOF vars
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES 0
.define CLASS.ZP_LENGTH zpLen

;ram buffers
.ramsection "packed vwf font buffer" bank 0 slot 1
  GLOBAL.vwfFontPacked ds $2000
  GLOBAL.vwfFontPacked.end ds 0
.ends

.base BSL
.bank BANK.PROGRAM

.include "src/include/vwf.include"
