.include "src/config/config.inc"

;zp-vars,just a reference
.enum 0
  iterator INSTANCEOF iteratorStruct
  sort INSTANCEOF sortStruct
zpLen ds 0
.ende

;object class static flags, default properties and zero page 
.define CLASS.FLAGS OBJECT.FLAGS.Present
.define CLASS.PROPERTIES 0
.define CLASS.ZP_LENGTH zpLen

;ram buffers
.ramsection "global iterator sort vars" bank 0 slot 1
SORT.GLOBAL.START ds 0
	GLOBAL.iterator.sort.counter dw
	GLOBAL.iterator.sort.count dw
	GLOBAL.iterator.sort.key dw
	GLOBAL.iterator.sort.stack dw
	GLOBAL.iterator.sort.dirty dw
	GLOBAL.iterator.sort.first ds _sizeof_oopObjHash
	GLOBAL.iterator.sort.second ds _sizeof_oopObjHash
SORT.GLOBAL.END ds 0
.ends

.base BSL
.bank BANK.PROGRAM
