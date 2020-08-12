.include "src/config/config.inc"

;defines

.def OAM.TABLE.0.START 0
.def OAM.TABLE.0.LENGTH $200
.def OAM.TABLE.1.START $200
.def OAM.TABLE.1.LENGTH $20


;ram buffers
.ramsection "global dmafifo vars, lower ram mirror" bank 0 slot 5
GLOBAL.currentOamSlot dw
GLOBAL.oamUploadFlag dw
.ends

.ramsection "global dmafifo vars" bank 0 slot 1
OAM.GLOBAL.START ds 0

GLOBAL.oamClearFlag dw
GLOBAL.oam.vram.id db
GLOBAL.oam.vram.start dw
GLOBAL.oam.graphics.default.obj ds _sizeof_oopObjHash
GLOBAL.oam.graphics.default.tileconfig dw
GLOBAL.oam.graphics.default.tileconfigBig dw

OAM.GLOBAL.END ds 0
.ends

.ramsection "oam buffer zp" bank 0 slot 6
	GLOBAL.oamBuffer INSTANCEOF oamSlot OAM_SLOTS
	GLOBAL.oamBuffer.end ds 0
	GLOBAL.oamBufferHi ds OAM_SLOTS
	GLOBAL.oamBufferHi.end ds 0
.ends

.base BSL
.bank BANK.PROGRAM
