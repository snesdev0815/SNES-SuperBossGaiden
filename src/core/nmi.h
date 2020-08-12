.include "src/config/config.inc"

.def DMA_CHANNEL_COUNT 8

.struct dmaChannelBuffer
 DMAP		db
 DMADEST	db
 DMASRCL	db
 DMASRCH	db
 DMASRCB	db
 DMALENL	db
 DMALENH	db
 DMALENB	db
 HDMATBLL	db
 HDMATBLH	db
 HDMACNT	db
 VOID		ds 5
.endst

.ramsection "global vars nmi" bank 0 slot 5
NmiGlobalVarsStrt ds 0

SetIni	db
window12Sel	db
window34Sel	db
window1Left	db
window1Right db
window2Left	db
window2Right db
windowBGLogic	db
windowObjLogic db
MainScreen db
SubScreen db
windowMainscreen	db
windowSubscreen db
colorAdditionSelect db
CgadsubConfig db
windowObjSel	db
ScreenMode db
mosaicSetting	db
BG1TilemapVram db
BG2TilemapVram db
BG3TilemapVram db
BG4TilemapVram db
BGTilesVram12 db
BGTilesVram34 db
FixedColourB db
FixedColourG db
FixedColourR db
xScrollBG1 dw
yScrollBG1 dw
xScrollBG2 dw
yScrollBG2 dw
xScrollBG3 dw
yScrollBG3 dw
ObjSel db

;buffers that change only once at start of frame - for indirect hdma
GLOBALS.nmi.frame.busy dw
GLOBALS.nmi.busy dw
GLOBALS.nmi.refreshRate dw
GLOBALS.nmi.frameOver	dw

GLOBAL.DMA_BUFFER INSTANCEOF dmaChannelBuffer DMA_CHANNEL_COUNT
GLOBAL.HDMA.CHANNEL.ENABLE db	;flags that should be written next nmi
GLOBAL.HDMA.CHANNEL.ENABLE.CURRENT db	;flags that have actually been written during last nmi

FrameCounter	dw

CpuUsageScanline			db
ScreenBrightness 			db
GLOBAL.interruptFlags	db

NmiGlobalVarsEnd ds 0
.ends


.base BSL
.bank BANK.PROGRAM
