.include "src/config/config.inc"

.def BITFLAG.PERSISTENT.COUNT 8

.def SAVE_SLOT.DEFAULT 0
.export SAVE_SLOT.DEFAULT

;persistent flags
.enum 0 export
  ;FLAG.PERSISTENT.NONE db
  FLAG.PERSISTENT.PLAYER_ENABLE.0 db
  FLAG.PERSISTENT.PLAYER_ENABLE.1 db
  FLAG.PERSISTENT.PLAYER_ENABLE.2 db
  FLAG.PERSISTENT.GAME_BEATEN db
  FLAG.PERSISTENT.EASTER_EGG db
  FLAG.PERSISTENT.EASTER_EGG.1 db
  FLAG.PERSISTENT.EASTER_EGG.2 db
  FLAG.PERSISTENT.EASTER_EGG.3 db
  FLAG.PERSISTENT.MAX ds 0
.ende

.struct vars
  magic dw
  chsum db
  chsum.xor db
  playtime.second db
  playtime.minute db
  playtime.hour db
  bitflag ds BITFLAG.PERSISTENT.COUNT/8
  max ds 0
  tmp dw
.endst

.def FLASH.MX29F400CB.ID $ABC2

.def PERSISTENCY.SLOT.LENGTH _sizeof_vars
.def PERSISTENCY.SLOT.COUNT 2
.export PERSISTENCY.SLOT.COUNT
.def PERSISTENCY.SLOT.MAGIC 1338

.ramsection "global.flash.code" bank 0 slot 1
  GLOBAL.flash.code ds $100
.ends

;sram, quick hack
.ramsection "sram slots" bank 0 slot 3
  persistency.sram.slot INSTANCEOF vars PERSISTENCY.SLOT.COUNT
.ends


.enum 0 export
/*
  PERSISTENCY.SLOT.ID db
  PERSISTENCY.SLOT.SAVE_POINT db
*/  
  PERSISTENCY.SLOT.PLAYTIME.SECOND db
  PERSISTENCY.SLOT.PLAYTIME.MINUTE db
  PERSISTENCY.SLOT.PLAYTIME.HOUR db
/*  
  PERSISTENCY.SLOT.LEVEL db
  PERSISTENCY.SLOT.EXP db
  PERSISTENCY.SLOT.HP db
  PERSISTENCY.SLOT.MONEY db
  PERSISTENCY.SLOT.QUOTA.PERFECT db
  PERSISTENCY.SLOT.QUOTA.OK db
  PERSISTENCY.SLOT.QUOTA.MISS db
*/  
  PERSISTENCY.SLOT.BITFLAG db

  PERSISTENCY.SLOT.MAX ds 0
.ende

;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  this.pointer ds 3
  this.id db
  this.fps dw
  this.playtime.frame db
  this INSTANCEOF vars
zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS (OBJECT.FLAGS.Present | OBJECT.FLAGS.Singleton)
.define CLASS.PROPERTIES 0
.define CLASS.ZP_LENGTH zpLen

.base BSL
.bank BANK.DATA

.section "flash byte" superfree
flash.saveByte:
  .db $ff ;flash bits can only be set from 1 to 0, not to 0 to 1 without erasing, so we have to init all bits to 1
.ends


.section "sram slot lut" superfree
persistency.sram.slot.lut:
  .dw (persistency.sram.slot.1 &$ffff)
  .db (persistency.sram.slot.1 >> 16 &$ff)
  .dw (persistency.sram.slot.2 &$ffff)
  .db (persistency.sram.slot.2 >> 16 &$ff)
.ends

.base BSL
.bank BANK.PROGRAM