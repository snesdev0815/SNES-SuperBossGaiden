.include "src/config/config.inc"

.def VWF.PARSER.LINES 3
.def VWF.PARSER.LINELENGTH 32
.def VWF.PARSER.BUFFER.LENGTH VWF.PARSER.LINELENGTH*VWF.PARSER.LINES*2

.export VWF.PARSER.LINES
.export VWF.PARSER.LINELENGTH

.struct parserLine
  index dw
.endst

.struct vars
  context ds _sizeof_oopObjHash
  pos.x dw
  pos.y dw
  linewidth dw
  string.id dw
  font.id dw
  font.pointer ds 3
  char.current dw
  linechar.current dw
  allocation.start dw
  wram.buffer.id db
  wram.buffer.start dw
  ;wram.buffer.index dw
  arg.0 dw
  arg.1 dw
  arg.2 dw
  arg.3 dw
  arg.4 dw
  arg.5 dw
.endst
		 
;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  this INSTANCEOF vars
  line INSTANCEOF parserLine VWF.PARSER.LINES  
  renderer INSTANCEOF oopObjHash VWF.PARSER.LINES  
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES 0
.define CLASS.ZP_LENGTH zpLen

.base BSL
.bank BANK.DATA

;character conversion lut, same for all fonts
.Section "vwfCharLUT" superfree
vwfChar.ascii.LUT:
  .incbin "data/text/charset_V.a2h"
vwfChar.ascii.LUT.end:
.ends

.base BSL
.bank BANK.PROGRAM
