
.MEMORYMAP
DEFAULTSLOT 0
SLOTSIZE $8000
SLOT 0 $8000	;lorom

SLOTSIZE $10000-$2000
SLOT 1 $7e2000	;ram in bank $7e

SLOTSIZE $100
SLOT 2 $0	;zero-page ram. 16=debug value to check if all routines relocate properly

;small lorom sram
SLOTSIZE $800
SLOT 3 $700000

SLOTSIZE $10000
SLOT 4 $7f0000  ;upper ram bank

SLOTSIZE $1c80
SLOT 5 $100	;upper zero-page ram. used for object heap. must start above $ff so that pointer size can be deduced correctly

SLOTSIZE $280
SLOT 6 $1D80	;oam ram buffer
.ENDME

.def IS_3D 0 ;pseudo-3d or 2d side view?

.def DEBUG 0

.def HANDLE_ERRORS 0

.def USE_FLASH_SAVE 0	;if enabled, game expects to reside on mx29f040 4mbit flash ROM and will save to it aswell, no need for additional SRAM. However, game will not boot if it fails to detect flash ROM. Also, saving progress will corrupt header checksum. This is expected behavior.

.def ROMBANKS 16	;3.

.ROMBANKSIZE $8000    ; Every ROM bank is 64 KBytes in size, also necessary.
.ROMBANKS ROMBANKS           ; 256Mbits

.EMPTYFILL 0

;kernel defines:
;bank defines
.def BSL		$80
.def ROM		$80
.def ROM.BANKED $00
.def LOROM $80
.def EXROM $0
.def RAM		$7e
.def RAM2		RAM+1
.def REGS		$00

.def BANK.PROGRAM 0
.def BANK.PROGRAM_EXT 1
.def BANK.DATA 1

.def BANK0_LOROM		$0000

;header defines
.def SNESHEADER.TITLE $7fc0

.include "src/config/globals.inc"

