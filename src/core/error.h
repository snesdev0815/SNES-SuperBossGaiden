.include "src/config/config.inc"


;defines
.define errStrt	10

.enum errStrt export
E_ObjLstFull	db
E_ObjRamFull	db
E_StackTrash	db
E_Brk					db
E_StackOver		db
E_Todo db
E_SpcTimeout db
E_ObjBadHash	db
E_ObjBadMethod db
E_BadScript db
E_StackUnder db
E_Cop db
E_ScriptStackTrash db
E_UnhandledIrq	db
E_SpcNoStimulusCallback	db
E_DmaQueueFull db
E_InvalidDmaTransferType db
E_InvalidDmaTransferLength db
E_VallocBadStepsize db
E_VallocEmptyDeallocation db
E_UnitTestComplete db
E_UnitTestFail db
E_VallocInvalidLength db
E_CGallocInvalidLength db
E_CGallocBadStepsize db
E_CGallocInvalidStart db
E_CGallocEmptyDeallocation db
E_ObjNotFound db
E_BadParameters db
E_OutOfVram db
E_OutOfCgram db
E_InvalidException db
E_ObjStackCorrupted db
E_BadEventResult db
E_abstractClass db
E_NoChapterFound db
E_NoCheckpointFound db
E_BadSpriteAnimation db
E_BadHdmaAnimation db
E_BadPaletteAnimation db
E_BadVwfFont db
E_VwfAllocationOverflow db
E_AllocatedVramExceeded db
E_AllocatedCgramExceeded db
E_InvalidDmaChannel db
E_DmaChannelEmpty db
E_NoDmaChannel db
E_BadBgAnimation db
E_BadBgLayer db
E_WallocBadStepsize db
E_WallocEmptyDeallocation db
E_OutOfWram db
E_BadInputDevice db
E_BadIrq db
E_NoIrqCallback db
E_BadIrqCallback db
E_SramBad db
E_Deprecated db
E_MathLUTBadPos db
E_BadLevel db
E_LevelTooManyObjects db
E_TooManyObjectArgs db
E_CgramPoolFull db
E_CgramPoolBadDeallocation db
E_CgramPoolEmptyDeallocation db
E_VramPoolFull db
E_VramPoolBadDeallocation db
E_VramPoolEmptyDeallocation db
E_BadCollisionTile db
E_TextOverflow db
E_BadCallback db
E_DivisionByZero db
E_ValueError db
E_IndexError db
E_ChecksumMismatch db
E_LifeformCommandRejected db
E_ChsumKernelBad db
E_ChsumROMBad db
E_SaveSlotBad db
E_ObjDisabled db
E_ObjEnabled db
E_GarbageCollectionFailed db
E_ObjRamPointerBad db
E_BadRegisterWidth db
E_LZ4BadFile db
E_LZ4UnpackError db

E_MaxException ds 0
.ende


;data structures

;ram buffers
.base RAM
;this is where exception handler stores temp vars for exception display
.ramsection "exception cpu status buffr" bank 0 slot 2
excStack	dw
excA	dw
excY	dw
excX	dw
excDp	dw
excDb	db
excPb	db
excFlags	db
excPc	dw
excErr	dw
excArgs	ds 4
.ends

.if HANDLE_ERRORS == 1

;data includes
.base BSL
.bank BANK.DATA

.section "exception font tiles" superfree
	FILEINC ExcFontTiles "build/data/font/fixed8x8.gfx_font.tiles"
.ends

.section "exception font pal" superfree
	FILEINC ExcFontPal "build/data/font/fixed8x8.gfx_font.palette" 8
.ends

.section "err-msg string LUT" superfree
	ExcErrMsgStrLut:
		.dw text.error.objLstFull
		.dw text.error.objRamFull
		.dw text.error.stackTrash
		.dw text.error.brk
		.dw text.error.stackOver
		.dw text.error.todo
		.dw text.error.spcTimeout
		.dw text.error.objBadHash
		.dw text.error.objBadMethod
		.dw text.error.badScript
		.dw text.error.stackUnder
		.dw text.error.cop
		.dw text.error.scriptStackTrash
		.dw text.error.unhandledIrq
		.dw text.error.spcNoStimulusCallback
		.dw text.error.dmaQueueFull
		.dw text.error.invalidDmaTransferType
		.dw text.error.invalidDmaTransferLength		
		.dw text.error.vAllocBadStepsize
		.dw text.error.vAllocEmptyDeallocation
		.dw text.error.unitTestComplete
		.dw text.error.unitTestFail
		.dw text.error.vAllocInvalidLength
		.dw text.error.cgAllocInvalidLength
		.dw text.error.cgAllocBadStepsize
		.dw text.error.cgAllocInvalidStart
		.dw text.error.cgAllocEmptyDeallocation
		.dw text.error.objNotFound
		.dw text.error.badParameters
		.dw text.error.outOfVram
		.dw text.error.outOfCgram
		.dw text.error.invalidException
		.dw text.error.objStackCorrupted
		.dw text.error.badEventResult
		.dw text.error.abstractClass
		.dw text.error.noChapterFound
		.dw text.error.noCheckpointFound
		.dw text.error.badSpriteAnimation
        .dw text.error.badHdmaAnimation
        .dw text.error.badPaletteAnimation
        .dw text.error.badVwfFont
        .dw text.error.vwfAllocationOverflow
        .dw text.error.allocatedVramExceeded
		.dw text.error.allocatedCgramExceeded
		.dw text.error.invalidDmaChannel
		.dw text.error.dmaChannelEmpty
		.dw text.error.noDmaChannel
		.dw text.error.badBgAnimation
		.dw text.error.badBgLayer
		.dw text.error.wAllocBadStepsize
		.dw text.error.wAllocEmptyDeallocation
		.dw text.error.outOfWram
		.dw text.error.badInputDevice
        .dw text.error.badIrq
        .dw text.error.noIrqCallback
        .dw text.error.badIrqCallback
        .dw text.error.sramBad
        .dw text.error.deprecated
        .dw text.error.mathLUTBadPos
        .dw text.error.badLevel
        .dw text.error.levelTooManyObjects
        .dw text.error.tooManyObjectArgs
        .dw text.error.cgramPoolFull
        .dw text.error.cgramPoolBadDeallocation
        .dw text.error.cgramPoolEmptyDeallocation
        .dw text.error.vramPoolFull
        .dw text.error.vramPoolBadDeallocation
        .dw text.error.vramPoolEmptyDeallocation
        .dw text.error.badCollisionTile
        .dw text.error.textOverflow
        .dw text.error.badCallback
        .dw text.error.divisionByZero
        .dw text.error.valueError
        .dw text.error.indexError
        .dw text.error.checksumMismatch
        .dw text.error.lifeformCommandRejected
        .dw text.error.checksumKernelBad
        .dw text.error.checksumROMBad
        .dw text.error.saveSlotBad
        .dw text.error.objDisabled
		.dw text.error.objEnabled
		.dw text.error.garbageCollectionFailed
		.dw text.error.objRamPointerBad
		.dw text.error.badRegisterWidth
		.dw text.error.Lz4BadFile
		.dw text.error.Lz4UnpackError


.ends

.endif

.base BSL
.bank BANK.PROGRAM