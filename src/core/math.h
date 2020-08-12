.include "src/config/config.inc"

.def MATH.0_PI 0
.def MATH.1_PI (math.lut.sin.LEN/2)/2
.def MATH.2_PI (math.lut.sin.LEN/2)

.export MATH.0_PI
.export MATH.1_PI
.export MATH.2_PI


.def MATH.000_DEG MATH.0_PI
.def MATH.045_DEG MATH.1_PI/4
.def MATH.090_DEG MATH.1_PI/2
.def MATH.135_DEG (MATH.1_PI/2)+(MATH.1_PI/4)
.def MATH.180_DEG MATH.1_PI
.def MATH.225_DEG MATH.1_PI+(MATH.1_PI/4)
.def MATH.270_DEG MATH.1_PI+(MATH.1_PI/2)
.def MATH.315_DEG MATH.1_PI+(MATH.1_PI/2)+(MATH.1_PI/4)
.def MATH.360_DEG MATH.2_PI

.export MATH.000_DEG
  .export MATH.045_DEG
    .export MATH.090_DEG
      .export MATH.135_DEG
        .export MATH.180_DEG
      .export MATH.225_DEG
    .export MATH.270_DEG
  .export MATH.315_DEG
.export MATH.360_DEG

.def MATH.ATAN2.MAX 127

;ram buffers
.ramsection "global vram_allocate vars" bank 0 slot 1
MATH.GLOBAL.START ds 0
GLOBAL.math.scratch ds 8
MATH.GLOBAL.END ds 0
.ends


.base BSL
.bank BANK.DATA

.section "math.luts.sine" superfree
  FILEINC math.lut.sin "data/math/sine.lut"
.ends
.section "math.luts.cosine" superfree
  FILEINC math.lut.cos "data/math/cosine.lut"
.ends
.section "math.luts.tangent" superfree
  FILEINC math.lut.tan "data/math/tangent.lut"
.ends
.section "math.luts.atan2" superfree
  FILEINC math.lut.atan2 "data/math/atan2.lut"
.ends

.section "math.lut.direction2angle" superfree
math.lut.direction2angle:
  .dw 0 ;x
  .dw MATH.000_DEG   ;right
  .dw MATH.180_DEG   ;left
  .dw 0 ;x
  .dw MATH.090_DEG ;down
  .dw MATH.045_DEG ;right down
  .dw MATH.135_DEG ;left down
  .dw 0 ;x
  .dw MATH.270_DEG ;up
  .dw MATH.315_DEG ;right up
  .dw MATH.225_DEG ;left up
  .dw 0 ;x
  .dw 0 ;x
  .dw 0 ;x
  .dw 0 ;x
  .dw 0 ;x

;both of these must follow in this order
math.lut.direction2angle.byte.horz:
  .db 0 ;x
  .db MATH.000_DEG   ;right
  .db MATH.180_DEG   ;left
  .db 0 ;x
  .db MATH.090_DEG ;down
  .db MATH.090_DEG ;right down
  .db MATH.090_DEG ;left down
  .db 0 ;x
  .db MATH.270_DEG ;up
  .db MATH.270_DEG ;right up
  .db MATH.270_DEG ;left up
  .db 0 ;x
  .db 0 ;x
  .db 0 ;x
  .db 0 ;x
  .db 0 ;x
math.lut.direction2angle.byte.vert:
  .db 0 ;x
  .db MATH.000_DEG   ;right
  .db MATH.180_DEG   ;left
  .db 0 ;x
  .db MATH.090_DEG ;down
  .db MATH.000_DEG ;right down
  .db MATH.180_DEG ;left down
  .db 0 ;x
  .db MATH.270_DEG ;up
  .db MATH.000_DEG ;right up
  .db MATH.180_DEG ;left up
  .db 0 ;x
  .db 0 ;x
  .db 0 ;x
  .db 0 ;x
  .db 0 ;x
.ends


.section "math.lut.angle2spriteDirection" superfree
math.lut.angle2spriteDirection:
  .dw SPRITE.DIRECTION.RIGHT
  .dw SPRITE.DIRECTION.RIGHT

  .dw SPRITE.DIRECTION.DOWN
  .dw SPRITE.DIRECTION.DOWN
  .dw SPRITE.DIRECTION.DOWN
  .dw SPRITE.DIRECTION.DOWN

  .dw SPRITE.DIRECTION.LEFT
  .dw SPRITE.DIRECTION.LEFT
  .dw SPRITE.DIRECTION.LEFT
  .dw SPRITE.DIRECTION.LEFT

  .dw SPRITE.DIRECTION.UP
  .dw SPRITE.DIRECTION.UP
  .dw SPRITE.DIRECTION.UP
  .dw SPRITE.DIRECTION.UP

  .dw SPRITE.DIRECTION.RIGHT
  .dw SPRITE.DIRECTION.RIGHT

.ends

.section "math.tile.normal.angle.lut" superfree
math.tile.normal.angle.lut:
  .db MATH.180_DEG,MATH.270_DEG,MATH.270_DEG,MATH.270_DEG,MATH.270_DEG,MATH.270_DEG,MATH.270_DEG,MATH.270_DEG
  .db MATH.180_DEG,MATH.180_DEG,MATH.270_DEG,MATH.270_DEG,MATH.270_DEG,MATH.270_DEG,MATH.270_DEG,MATH.000_DEG
  .db MATH.180_DEG,MATH.180_DEG,MATH.180_DEG,MATH.270_DEG,MATH.270_DEG,MATH.270_DEG,MATH.000_DEG,MATH.000_DEG
  .db MATH.180_DEG,MATH.180_DEG,MATH.180_DEG,MATH.180_DEG,MATH.270_DEG,MATH.000_DEG,MATH.000_DEG,MATH.000_DEG
  .db MATH.180_DEG,MATH.180_DEG,MATH.180_DEG,MATH.090_DEG,MATH.000_DEG,MATH.000_DEG,MATH.000_DEG,MATH.000_DEG
  .db MATH.180_DEG,MATH.180_DEG,MATH.090_DEG,MATH.090_DEG,MATH.090_DEG,MATH.000_DEG,MATH.000_DEG,MATH.000_DEG
  .db MATH.180_DEG,MATH.090_DEG,MATH.090_DEG,MATH.090_DEG,MATH.090_DEG,MATH.090_DEG,MATH.000_DEG,MATH.000_DEG
  .db MATH.090_DEG,MATH.090_DEG,MATH.090_DEG,MATH.090_DEG,MATH.090_DEG,MATH.090_DEG,MATH.090_DEG,MATH.000_DEG

.ends

.section "math.dec2hex.nibbles" superfree

hexToDecimal.nibble0:
  .dw 0,1,2,3,4,5,6,7,8,9,$10,$11,$12,$13,$14,$15
hexToDecimal.nibble1:
  .dw 0,$16,$32,$48,$64,$80,$96,$112,$128,$144,$160,$176,$192,$208,$224,$240
hexToDecimal.nibble2:
  .dw 0,$256,$512,$768,$1024,$1280,$1536,$1792,$2048,$2304,$2560,$2816,$3072,$3328,$3584,$3840
hexToDecimal.nibble3:
  .dw 0,$4096,$8192,0,0,0,0,0,0,0,0,0,0,0,0,0
.ends

.base BSL
.bank BANK.PROGRAM
