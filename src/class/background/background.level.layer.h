.include "src/config/config.inc"

.def BACKGROUND.LINE.LENGTH TILEMAP.SIZE.X*TILEMAP.ENTRY.SIZE

.def BACKGROUND.WRAM.LENGTH BACKGROUND.LINE.LENGTH*3  ;one horizontal, one vertical buffer line


.enum 0
  BACKGROUND.LINE.HORIZONTAL ds BACKGROUND.LINE.LENGTH*2
  BACKGROUND.LINE.VERTICAL ds BACKGROUND.LINE.LENGTH
.ende

.define BACKGROUND.GENERIC.TILESIZE.X 64
.define BACKGROUND.GENERIC.TILESIZE.Y 32

.define BACKGROUND.DRAW.WIDTH 33
.define BACKGROUND.DRAW.HEIGHT 32

;.define BG.TILEMAP.SCROLL.LENGTH BACKGROUND.GENERIC.TILESIZE.X*BACKGROUND.GENERIC.TILESIZE.Y*2
.define BG.TILEMAP.SCROLL.LENGTH BACKGROUND.GENERIC.TILESIZE.X*BACKGROUND.GENERIC.TILESIZE.Y*2

.struct vars
  pos.layer dw
  pos.meta dw
  pos.x dw
  pos.y dw
  meta.current dw
  count.line dw
  count.target dw
  count.tile dw
  tile.config dw
  tilemap.pointer ds 3
  metamap.layer.pointer ds 3
  bg dw
  scrollfactor dw
  screen.current.x dw
  screen.current.y dw
  tile.current.x dw
  tile.current.y dw
  tile.last.x dw
  tile.last.y dw

.endst
		 
;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  background INSTANCEOF backgroundStruct
  this INSTANCEOF vars
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES (OBJECT.PROPERTIES.isLevelMember | OBJECT.PROPERTIES.isLevelSortable)
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

.base BSL
.bank BANK.PROGRAM

