
.macro AX16
  .ACCU 16
  .INDEX 16
.if DEBUG == 1  
  jsl core.oop.assertAx16
.endif  
.endm

.macro A8
  .ACCU 8
  .INDEX 16
.if DEBUG == 1  
  jsl core.oop.assertA8
.endif
.endm

.macro LSR_SIGNED
	cmp.w #$8000
	ror a
.endm

.macro ASL_SIGNED
	cmp.w #$8000
	bcs _asl_neg\@
		asl a
		bra _asl_done\@ps65
_asl_neg\@:
		asl a
		ora.w #$8000
_asl_done\@:

.endm

.macro HASH_POINTER_TO_INDEX
	lsr a
	lsr a
	lsr a
	lsr a
.endm

.macro INDEX_TO_HASH_POINTER
	and.w #$ff
	asl a
	asl a
	asl a
	asl a
.endm

;dispatch obj method. parameters: \1 pointer to obj hash \2 method .ptr to execute \3-\9 parameters(optional)
;assumes accu 16bit
.macro CALL

.if NARGS < 2
	.fail
.endif

ldx #\2
ldy #\1

.ifdefm \9
pea \9
.endif

.ifdefm \8
pea \8
.endif

.ifdefm \7
pea \7
.endif

.ifdefm \6
pea \6
.endif

.ifdefm \5
pea \5
.endif

.ifdefm \4
pea \4
.endif


.ifdefm \3
pea \3
.endif

jsr core.object.call

.ifdefm \9
pla
.endif

.ifdefm \8
pla
.endif

.ifdefm \7
pla
.endif

.ifdefm \6
pla
.endif

.ifdefm \5
pla
.endif

.ifdefm \4
pla
.endif

.ifdefm \3
pla
.endif

.endm

;dispatch obj method. parameters: \1 pointer to obj hash \2 method .ptr to execute \3-\9 parameters(optional)
;assumes accu 16bit
.macro FASTCALL

.if NARGS < 2
	.fail
.endif

ldx #\2
ldy #\1

.ifdefm \9
pea \9
.endif

.ifdefm \8
pea \8
.endif

.ifdefm \7
pea \7
.endif

.ifdefm \6
pea \6
.endif

.ifdefm \5
pea \5
.endif

.ifdefm \4
pea \4
.endif


.ifdefm \3
pea \3
.endif

jsr core.object.call

.ifdefm \9
pla
.endif

.ifdefm \8
pla
.endif

.ifdefm \7
pla
.endif

.ifdefm \6
pla
.endif

.ifdefm \5
pla
.endif

.ifdefm \4
pla
.endif

.ifdefm \3
pla
.endif

.endm

;dispatch obj method. parameters: \1 pointer to obj hash \2 method .ptr to execute \3-\9 parameters(optional)
;assumes accu 16bit
.macro SCRIPT_CALL

.if NARGS < 2
  .fail
.endif

ldx #\2
ldy #\1

.ifdefm \9
pea \9
.endif

.ifdefm \8
pea \8
.endif

.ifdefm \7
pea \7
.endif

.ifdefm \6
pea \6
.endif

.ifdefm \5
pea \5
.endif

.ifdefm \4
pea \4
.endif


.ifdefm \3
pea \3
.endif

jsl extend.object.call

.ifdefm \9
pla
.endif

.ifdefm \8
pla
.endif

.ifdefm \7
pla
.endif

.ifdefm \6
pla
.endif

.ifdefm \5
pla
.endif

.ifdefm \4
pla
.endif

.ifdefm \3
pla
.endif

.endm



;dispatch obj method, but only if object exists. parameters: \1 pointer to obj hash \2 method .ptr to execute \3-\9 parameters(optional)
;assumes accu 16bit
.macro TRY

.if NARGS < 2
  .fail
.endif

ldx #\2
jsr core.object.exists
bcc _try_catch\@

ldx #\2
ldy #\1

.ifdefm \9
pea \9
.endif

.ifdefm \8
pea \8
.endif

.ifdefm \7
pea \7
.endif

.ifdefm \6
pea \6
.endif

.ifdefm \5
pea \5
.endif

.ifdefm \4
pea \4
.endif


.ifdefm \3
pea \3
.endif

jsr core.object.call

.ifdefm \9
pla
.endif

.ifdefm \8
pla
.endif

.ifdefm \7
pla
.endif

.ifdefm \6
pla
.endif

.ifdefm \5
pla
.endif

.ifdefm \4
pla
.endif

.ifdefm \3
pla
.endif
_try_catch\@:
.endm

;create reference pointer to routine so that it can be properly be jumped at by jsr(0),x. only used for callbacks so far. should be used inside seperate callback section
.macro REGISTER_CALLBACK
.if NARGS != 1
	.fail
.endif
\1.CLB:
.dw \1
.endm

;create instance of class. parameters: \1 class pointer \2 pointer to obj hash \3 parameter to pass to class init routine(optional)
.macro NEW

.if NARGS < 2
	.fail
.endif

ldy #\1
ldx #\2


.ifdefm \9
pea \9
.endif

.ifdefm \8
pea \8
.endif

.ifdefm \7
pea \7
.endif

.ifdefm \6
pea \6
.endif

.ifdefm \5
pea \5
.endif

.ifdefm \4
pea \4
.endif


.ifdefm \3
pea \3
.endif

jsr core.object.create

.ifdefm \9
pla
.endif

.ifdefm \8
pla
.endif

.ifdefm \7
pla
.endif

.ifdefm \6
pla
.endif

.ifdefm \5
pla
.endif

.ifdefm \4
pla
.endif

.ifdefm \3
pla
.endif


.endm


;create instance of class. parameters: \1 class pointer \2 pointer to obj hash \3 parameter to pass to class init routine(optional)
.macro NEW_TRY

.if NARGS < 2
	.fail
.endif

ldy #\1
ldx #\2


.ifdefm \9
pea \9
.endif

.ifdefm \8
pea \8
.endif

.ifdefm \7
pea \7
.endif

.ifdefm \6
pea \6
.endif

.ifdefm \5
pea \5
.endif

.ifdefm \4
pea \4
.endif


.ifdefm \3
pea \3
.endif

jsr core.object.create.try

.ifdefm \9
pla
.endif

.ifdefm \8
pla
.endif

.ifdefm \7
pla
.endif

.ifdefm \6
pla
.endif

.ifdefm \5
pla
.endif

.ifdefm \4
pla
.endif

.ifdefm \3
pla
.endif


.endm


;create instance of class. parameters: \1 class pointer \2 pointer to obj hash \3 parameter to pass to class init routine(optional)
.macro SCRIPT_NEW

.if NARGS < 2
  .fail
.endif

ldy #\1
ldx #\2


.ifdefm \9
pea \9
.endif

.ifdefm \8
pea \8
.endif

.ifdefm \7
pea \7
.endif

.ifdefm \6
pea \6
.endif

.ifdefm \5
pea \5
.endif

.ifdefm \4
pea \4
.endif


.ifdefm \3
pea \3
.endif

jsl extend.object.create

.ifdefm \9
pla
.endif

.ifdefm \8
pla
.endif

.ifdefm \7
pla
.endif

.ifdefm \6
pla
.endif

.ifdefm \5
pla
.endif

.ifdefm \4
pla
.endif

.ifdefm \3
pla
.endif


.endm

;create instance of class. Fail silently. parameters: \1 class pointer \2 pointer to obj hash \3 parameter to pass to class init routine(optional)
.macro SCRIPT_NEW_TRY

.if NARGS < 2
  .fail
.endif

ldy #\1
ldx #\2


.ifdefm \9
pea \9
.endif

.ifdefm \8
pea \8
.endif

.ifdefm \7
pea \7
.endif

.ifdefm \6
pea \6
.endif

.ifdefm \5
pea \5
.endif

.ifdefm \4
pea \4
.endif


.ifdefm \3
pea \3
.endif

jsl extend.object.create.try

.ifdefm \9
pla
.endif

.ifdefm \8
pla
.endif

.ifdefm \7
pla
.endif

.ifdefm \6
pla
.endif

.ifdefm \5
pla
.endif

.ifdefm \4
pla
.endif

.ifdefm \3
pla
.endif



.endm
;terminate script, do some garbage collection aswell
.macro DIE
	jmp terminateScript
.endm

;terminate call, don't do any garbage collection
.macro RETURN
	rts

.endm

;minimal delay to even out processing load across multiple frames to avoid frame drops
.macro DELAY
  LOOP 1
  LOOP
.endm

;wait for equation(two variables) to become true. If not true, save current PC and return, then try again next frame
.macro WAIT
.if NARGS != 3
	.fail
.endif
	jsr script.savePosition
	lda.w \1
	cmp.w \3

.if ">" == \2
	bcc Wait\@
	
WaitOkStep\@:
	bne WaitOk\@
.endif

.if ">=" == \2
	bcs WaitOk\@
.endif

.if "<=" == \2
	beq WaitOk\@
	bcc WaitOk\@
.endif

.if "<" == \2
	bcc WaitOk\@
.endif

.if "==" == \2
	beq WaitOk\@
.endif

.if "!=" == \2
	bne WaitOk\@
.endif

Wait\@:
	rts
	
WaitOk\@:
.endm

;wait for equation(two variables) to become true. If not true, save current PC and return, then try again next frame
.macro WAIT_IMMEDIATE
.if NARGS != 3
	.fail
.endif
	jsr script.savePosition
	lda.w \1
	cmp.w #\3

.if ">" == \2
	bcc WaitI\@
	
WaitIOkStep\@:
	bne WaitIOk\@
.endif

.if ">=" == \2
	bcs WaitIOk\@
.endif

.if "<=" == \2
	beq WaitIOk\@
	bcc WaitIOk\@
.endif

.if "<" == \2
	bcc WaitIOk\@
.endif

.if "==" == \2
	beq WaitIOk\@
.endif

.if "!=" == \2
	bne WaitIOk\@
.endif

WaitI\@:
	rts
	
WaitIOk\@:
.endm

;2 parameters: song file, name alias
.macro SONG
.if NARGS != 2
	.fail
.endif

.Section "\1.song.sect" superfree
  Song.\2:
      .incbin "build/data/songs/\1.spcmod.lz4"
  Song.\2.EOF:
.ends
.endm

.macro SONGPATTERN
.if NARGS != 1
	.fail
.endif

.Section "\1.songpattern.sect" superfree
  Songpattern.\1:
      .incbin "data/songpatterns/\1.pattern"
  Songpattern.\1.EOF:
.ends
.endm

;params: 1=target label
.macro LEVEL

PtrLonglevelLUT\@:
.if NARGS == 1
  .dw \1
  .db :\1
.endif
.if NARGS == 2
  .dw \2
  .db :\2
.endif
  .dw 0
  .db 0 ;void dummy
.ifndef \1.PTR  ;define only once 
  .define "\1.PTR" (PtrLonglevelLUT\@ - levelLUT )/6
  .export \1.PTR
.endif
.endm



;creates a 3-byte pointer and a definition of pointernumber in table: label.PTR
;params: 1=pointer table base 2=target label
.macro PTRLONG
PtrLong\1\@:
	.dw \2
	.db :\2 
.ifndef \2.PTR	;define only once 
	.define "\2.PTR" (PtrLong\1\@ - \1 )/3
	.export \2.PTR
.endif
.endm


;creates a 2-byte pointer and a definition of pointernumber in table: label.PTR
;params: 1=pointer table base 2=target label
.macro PTRNORM
PtrNorm\1\@:
	.dw \2
.ifndef \2.PTR	;define only once 
	.define "\2.PTR" (PtrNorm\1\@ - \1 )/2
	.export \2.PTR
.endif
.endm

;creates a 2-byte pointer and a definition of pointernumber in table: label.PTR
;params: 1=pointer table base 2=target label
.macro PTRWORD
PtrWord\1\@:
	.dw \2 
	.define "\2.PTRWORD" (PtrWord\1\@ - \1 )/2
	.export \2.PTRWORD
.endm


;creates oop object class. parameters: 1=class name 2-9: additional routines
;object id = \1.OBJID
.macro CLASS
	.if NARGS < 1
		.printt "Fatal error in macro CLASS, not enough arguments for class \n"
		.fail
	.endif
  .ifdef CLASS.IMPLEMENTS
    .if CLASS.IMPLEMENTS == interface.dimension
    \1.CLS:
    _relative\1:
	    .db CLASS.FLAGS
	    .db OBJID.\1	;object id
	    .db CLASS.ZP_LENGTH	;zero page ram buffer length
	    .dw CLASS.PROPERTIES	;default properties, disabled for now.
	    .db NARGS + 3 + 2 + 5 ;number of routines
	
	    .define \1.init.MTD 0
	    .export \1.init.MTD
      ;fall back to default interface routine if not defined in current class scope
      .ifndef __init
        .dw interface.default.init
      .else
	      .dw _init
      .endif

	    .define \1.play.MTD 1
	    .export \1.play.MTD
      ;fall back to default interface routine if not defined in current class scope
      .ifndef __play
        .dw interface.default.play
      .else
	      .dw _play
      .endif

        .define \1.pause.MTD 2
        .export \1.pause.MTD
      ;fall back to default interface routine if not defined in current class scope
      .ifndef __pause
        .dw interface.default.pause
      .else
          .dw _pause
      .endif

        .define \1.disable.MTD 3
        .export \1.disable.MTD
      ;fall back to default interface routine if not defined in current class scope
      .ifndef __disable
        .dw interface.default.disable
      .else
          .dw _disable
      .endif

        .define \1.enable.MTD 4
        .export \1.enable.MTD
      ;fall back to default interface routine if not defined in current class scope
      .ifndef __enable
        .dw interface.default.enable
      .else
          .dw _enable
      .endif

	    .define \1.kill.MTD 5
	    .export \1.kill.MTD
      ;fall back to default interface routine if not defined in current class scope
      .ifndef __kill
        .dw interface.default.kill
      .else
	      .dw _kill
      .endif

	    .define \1.setPosition.MTD 6
	    .export \1.setPosition.MTD
      ;fall back to default interface routine if not defined in current class scope
      .ifndef __setPosition
        .dw interface.dimension.setPosition
      .else
	      .dw _setPosition
      .endif

	    .define \1.getPosition.MTD 7
	    .export \1.getPosition.MTD
      ;fall back to default interface routine if not defined in current class scope
      .ifndef __getPosition
        .dw interface.dimension.getPosition
      .else
	      .dw _getPosition
      .endif

	    .define \1.getCollisionBasepoint.MTD 8
	    .export \1.getCollisionBasepoint.MTD
      ;fall back to default interface routine if not defined in current class scope
      .ifndef __getCollisionBasepoint
        .dw interface.dimension.getCollisionBasepoint
      .else
	      .dw _getCollisionBasepoint
      .endif

	    .define \1.getSize.MTD 9
	    .export \1.getSize.MTD
      ;fall back to default interface routine if not defined in current class scope
      .ifndef __getSize
        .dw interface.dimension.getSize
      .else
	      .dw _getSize
      .endif

	    .define \1.translate.MTD 10
	    .export \1.translate.MTD
      ;fall back to default interface routine if not defined in current class scope
      .ifndef __translate
        .dw interface.dimension.translate
      .else
	      .dw _translate
      .endif

	    .ifdefm \2
		    .define \1.\2.MTD 11
		    .export \1.\2.MTD
		    .dw _\2
	    .endif

	    .ifdefm \3
		    .define \1.\3.MTD 12
		    .export \1.\3.MTD
		    .dw _\3
	    .endif
	
	    .ifdefm \4
		    .define \1.\4.MTD 13
		    .export \1.\4.MTD
		    .dw _\4
	    .endif
	
	    .ifdefm \5
		    .define \1.\5.MTD 14
		    .export \1.\5.MTD
		    .dw _\5
	    .endif

	    .ifdefm \6
		    .define \1.\6.MTD 15
		    .export \1.\6.MTD
		    .dw _\6
	    .endif

	    .ifdefm \7
		    .define \1.\7.MTD 16
		    .export \1.\7.MTD
		    .dw _\7
	    .endif

	    .ifdefm \8
		    .define \1.\8.MTD 17
		    .export \1.\8.MTD
		    .dw _\8
	    .endif

	    .ifdefm \9
		    .define \1.\9.MTD 18
		    .export \1.\9.MTD
		    .dw _\9
	    .endif
    .endif

  .else
  \1.CLS:
  _relative\1:
	  .db CLASS.FLAGS
	  .db OBJID.\1	;object id
	  .db CLASS.ZP_LENGTH	;zero page ram buffer length
	  .dw CLASS.PROPERTIES	;default properties, disabled for now.
	  .db NARGS + 3 + 2
	
	  .define \1.init.MTD 0
	  .export \1.init.MTD
    ;fall back to default interface routine if not defined in current class scope
    .ifndef __init
      .dw interface.default.init
    .else
	    .dw _init
    .endif

	  .define \1.play.MTD 1
	  .export \1.play.MTD
    ;fall back to default interface routine if not defined in current class scope
    .ifndef __play
      .dw interface.default.play
    .else
	    .dw _play
    .endif

      .define \1.pause.MTD 2
      .export \1.pause.MTD
    ;fall back to default interface routine if not defined in current class scope
    .ifndef __pause
      .dw interface.default.pause
    .else
        .dw _pause
    .endif

      .define \1.disable.MTD 3
      .export \1.disable.MTD
    ;fall back to default interface routine if not defined in current class scope
    .ifndef __disable
      .dw interface.default.disable
    .else
        .dw _disable
    .endif

      .define \1.enable.MTD 4
      .export \1.enable.MTD
    ;fall back to default interface routine if not defined in current class scope
    .ifndef __enable
      .dw interface.default.enable
    .else
        .dw _enable
    .endif

	  .define \1.kill.MTD 5
	  .export \1.kill.MTD
    ;fall back to default interface routine if not defined in current class scope
    .ifndef __kill
      .dw interface.default.kill
    .else
	    .dw _kill
    .endif

	  .ifdefm \2
		  .define \1.\2.MTD 6
		  .export \1.\2.MTD
		  .dw _\2
	  .endif

	  .ifdefm \3
		  .define \1.\3.MTD 7
		  .export \1.\3.MTD
		  .dw _\3
	  .endif
	
	  .ifdefm \4
		  .define \1.\4.MTD 8
		  .export \1.\4.MTD
		  .dw _\4
	  .endif
	
	  .ifdefm \5
		  .define \1.\5.MTD 9
		  .export \1.\5.MTD
		  .dw _\5
	  .endif

	  .ifdefm \6
		  .define \1.\6.MTD 10
		  .export \1.\6.MTD
		  .dw _\6
	  .endif

	  .ifdefm \7
		  .define \1.\7.MTD 11
		  .export \1.\7.MTD
		  .dw _\7
	  .endif

	  .ifdefm \8
		  .define \1.\8.MTD 12
		  .export \1.\8.MTD
		  .dw _\8
	  .endif

	  .ifdefm \9
		  .define \1.\9.MTD 13
		  .export \1.\9.MTD
		  .dw _\9
	  .endif
  .endif
.endm

;parameters: 1=file label 2=file path 3=read length
.macro FILEINC
\1:
	.ifdefm \3
		.incbin \2 read \3 fsize \1.LEN
	.else
		.incbin \2 fsize \1.LEN
	.endif
	.export \1.LEN
.endm



;declares label in local scope, then does a (normally redundant) define so that already-defined labels can be detected.
.macro METHOD
  .if NARGS != 1
	.fail
  .endif

  .define __\1
  _\1:
  .accu 16
  .index 16
.endm

.macro DEFAULT_METHOD
  .if NARGS != 1
	.fail
  .endif

  .ifndef __\1
	.define __\1
	_\1:
.endm


.macro SCRIPT
  .if NARGS != 1
	  .printt "Invalid parameter count in event macro\n."
	  .fail
  .endif
	\1:
	.dw SCRIPT_MAGIC
	\1.codeStart:
	AX16
.endm


.macro IRQ
  .if NARGS != 3
      .printt "Invalid parameter count in irq macro\n."
      .fail
  .endif
  \1.IRQ:
    .dw IRQ_MAGIC
    .dw \2  ;v-pos
    .dw \3  ;h-pos
    .ACCU 16
    .INDEX 16
.endm

.macro CALLBACK
  .if NARGS != 1
      .printt "Invalid parameter count in callback macro\n."
      .fail
  .endif
  \1.CLB:
    .dw CALLBACK_MAGIC
    .ACCU 16
    .INDEX 16
.endm


.macro SPRITE_ANIMATION
  .INCDIR "build/data/sprites/"
  .if NARGS == 4
    .Section "\1.\2.\3.sprite.\4.animation" superfree
        SPRITE.\1.\2.\3:
        .incbin "\1/\2/\3.gfx_sprite_\4.animation"
    .ends
  .endif
  .if NARGS == 3
    .Section "\1.\2.sprite.\3.animation" superfree
        SPRITE.\1.\2:
        .incbin "\1/\2.gfx_sprite_\3.animation"
    .ends
  .endif
  .if NARGS == 2
    .Section "\1.sprite.\2.animation" superfree
        SPRITE.\1:
        .incbin "\1.gfx_sprite_\2.animation"
    .ends
  .endif
  .if NARGS == 1
    .Section "\1.sprite.animation" superfree
        SPRITE.\1:
        .incbin "\1.gfx_sprite.animation"
    .ends
  .endif
  .INCDIR ""
.endm

.macro SPRITE_DUMMY
  .INCDIR "build/data/sprites/"
    .Section "\1.\2.sprite.animation" superfree
        SPRITE.\1.\2:
        .incbin "\1/\2.gfx_sprite.animation"
    .ends
  .INCDIR ""
.endm


.macro SPRITE_ANIMATION_INC
  .INCDIR "build/data/sprites/"
  .if NARGS == 4
    .Section "\1.\2.\3.sprite.\4.animation" superfree
        SPRITE.\1.\2.\3:
        .include "\1/\2/\3.gfx_sprite_\4.animation.include"
    .ends
  .endif
  .if NARGS == 3
    .Section "\1.\2.sprite.\3.animation" superfree
        SPRITE.\1.\2:
        .include "\1/\2.gfx_sprite_\3.animation.include"
    .ends
  .endif
  .if NARGS == 2
    .Section "\1.sprite.\2.animation" superfree
        SPRITE.\1:
        .include "\1.gfx_sprite_\2.animation.include"
    .ends
  .endif
  .if NARGS == 1
    .Section "\1.sprite.animation" superfree
        SPRITE.\1:
        .include "\1.gfx_sprite.animation.include"
    .ends
  .endif
  .INCDIR ""
.endm

.macro VWF_FONT
  .INCDIR "build/data/font/"
    .Section "\1.font.\2." superfree
        FONT.\1:
        .incbin "\1.gfx_vwf_font_\2.bmp.font"
    .ends
  .INCDIR ""
.endm

.macro VWF_FONT_PACKED
  .INCDIR "build/data/font/"
    .Section "\1.font.\2." superfree
        FONT.\1:
        .incbin "\1.gfx_vwf_font_\2.bmp.font.lz4"
    .ends
  .INCDIR ""
.endm

.macro HDMA_SCROLL_ANIMATION
  .INCDIR "build/data/hdma/"

  .if NARGS == 1
    .Section "\1.hdma.animation" superfree
        HDMA.\1:
        .incbin "\1.hdma_scroll.animation"
    .ends
  .endif
  .INCDIR ""
.endm

.macro HDMA_WINDOW_ANIMATION
  .INCDIR "build/data/hdma/"

  .if NARGS == 1
    .Section "\1.hdma.animation" superfree
        HDMA.\1:
        .incbin "\1.hdma_window.animation"
    .ends
  .endif
  .INCDIR ""
.endm

.macro HDMA_WINDOW_ANIMATION_SINGLE
  .INCDIR "build/data/hdma/"

  .if NARGS == 1
    .Section "\1.hdma.animation" superfree
        HDMA.\1:
        .incbin "\1.hdma_window_single.animation"
    .ends
  .endif
  .INCDIR ""
.endm

.macro PALETTE_ANIMATION
  .INCDIR "build/data/palettes/"

  .if NARGS == 1
    .Section "\1.palette.animation" superfree
        PALETTE.\1:
        .incbin "\1.palette.animation"
    .ends
  .endif
  .INCDIR ""
.endm

.macro HDMA_COLOR_ANIMATION
  .INCDIR "build/data/hdma/"

  .if NARGS == 1
    .Section "\1.hdma.animation" superfree
        HDMA.\1:
        .incbin "\1.hdma_color.animation"
    .ends
  .endif
  .INCDIR ""
.endm

.macro HDMA_PALETTE_ANIMATION
  .INCDIR "build/data/hdma/"

  .if NARGS == 1
    .Section "\1.hdma.animation" superfree
        HDMA.\1:
        .incbin "\1.hdma_palette.animation"
    .ends
  .endif
  .INCDIR ""
.endm

.macro BG_ANIMATION
  .INCDIR "build/data/backgrounds/"
  .Section "\1.\2.animation" superfree
	  BG.\1:
	  .incbin "\1.\2.animation"
  .ends
  .INCDIR ""
.endm

;shorthand for error handler
.macro TRIGGER_ERROR
.if HANDLE_ERRORS == 1
    .if NARGS != 1
        .printt "Fatal error in macro TRIGGER_ERROR, must have exactly one argument \n"
        .fail
    .endif
    pea \1
    jsr core.error.trigger
.endif    
.endm

;shorthand for error handler
.macro SCRIPT_TRIGGER_ERROR
.if HANDLE_ERRORS == 1
    .if NARGS != 1
        .printt "Fatal error in macro TRIGGER_ERROR, must have exactly one argument \n"
        .fail
    .endif
    pea \1
    jml extend.error.trigger
.endif    
.endm

.macro MARK_BANK
.bank \@
.org 0
  .section "!bank.mark.\@" force
    .dw BANK.MAGIC.VALUE
    .dw \@
  .ends
.endm


;wait macro for scripts
;parameter \1: number of frames to wait
.macro SLEEP
  lda #\1
  sta this.timer

  jsr script.savePosition

  lda this.timer
  beq _sleep\@
    dec a
    sta this.timer
    rts
_sleep\@
.endm


.macro SAVE
  jsr script.savePosition
.endm

.macro SET_PC
	lda.w #\1
	jsr script.setPosition
.endm

.macro SCRIPT_JSR
	pea \1
	jsl script.trampoline
	sta 1,s
	pla
.endm

;dispatch obj method. parameters: \1 pointer to obj hash \2 method .ptr to execute \3-\9 parameters(optional)
;assumes accu 16bit
.macro SCRIPT_TRY

.if NARGS < 2
  .fail
.endif

ldx #\2
pea core.object.exists
jsl script.trampoline
sta 1,s
pla
bcc _script_try_catch\@

ldx #\2
ldy #\1

.ifdefm \9
pea \9
.endif

.ifdefm \8
pea \8
.endif

.ifdefm \7
pea \7
.endif

.ifdefm \6
pea \6
.endif

.ifdefm \5
pea \5
.endif

.ifdefm \4
pea \4
.endif


.ifdefm \3
pea \3
.endif

jsl extend.object.call

.ifdefm \9
pla
.endif

.ifdefm \8
pla
.endif

.ifdefm \7
pla
.endif

.ifdefm \6
pla
.endif

.ifdefm \5
pla
.endif

.ifdefm \4
pla
.endif

.ifdefm \3
pla
.endif

_script_try_catch\@:

.endm


;wait as long as object exists
;parameter \1: object hash
.macro WAIT_FOR
  jsr script.savePosition
  ldx #\1
  SCRIPT_JSR core.object.exists
  bcc _waitFor\@
    rts
_waitFor\@
.endm

.macro WAIT_FOR_NOSAVE
  ldx #\1
  SCRIPT_JSR core.object.exists
  bcc _waitForNS\@
    rts
_waitForNS\@
.endm

;wait as long as object exists
;parameter \1: object hash
;parameter \2: joypad id
;parameter \3: button trigger
;parameter \4: escape target label
.macro WAIT_FOR_WITH_BUTTON_ESCAPE
  jsr script.savePosition
	ldx.w #\2
	SCRIPT_JSR core.input.get.trigger
	and.w #\3
	bne \4

  ldx #\1
  SCRIPT_JSR core.object.exists
  bcc _waitForEsc\@
    rts
_waitForEsc\@
.endm


.macro LOOP
  .if NARGS == 1
    lda #\1
    sta this.timer
    jsr script.savePosition

  .else
    jsr script.waitLoop
  .endif
.endm




.macro ACQUIRE_OBJECT
 SCRIPT_JSR iterator.library.reset

  lda.w #\1
  SCRIPT_JSR iterator.library.each.byId
  bcs _acquire_\@
  	pea \1
  	SCRIPT_TRIGGER_ERROR E_ObjNotFound

_acquire_\@:
.endm


;wait forever
.macro CUTSCENE_ACQUIRE_OBJECT
	SAVE
	SCRIPT_JSR iterator.library.reset
	lda.w #\1
	SCRIPT_JSR iterator.library.each.byId
	bcs _acquire\@
		rts

_acquire\@:
	lda iterator.target
	sta \2
	lda iterator.target+2
	sta \2 +2 
.endm

.macro CUTSCENE_STRING_LO
  SCRIPT_CALL background.textlayer.vwf.clear.MTD obj.vwf
  SCRIPT_CALL vwf.parser.print.MTD obj.parser \1 FONT.big_2bpp.PTR 220 40 140 VOID
  SAVE
  SCRIPT_CALL background.textlayer.vwf.isDone.MTD obj.vwf
  bcs _cutscene_string_lo\@
    rts

_cutscene_string_lo\@:
  LOOP 60
  LOOP
  SCRIPT_CALL background.textlayer.vwf.clear.MTD obj.vwf
.endm


.macro CUTSCENE_STRING_HI
  SCRIPT_CALL background.textlayer.vwf.clear.MTD obj.vwf
  SCRIPT_CALL vwf.parser.print.MTD obj.parser \1 FONT.big_2bpp.PTR 220 40 40 VOID
  SAVE
  SCRIPT_CALL background.textlayer.vwf.isDone.MTD obj.vwf
  bcs _cutscene_string_hi\@
    rts

_cutscene_string_hi\@:
  LOOP 60
  LOOP
  SCRIPT_CALL background.textlayer.vwf.clear.MTD obj.vwf
.endm

.macro CUTSCENE_STRING_SPRITE_LO
  SCRIPT_CALL sprite.vwf.clear.MTD obj.vwf
  SCRIPT_CALL vwf.parser.print.MTD obj.parser \1 FONT.big.PTR 220 40 140 VOID
  SAVE
  SCRIPT_CALL sprite.vwf.isDone.MTD obj.vwf
  bcs _cutscene_string_sprite_hi\@
    rts

_cutscene_string_sprite_hi\@:
  LOOP 60
  LOOP
.endm

.macro CUTSCENE_WAIT
  LOOP 60
  LOOP
.endm

.macro CUTSCENE_WAIT_SHORT
  LOOP 30
  LOOP
.endm


.macro CUTSCENE_WAIT_LONG
  LOOP 120
  LOOP
.endm

.macro CUTSCENE_WAIT_SUPER_LONG
  LOOP 240
  LOOP
.endm

.macro CUTSCENE_GOTO_TILE
  pea \3*8
  pea \2*8
  SCRIPT_CALL lifeform.library.oncommand.MTD \1 LIFEFORM.COMMAND.CUTSCENE.GO_TO
  pla
  pla
.endm

.macro CUTSCENE_WARPTO_TILE
  pea \3*8
  pea \2*8
  SCRIPT_CALL lifeform.library.oncommand.MTD \1 LIFEFORM.COMMAND.CUTSCENE.WARP_TO
  pla
  pla
.endm

.macro CUTSCENE_SETTO_TILE
  pea \3*8
  pea \2*8
  SCRIPT_CALL lifeform.library.setPosition.MTD \1
  pla
  pla
.endm

.macro CUTSCENE_CREATE_NPC
  pea \4
  pea 0
  pea 0
  pea \3*8
  pea \2*8
  SCRIPT_NEW lifeform.npc.CLS.PTR \1
  pla
  pla
  pla
  pla
  pla
.endm

.macro CUTSCENE_WAIT_ANIMATION
	SCRIPT_CALL lifeform.library.oncommand.MTD \1 LIFEFORM.COMMAND.CUTSCENE.ANIMATION_START \2 \3
  LOOP \3
  LOOP
.endm

.macro SCRIPT_TRY_PAUSE
  SCRIPT_JSR iterator.library.reset
  lda.w #\1
  SCRIPT_JSR iterator.library.each.byId
  bcc _try_pause\@
	ldx #iterator.target
    SCRIPT_JSR core.object.pause

_try_pause\@:
.endm

.macro SCRIPT_TRY_RESUME
  SCRIPT_JSR iterator.library.reset
  lda.w #\1
  SCRIPT_JSR iterator.library.each.byId
  bcc _try_resume\@
	ldx #iterator.target
    SCRIPT_JSR core.object.resume

_try_resume\@:

.endm

.macro CUTSCENE_DISABLE
	ldx #\1
	SCRIPT_JSR core.object.disable
.endm

.macro CUTSCENE_ENABLE
	ldx #\1
	SCRIPT_JSR core.object.enable
.endm


.macro CUTSCENE_SOUNDEFFECT
  lda.w #\1
  SCRIPT_JSR interface.dimension.playSoundEffect
.endm

.macro CUTSCENE_EXPLOSION
  pea 0
  pea TRUE
  pea 3
  pea SPRITE.effect.enemy.explosion.normal.large.PTR
  pea \2*8
  pea \1*8
  SCRIPT_NEW sprite.once.CLS.PTR VOID
  pla
  pla
  pla
  pla
  pla
  pla
  SCRIPT_NEW level.screen.shake.CLS.PTR VOID 0 0 0 0 14 $7
.endm

.macro CUTSCENE_BOSS_EXPLOSION
  pea 0
  pea TRUE
  pea 3
  pea SPRITE.effect.enemy.explosion.normal.large.PTR
  phy
  phx
  SCRIPT_NEW sprite.once.CLS.PTR VOID
  pla
  pla
  pla
  pla
  pla
  pla
.endm


;16bit with checks. correct, but slow and big
.macro GENERATE_SPRITE_NORMAL
.if \1 == 0
    lda.b animation.displacement.x
.else
    lda.w #\1
    clc
    adc.b animation.displacement.x
    cmp.w #SCREEN.DEFAULT.SIZE.X+1
    bcc ++
		;catch sprites hanging over left edge of screen
      	cmp.w #-SCREEN.MARGIN.X
      	bcc +
  
++
.endif
    sta.w GLOBAL.oamBuffer+(4*\4),y
    and.w #$100
    xba
    sta.w GLOBAL.oamBufferHi+(\4),x
.if \2 == 0
    lda.b animation.displacement.y
.else
    lda.w #\2
    clc
    adc.b animation.displacement.y
    cmp.w #SCREEN.DEFAULT.SIZE.Y+1
    bcc ++
		;catch sprites hanging over left edge of screen
      	cmp.w #-SCREEN.MARGIN.Y
      	bcs ++
  			 lda.w #225

++
.endif
    sta.w GLOBAL.oamBuffer+$1+(4*\4),y
.if \3 == 0
    lda oam.buffer.flags
.else
    lda.w #\3
    clc
    adc oam.buffer.flags
.endif
    sta.w GLOBAL.oamBuffer+$2+(4*\4),y
+
.endm



.macro GENERATE_SPRITE_BIG
.if \1 == 0
    lda.b animation.displacement.x
.else
    lda.w #\1
    clc
    adc.b animation.displacement.x
    cmp.w #SCREEN.DEFAULT.SIZE.X+1
    bcc ++
		;catch sprites hanging over left edge of screen
      	cmp.w #-SCREEN.MARGIN.X*4
      	bcc +
  
++
.endif
    sta.w GLOBAL.oamBuffer+(4*\4),y
    and.w #$100
    ora.w #$200
    xba
    sta.w GLOBAL.oamBufferHi+(\4),x
.if \2 == 0
    lda.b animation.displacement.y
.else
    lda.w #\2
    clc
    adc.b animation.displacement.y
    cmp.w #SCREEN.DEFAULT.SIZE.Y+1
    bcc ++
		;catch sprites hanging over left edge of screen
      	cmp.w #-SCREEN.MARGIN.Y*4
      	bcs ++
  			lda.w #225
  			
++

.endif
    sta.w GLOBAL.oamBuffer+$1+(4*\4),y
.if \3 & OAM.FORMAT.TILE == 0
	lda oam.tilesBig.maintable 
.else
    lda.w #\3 & OAM.FORMAT.TILE
    clc
	adc oam.tilesBig.maintable 
.endif
	asl a
	phx
	tax
.if \3 & (OAM.FORMAT.HFLIP | OAM.FORMAT.VFLIP) == 0
    lda oam.buffer.flagsBig
.else
    lda.w #\3 & (OAM.FORMAT.HFLIP | OAM.FORMAT.VFLIP)
	clc
    adc oam.buffer.flagsBig
.endif
	clc
	adc.l sprite32x32id.lut,x
	plx
    sta.w GLOBAL.oamBuffer+$2+(4*\4),y
+
.endm


.macro GENERATE_SPRITE_RETURN
  rtl
.endm

.macro ONCOMMAND
  lda OBJECT.CALL.ARG.1,s
  asl a
  tax
  lda.l \1,x
  dec a
  tax
  phx
  rts
.endm


.macro SFX_HEADER
	.dw (SFX_SAMPLE.\1-\2)	;relative pointer to sample	
	.dw (SFX_SAMPLE.\1-\2)	;relative loop pointer
    .db \3             ;volume l
    .db \4             ;volume r
    .dw \5           ;pitch
        ;edddaaaa VxADSR1
    .db \6         ;adsr
        ;lllrrrrr VxADSR2
    .db \7           ;adsr
        ;Emmggggg VxGAIN
    .db \8               ;gain
    .db 0
    .db 0
    .db 0
    .db 0
    .db 0
.endm

.macro SFX_SAMPLE
SFX_SAMPLE.\1:
	.incbin "build/data/sounds/\1.sfx_normal.brr"
.endm

.macro SFX_SAMPLE_LOOP
SFX_SAMPLE.\1:
	.incbin "build/data/sounds/\1.sfx_loop.brr"
.endm

.macro MATH_SIN
  AX16
.if DEBUG == 1    
    cmp.w #MATH.2_PI
    bcc +
      pha
      TRIGGER_ERROR E_MathLUTBadPos
+
.endif
    asl a
    tax
    lda.l math.lut.sin,x
.endm

.macro MATH_COS_8BIT
  AX8
.if DEBUG == 1    
    cmp.b #MATH.2_PI
    bcc +
      pha
      TRIGGER_ERROR E_MathLUTBadPos
+
.endif
    tax
    lda.l math.lut.byte.cos,x
.endm

.macro MATH_COS
  AX16
.if DEBUG == 1    
    cmp.w #MATH.2_PI
    bcc +
      pha
      TRIGGER_ERROR E_MathLUTBadPos
+
.endif
    asl a
    tax
    lda.l math.lut.cos,x
.endm

.macro CUTSCENE_KILL_ENEMIES
	jsr _cutscene_kill_enemies
.endm

.macro CUTSCENE_KILL_ENEMIES_AND_BOSSES
	jsr _cutscene_kill_enemies_and_bosses
.endm

.macro CUTSCENE_PAUSE
	ldx.w #\1
	SCRIPT_JSR core.object.pause
.endm

.macro CUTSCENE_RESUME
	ldx.w #\1
	SCRIPT_JSR core.object.resume
.endm

.macro CUTSCENE_PAUSE_PLAYER
	jsr _cutscene_pause_player
.endm

.macro CUTSCENE_RESUME_PLAYER
	jsr _cutscene_resume_player
.endm

.macro HUD_DISABLE
  CUTSCENE_ACQUIRE_OBJECT background.hud.CLS.PTR \1
  ldx #\1
  SCRIPT_JSR core.object.disable
.endm

.macro HUD_ENABLE
	ldx #\1
	SCRIPT_JSR core.object.exists
	bcc _disableSkip\@
	ldx #\1
	SCRIPT_JSR core.object.isDisabled
	bcc _disableSkip\@
		ldx #\1
		SCRIPT_JSR core.object.enable

_disableSkip\@:
.endm

.macro SET_CUTSCENE_OPTIONAL
	jsr _setCutscene
  lda.w #OBJECT.PROPERTIES.isCutscene
  SCRIPT_JSR iterator.library.others	
  bcc _optDontKill\@
    DIE

_optDontKill\@:
.endm

.macro SET_CUTSCENE_MANDATORY
	jsr _setCutscene
	;kill other cutscenes
_mand.loop\@:
  lda.w #OBJECT.PROPERTIES.isCutscene
  SCRIPT_JSR iterator.library.others
  bcc _mand.done\@
  	SCRIPT_CALL Script.oncommand.MTD iterator.target SCRIPT.COMMAND.EXIT
    bra _mand.loop\@

_mand.done\@:
	LOOP 5
	LOOP
.endm


.macro LIMIT_LIFEFORM_X_RANGE
	SCRIPT_CALL lifeform.library.getPosition.MTD \1
	cpx.w #\2*8
	bcs _limit1_\@
		phy
		pea \2*8
		SCRIPT_CALL lifeform.library.setPosition.MTD \1
		pla
		pla
		bra _limit2_\@

_limit1_\@:
	cpx.w #\3*8
	bcc _limit2_\@
		phy
		pea \3*8
		SCRIPT_CALL lifeform.library.setPosition.MTD \1
		pla
		pla

_limit2_\@
.endm


.macro EXPLOSION_BIG
	pea \2
	pea \1
	jsr _explosion_big
	pla
	pla
.endm

.macro AUDIO_FADE
	lda.w #\1
	SCRIPT_JSR core.audio.fadeToVolume
.endm

.macro AUDIO_SET
	lda.w #\1
	SCRIPT_JSR core.audio.setVolume
.endm

.macro WAIT_AUDIO_FADE_COMPLETE
  SAVE
  SCRIPT_JSR core.audio.fadeComplete
  bcs _fade_\@
    rts

_fade_\@:
.endm
