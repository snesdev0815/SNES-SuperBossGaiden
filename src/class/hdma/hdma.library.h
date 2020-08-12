.include "src/config/config.inc"

		 
.def HDMA.CHANNEL.ALLOCATED $80

.enum 0
  HDMA_ANIMATION.TYPE.WINDOW db
  HDMA_ANIMATION.TYPE.GRADIENT_PALETTE db
  HDMA_ANIMATION.TYPE.GRADIENT_BG_COLOR db
  HDMA_ANIMATION.TYPE.SCROLL db
  HDMA_ANIMATION.TYPE.MAX ds 0
.ende

;zp-vars,just a reference
.enum 0
  iterator INSTANCEOF iteratorStruct
  hdma INSTANCEOF hdmaStruct
zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES 0
.define CLASS.ZP_LENGTH zpLen

.base BSL
.bank BANK.PROGRAM

.include "src/include/hdma.include"

