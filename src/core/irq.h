.include "src/config/config.inc"

.def IRQ.POSITION.Y.MAX 224


.ramsection "global vars irq" bank 0 slot 1
GLOBAL.irq.xpos   dw
GLOBAL.irq.ypos   dw
GLOBAL.irq.callback   dw
GLOBAL.irq.buffer ds 8
.ends


.base BSL
.bank BANK.PROGRAM
