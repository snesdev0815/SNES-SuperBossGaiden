.include "src/config/config.inc"

.def LEVEL.MAX.OBJECTS 128
.def LEVEL.MAX.LAYERS 4

.def LEVEL.OBJ_WINDOW 16
.def LEVEL.OBJ_WINDOW.LEFT -LEVEL.OBJ_WINDOW
.def LEVEL.OBJ_WINDOW.RIGHT SCREEN.SIZE.X+LEVEL.OBJ_WINDOW
.def LEVEL.OBJ_WINDOW.TOP -LEVEL.OBJ_WINDOW
.def LEVEL.OBJ_WINDOW.BOTTOM SCREEN.SIZE.Y+LEVEL.OBJ_WINDOW
.def LEVEL.OBJ_WINDOW.WIDTH SCREEN.SIZE.X+(2*LEVEL.OBJ_WINDOW)
.def LEVEL.OBJ_WINDOW.HEIGHT SCREEN.SIZE.Y+(2*LEVEL.OBJ_WINDOW)

.def LEVEL.SIZE.X 256*8
.def LEVEL.SIZE.Y 256*8
.export LEVEL.SIZE.X
.export LEVEL.SIZE.Y

.def METATILE.SIZE.X TILE.SIZE.X*16

.def LEVEL.TILE.ELEVATED.HEIGHT $1000
.export LEVEL.TILE.ELEVATED.HEIGHT

.def LEVEL.TILE.HAZARD.DAMAGE 1
.export LEVEL.TILE.HAZARD.DAMAGE

.def LEVEL.LAYER.FLAGS.LAYER0 1
.def LEVEL.LAYER.FLAGS.LAYER1 2
.def LEVEL.LAYER.FLAGS.LAYER2 4

.def LEVEL.CONVEYOR.SPEED $100
.export LEVEL.CONVEYOR.SPEED

.enum 0 export
  LEVEL.MAGIC dw    ;"LV"
  LEVEL.NAME ds 16      ;ascii-name of level
  LEVEL.TILESIZE.X dw    ;width in tiles (min $20, max $2000)
  LEVEL.TILESIZE.Y dw    ;height in tiles (min $1c, max $2000)
  LEVEL.BORDER.LEFT dw
  LEVEL.BORDER.TOP dw
  LEVEL.BORDER.RIGHT dw
  LEVEL.BORDER.BOTTOM dw
  LEVEL.MODE db
  LEVEL.IS_SUBLEVEL db
  LEVEL.SONG db
  LEVEL.LAYER.FLAGS db
  LEVEL.LAYER.FLAGS.LOWER dw
  LEVEL.LAYER.FLAGS.UPPER dw
  LEVEL.LAYER.FLAGS.STATUS dw  
  LEVEL.CGADSUB db
  LEVEL.COLOR_ADDITION db
  LEVEL.MISC.FLAGS dw
  LEVEL.HIDDEN_TREASURE.COUNT db
  LEVEL.SCROLLFACTOR.BG.LOWER db
  LEVEL.SCROLLFACTOR.BG.UPPER db
  LEVEL.SCROLLFACTOR.BG.STATUS db
  LEVEL.TIMER.GOLD dw
  LEVEL.TIMER.SILVER dw
  LEVEL.TIMER db
  LEVEL.SCRIPT.LOAD dw
  LEVEL.LAYER.COUNT db    ;number of maps in this level: 2-5 (collision,1-4 bg)
  LEVEL.OBJECT.COUNT db ;number of objects on map

  LEVEL.POINTER.TILESET ds 3  ;absolute pointer to tileset
  LEVEL.TILESET.LENGTH dw
  LEVEL.POINTER.TILESET_STATUS ds 3  ;absolute pointer to tileset
  LEVEL.TILESET_STATUS.LENGTH dw  
  LEVEL.POINTER.PALETTE dw  ;relative pointer to color palette
  LEVEL.POINTER.PALETTE_STATUS dw  ;relative pointer to color palette

  LEVEL.POINTER.OBJECT dw  ;relative pointer to first object, repeated for LEVEL.OBJECT.COUNT
  ;LEVEL.POINTER.MAP dw  ;repeated for LEVEL.MAP.COUNT, but position dependant on number of objects
.ende

.enum 0 export
  LEVEL.MODE.NORMAL db
.ende

.def LEVEL.AUTOSCROLL.SPEED.X $c0
.export LEVEL.AUTOSCROLL.SPEED.X

.def LEVEL.COLLISION.MODE.MASK $f
.def LEVEL.COLLISION.SLOPE.MASK $f0
.def LEVEL.COLLISION.ELEVATION.MASK $f00

.export LEVEL.COLLISION.MODE.MASK
.export LEVEL.COLLISION.SLOPE.MASK
.export LEVEL.COLLISION.ELEVATION.MASK

.def LEVEL.COLLISION.ELEVATION.PLATFORM $100
.export LEVEL.COLLISION.ELEVATION.PLATFORM

.enum 0
  LEVEL.LUT.POINTER ds 3
  LEVEL.NAME.POINTER dw
.ende

.def LEVEL.FLAG.PLAYER.NO_COLOR_MATH 1 << 0

.def LEVEL.MAGIC.VALUE $564c    ;"LV"

.def LEVEL.OBJMAP.SIZE.Y 240*8
.def LEVEL.OBJMAP.LENGTH 128*120  ;no objects in lower 16*8 pixel of level, can we get away with that?

.enum 0
  OBJECT.CLASS dw
  OBJECT.PARM.X.INDEX dw
  OBJECT.PARM.X.VALUE dw
  OBJECT.PARM.Y.INDEX dw
  OBJECT.PARM.Y.VALUE dw
.ende


.struct vars
  id dw
  pointer ds 3
  layer.count db
  object.count db
  palette.length dw
  palette.start dw
  palette.id db
  palette.startid db
  tileset.length dw
  tileset.start dw
  tileset.id db
  palette_status.length dw
  palette_status.start dw
  palette_status.id db
  palette_status.startid db
  tileset_status.length dw
  tileset_status.start dw
  tileset_status.id db
  layer.flags db
  layer.flags.lower dw
  layer.flags.upper dw
  layer.flags.status dw
  misc.flags dw
  cgadsub dw
  screen.x dw
  screen.y dw
  scrollfactor.layer.lower dw
  scrollfactor.layer.upper dw
  scrollfactor.layer.status dw
  song dw
  treasure.count dw
  objmap.length dw
  objmap.start dw
  objmap.id db
  objwindow.left db
  objwindow.right db
  objwindow.top db
  objwindow.bottom db
  tilemap.dimension.x dw
  timer.gold dw
  timer.silver dw
  object.current dw
  object.current.pointer dw
  object.current.arg.length dw
  object.current.args ds 2*OBJECT.CALL.ARGS.MAX
  persistency ds _sizeof_oopObjHash
  hud ds _sizeof_oopObjHash
  pause ds _sizeof_oopObjHash
  spc ds _sizeof_oopObjHash
  fixedColor ds _sizeof_oopObjHash
  hdma ds _sizeof_oopObjHash
  outbuffer ds 6
.endst
		 
;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  this INSTANCEOF vars
  this.layer.pointer INSTANCEOF oopObjHash LEVEL.MAX.LAYERS
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS (OBJECT.FLAGS.Present | OBJECT.FLAGS.Singleton)
.define CLASS.PROPERTIES OBJECT.PROPERTIES.isLevelSortable
.define CLASS.ZP_LENGTH zpLen

.def LEVEL.BITFLAG.NONE 0 << 0
.def LEVEL.BITFLAG.TORCH 1 << 0
.def LEVEL.BITFLAG.1 1 << 1
.def LEVEL.BITFLAG.2 1 << 2
.def LEVEL.BITFLAG.3 1 << 3
.def LEVEL.BITFLAG.4 1 << 4
.def LEVEL.BITFLAG.5 1 << 5
.def LEVEL.BITFLAG.6 1 << 6
.def LEVEL.BITFLAG.7 1 << 7
.def LEVEL.BITFLAG.8 1 << 8
.def LEVEL.BITFLAG.9 1 << 9
.def LEVEL.BITFLAG.10 1 << 10
.def LEVEL.BITFLAG.11 1 << 11
.def LEVEL.BITFLAG.12 1 << 12
.def LEVEL.BITFLAG.13 1 << 13
.def LEVEL.BITFLAG.14 1 << 14
.def LEVEL.BITFLAG.15 1 << 15

.export LEVEL.BITFLAG.TORCH
.export LEVEL.BITFLAG.1
.export LEVEL.BITFLAG.2
.export LEVEL.BITFLAG.3
.export LEVEL.BITFLAG.4
.export LEVEL.BITFLAG.5
.export LEVEL.BITFLAG.6
.export LEVEL.BITFLAG.7
.export LEVEL.BITFLAG.8
.export LEVEL.BITFLAG.9
.export LEVEL.BITFLAG.10 
.export LEVEL.BITFLAG.11 
.export LEVEL.BITFLAG.12 
.export LEVEL.BITFLAG.13 
.export LEVEL.BITFLAG.14 
.export LEVEL.BITFLAG.15 

;ram buffers
.ramsection "global level vars" bank 0 slot 1
LEVEL.GLOBAL.START ds 0
GLOBAL.level.bitflags dw
GLOBAL.acceleration.x dw
GLOBAL.acceleration.y dw
GLOBAL.watchdog ds _sizeof_oopObjHash
LEVEL.GLOBAL.END ds 0
GLOBAL.map.meta.collision.buffer ds $2000
GLOBAL.map.meta.collision.buffer.end ds 0
GLOBAL.map.meta.layer0.buffer ds $2000
GLOBAL.map.meta.layer0.buffer.end ds 0
GLOBAL.map.meta.layer1.buffer ds $2000
GLOBAL.map.meta.layer1.buffer.end ds 0
GLOBAL.map.meta.layer2.buffer ds $2000
GLOBAL.map.meta.layer2.buffer.end ds 0
.ends

.base BSL
.bank BANK.DATA

.ramsection "map static metamap ram buffers" bank 0 slot 4
GLOBAL.map.metatile.buffer ds $bc00 ;$8000 ;$e000
GLOBAL.map.metatile.buffer.end ds 0
.ends


.def RAM_UPPER $7f0000

.include "src/include/level.include"

.base BSL
.bank BANK.PROGRAM

