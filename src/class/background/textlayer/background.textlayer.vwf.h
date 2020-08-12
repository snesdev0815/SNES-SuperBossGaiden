.include "src/config/config.inc"

.def BG.VWF.PALETTE.LENGTH 32

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  animation INSTANCEOF animationStruct
  background INSTANCEOF backgroundStruct
  this INSTANCEOF vwfLayerStruct
  this.tilemap.first dw
  this.tilemap.last dw
  this.busy dw
  this.tiles.uploaded dw
  this.clearCounter dw
  this.level.layer ds _sizeof_oopObjHash
  this.bgcolor ds _sizeof_oopObjHash
  zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS (OBJECT.FLAGS.Present | OBJECT.FLAGS.Singleton)
.define CLASS.PROPERTIES OBJECT.PROPERTIES.isLevelSortable
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

.base BSL
.bank BANK.PROGRAM

.section "emptyVwfTile" superfree
emptyVwfTile:
    .rept 32
      .db 0
    .endr
emptyVwfTile.end:
.ends


.base BSL
.bank BANK.PROGRAM