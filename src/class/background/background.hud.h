.include "src/config/config.inc"

.def BERZERK.TARGET.ROW0 2*(32*22+3)
.def BERZERK.TARGET.ROW1 2*(32*23+3)
.def BERZERK.TARGET.ROW2 2*(32*24+3)

.def BERZERK.TARGET.LENGTH 8
.def SIDEKICK.TARGET.LENGTH 4

.def TIMER.TARGET.FRAME 2*(32*22+26)
.def TIMER.TARGET.SECOND 2*(32*22+21)
.def TIMER.TARGET.MINUTE 2*(32*22+16)

.def BERZERK.SOURCE.EMPTY 2*32*31
.def BERZERK.SOURCE.FULL 2*(32*31+8)

.def TIMER.SOURCE 2*(32*30+12)

.def TIMER.TILE.0 2*(0)
.def TIMER.TILE.1 2*(0+1)
.def TIMER.TILE.2 2*(32+0)
.def TIMER.TILE.3 2*(32+1)

.def MEDAL.SOURCE 2*(32*31+0)
.def MEDAL.TARGET 2*(32*15+12)

.def TIMER_RESULT.TARGET.FRAME 2*(32*13+18)
.def TIMER_RESULT.TARGET.SECOND 2*(32*13+15)
.def TIMER_RESULT.TARGET.MINUTE 2*(32*13+12)

.def HUD.LEVEL.DMA.SOURCE  2*(32*21)
.def HUD.LEVEL.DMA.SIZE (32*4)*2
.def HUD.REPORT.DMA.SIZE $800

.def HUD.SIDEKICK.SOURCE.Y 2*(32*28)

.def HUD.SIDEKICK.SOURCE.VOID 0
.def HUD.SIDEKICK.SOURCE.CONNECT_JOYPAD.X 2*0
.def HUD.SIDEKICK.SOURCE.PRESS_START.X 2*14
.def HUD.SIDEKICK.SOURCE.DISK_KUN.X 2*20
.def HUD.SIDEKICK.SOURCE.PARABO.X 2*26

.def HUD.SIDEKICK.TARGET.Y 2*(32*21)

.def HUD.SIDEKICK.TARGET.DISK_KUN.X 2*14
.def HUD.SIDEKICK.TARGET.PARABO.X 2*23

.enum 0
  HUD.STATE.LEVEL db
  HUD.STATE.REPORT db
.ende

.enum 0
  HUD.RESULT.GOLD db
  HUD.RESULT.SILVER db
  HUD.RESULT.BRONZE db
.ende

.enum 0 export
  HUD.SIDEKICK.STATE.DISABLED db
  HUD.SIDEKICK.STATE.OFF db
  HUD.SIDEKICK.STATE.ON db
.ende

.struct vars
  bg dw
  state dw
  mode dw
  mode.last dw
  value dw
  value1 dw
  value2 dw
  value3 dw
  player.state.0 dw
  player.state.1 dw
  player.state.2 dw
  player.state.3 dw
  obj.hdma ds _sizeof_oopObjHash
  obj.palette ds _sizeof_oopObjHash
  obj.hdmapal ds _sizeof_oopObjHash
  obj.timerpal ds _sizeof_oopObjHash
  obj.medal ds _sizeof_oopObjHash
  dirty dw
  disabled dw
  timer dw
  timer.gold dw
  timer.silver dw
  frame dw
  second dw
  minute dw
  timerpal.current dw
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
.define CLASS.FLAGS (OBJECT.FLAGS.Present | OBJECT.FLAGS.Singleton)
.define CLASS.PROPERTIES OBJECT.PROPERTIES.isLevelSortable
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

.base BSL
.bank BANK.DATA

.section "sidekick target" superfree
hud.sidekick.source:
  .dw 0 ;player
  .dw HUD.SIDEKICK.SOURCE.DISK_KUN.X + HUD.SIDEKICK.SOURCE.Y
  .dw HUD.SIDEKICK.SOURCE.PARABO.X + HUD.SIDEKICK.SOURCE.Y
  .dw 0 ;dummy

hud.sidekick_bar.target:
  .dw 0 ;player
  .dw HUD.SIDEKICK.TARGET.DISK_KUN.X + HUD.SIDEKICK.TARGET.Y + (2*(32*2+1))
  .dw HUD.SIDEKICK.TARGET.PARABO.X + HUD.SIDEKICK.TARGET.Y + (2*(32*2+1))
  .dw 0 ;dummy

hud.sidekick.target:
  .dw 0 ;player
  .dw HUD.SIDEKICK.TARGET.DISK_KUN.X + HUD.SIDEKICK.TARGET.Y
  .dw HUD.SIDEKICK.TARGET.PARABO.X + HUD.SIDEKICK.TARGET.Y
  .dw 0
.ends

.base BSL
.bank BANK.PROGRAM
