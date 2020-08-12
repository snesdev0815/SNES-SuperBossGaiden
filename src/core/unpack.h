.include "src/config/config.inc"

.def LZ4.MAGIC.LO $2204
.def LZ4.MAGIC.HI $184d

.export LZ4.MAGIC.LO
.export LZ4.MAGIC.HI

.def TARGET.BANK $7f

.def UNPACK.TARGET $7f0000
.export UNPACK.TARGET

.enum 0
	LZ4.MAGIC_NUMBER ds 4
	LZ4.FLG db
	LZ4.BD db
	LZ4.CONTENT_SIZE ds 8
	LZ4.HEADER_CHECKSUM db
	LZ4.BLOCK_SIZE ds 4
	LZ4.DATA ds 0
.ende

.def LZ4.FLG.VERSION 3 << 6
.def LZ4.FLG.CONTENT_SIZE 1 << 6

.ramsection "global.unpack" bank 0 slot 1
  GLOBAL.unpack.dummy dw
  GLOBAL.unpack.code ds $100
.ends

.def UNPACK.BUFER.SIZE $4400

.ramsection "generic unpack buffer" bank 0 slot 4
  GLOBAL.unpack.buffer ds UNPACK.BUFER.SIZE
.ends

.base BSL
.bank BANK.PROGRAM
.org 0

