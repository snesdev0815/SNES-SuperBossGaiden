.include "src/config/config.inc"

;defines
.def NumOfHashptr 8
.def NumOfArgs 9

.struct vars
  _tmp ds 19
  oncommand ds 4
  timer dw  ;timer for scripts
  currPC	dw	;current exec address in script
  buffFlags db	;flags.
  buffBank db		;bank. unused, just for convenience
  buffA	dw
  buffA2 dw
  buffX	dw
  buffY	dw
  buffStack dw	;used to check for stack trashes
.endst
		 
;zp-vars
.enum 0
  iterator INSTANCEOF iteratorStruct
  dimension INSTANCEOF dimensionStruct
  script INSTANCEOF scriptStruct
  this INSTANCEOF vars
  hashPtr INSTANCEOF oopObjHash NumOfHashptr  
  zpLen ds 0
.ende


;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES 0
.define CLASS.ZP_LENGTH zpLen
.define CLASS.IMPLEMENTS interface.dimension

;external parameters
.enum 0 export
  Script.parameter.script db
  Script.parameter.argument.0 db
  Script.parameter.argument.1 db
  Script.parameter.argument.2 db
  Script.parameter.argument.3 db
  Script.parameter.argument.4 db
  Script.parameter.argument.5 db
  Script.parameter.argument.6 db
  Script.parameter.argument.7 db
  Script.parameter.argument.8 db
  Script.parameter.pos.x db
  Script.parameter.pos.y db
  Script.parameter.size.x db
  Script.parameter.size.y db
.ende

.enum 0 export
  DIALOGUE.STATE.CONCERNED db ;3 people
  DIALOGUE.STATE.SHOCKED db
  DIALOGUE.STATE.VENGEANCE db ;2 people
  DIALOGUE.STATE.BERZERK_PHILO db ;1 people
  DIALOGUE.STATE.BERZERK_FAUSTO db
  DIALOGUE.STATE.GHOST db
  DIALOGUE.STATE.GAME_BEATEN db
.ende


.def KILLCOUNT.MAX 999
.export KILLCOUNT.MAX

;ram buffers
.ramsection "global script vars" bank 0 slot 5
  GLOBAL.dialogueState dw
  GLOBAL.killCount dw
  GLOBAL.gotHitCount dw
.ends

.base BSL
.bank BANK.PROGRAM



