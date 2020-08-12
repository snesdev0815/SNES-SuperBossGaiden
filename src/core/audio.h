.include "src/config/config.inc"

;defines
.enum $f0
SPC.COMMAND.RESET db
SPC.COMMAND.SONG.UPLOAD.INIT  db    ;indicates that a song is to be uploaded
SPC.COMMAND.SONG.UPLOAD.STATE1  db    ;indicates that data for transfer1 is on apu ports
SPC.COMMAND.SONG.UPLOAD.STATE2  db    ;indicates that data for transfer2 is on apu ports
SPC.COMMAND.SONG.UPLOAD.DONE  db    ;indicates that song upload is complete
SPC.COMMAND.STREAM.UPLOAD.INIT db    ;indicates that 65816 wants to stream brr data to spc
SPC.COMMAND.STREAM.UPLOAD.DONE  db  ;spc wants to end stream transmission.
SPC.COMMAND.STREAM.UPLOAD.SUBMIT  db  ;indicates that hdma transfer has started.  Its important that bit0 of this command is set.(brr end bit)
SPC.COMMAND.SAMPLES.UPLOAD.INIT  db    ;indicates that a sample pack is to be uploaded. the rest of the commands are taken from normal song upload
SPC.COMMAND.SAMPLES.UPLOAD.DONE  db    ;indicates that sample pack upload is complete
SPC.COMMAND.SOUND.PLAY db    ;play a sound effect
SPC.COMMAND.SONG.STOP  db    ;stop song or stream
SPC.COMMAND.SONG.SET_SPEED  db    ;set timer speed of mod playback routine
SPC.COMMAND.SONG.SET_CHANNEL_MASK db    ;song channel mask
SPC.COMMAND.SONG.SET_REPORT_TYPE  db    ;type of data spc should respond with
SPC.COMMAND.SONG.SET_VOLUME  db    ;
.ende


.def SPC.FLIP_FLAG $80

.enum 0 export
	AUDIO.SONG.MAX ds 0
.ende

.def AUDIO.POSITION.LEFT 0
.def AUDIO.POSITION.CENTER 127
.def AUDIO.POSITION.RIGHT 255

.def AUDIO.VOLUME.MUTE 0
.def AUDIO.VOLUME.FULL $30

.def MSU1_SEEK_TIMEOUT $2000


.export AUDIO.POSITION.LEFT
.export AUDIO.POSITION.CENTER
.export AUDIO.POSITION.RIGHT
.export AUDIO.VOLUME.MUTE
.export AUDIO.VOLUME.FULL

.ramsection "global.audio" bank 0 slot 1
  GLOBAL.audio.song.current dw
  GLOBAL.audio.sfx.inhibit dw
  GLOBAL.audio.sfx_counter dw
  GLOBAL.audio.report.instrument dw
  GLOBAL.audio.report.instrument.trigger dw
  GLOBAL.audio.report.instrument.callback dw
  GLOBAL.audio.audioPlaying dw
  GLOBAL.audio.volumeCurrent dw
  GLOBAL.audio.volumeTarget dw
  GLOBAL.audio.persistency ds _sizeof_oopObjHash
.ends

.base BSL
.bank BANK.PROGRAM

.include "src/include/audio.include"
