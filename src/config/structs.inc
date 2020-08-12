;global structs

.struct oopObjHash
id			db	;class id
count		dw	;createobj call count
pntr		db	;index of obj in obj stack
.endst


.STRUCT tile
p ds 64
.ENDST

.STRUCT linBuff
strt dw
end  dw
dpag dw
.ENDST

.STRUCT linDpag
lin dw
.ENDST


.STRUCT lineDist
dx db
dy db
startx db
starty db
endx db
endy db
march db	;x=0,y=$80
dir	db	;left=0,right=$80
countr	db	;division step counter
posx	db
posy	db
void	db
.ENDST

;spc structures
.STRUCT callbackBuff
pointer		dw	;pointer to callback routine. $ffff means empty
.ENDST

;iterator structs
.struct iteratorStruct
  self ds 4
  properties dw
  target ds 4
  index dw
  count dw
  sort.target dw
.endst

.struct sortStruct
  properties dw
  attribute dw
.endst


;sprite/dimensions structs
.struct dimensionStruct
  position.x ds 3
  position.y ds 3
  position.last.x dw
  position.last.y dw
  size.x dw
  size.y dw
  acceleration.x dw
  acceleration.y dw
  speed.x dw
  speed.y dw
  direction db
  collision.basepoint.x dw  ;bg collision
  collision.basepoint.y dw
  collision.diameter dw
.endst

.struct lifeformStruct
  controller.type db    ;player, enemy, npc etc
  controller.id db  ;depends on type. eg joypad0, joypad 1 etc.
  controller.buffer dw  ;ds 4
  controller.current.actions dw
  evaluate.wait db
  state db      ;standing on ground, falling etc.
  condition db  ;normal,airborne,warping (tilecheck-related mode)
  abilities dw  ;potential actions a lifeform can execute
  actions dw    ;actions to be executed
  actions.trigger dw
  actions.last dw
  target.properties dw  ;properties to match against when seeking opposing objects. player usually seeks for enemies etc.
  target.object ds _sizeof_oopObjHash   ;currently targeted object
  animation.base dw ;base sprite animation file
  skills dw
  bouncyness dw

  friction dw

  action.age db
  hitpoints dw
  power dw
  speed dw
  combo.counter db
  combo.timer db
  invincibility.timer db
  invincibility.invisible.timer db
  berzerk.counter dw
  berzerk.counter.last dw
  berzerk.yield dw
  mode dw
  grabbed.object ds _sizeof_oopObjHash
  carry.x dw
  carry.y dw
  carry.height dw

  collision.tile dw
  collision.tile.below dw   ;tile lifeform is standing on
  
  callback.touch.wall dw
  callback.touch.floor dw
  callback.touch.lifeform dw
  freeze dw
  hitcount dw ;for one attack
.endst

.struct itemStruct
  item.id dw
  age dw
  persistency ds _sizeof_oopObjHash
.endst

.struct eventStruct
  chapterId dw
  startFrame dw
  endFrame dw
  result dw
  resultTarget dw
  msu1Handler ds 4
  player ds 4
.endst

.struct scriptStruct
  timestamp.start dw
  initAdress dw
  args ds 2*10
.endst

.struct optionStruct
  value dw
  textstring.id dw
  textlayer ds _sizeof_oopObjHash
.endst

.struct animationStruct
  id dw
  pointer ds 3
  buffer.flags dw
  displacement.x dw
  displacement.y dw
  flags.static dw

  speed db
  timer db

  frame.current dw
  frame.last dw
  frame.delay db  ;remove
  frame.pointer ds 3

  frame.tiles.length dw
  frame.tilemap.length dw
  frame.palette.length dw

  tiles.id db
  tiles.start dw
  tiles.length dw

  palette.id db
  palette.start dw
  palette.length dw
  palette.hash dw

  tilemap.id db
  tilemap.start dw
  tilemap.length dw

.endst

.struct backgroundStruct
  ;following only used by bg (and sprite hud)
  tiles.bpp db
  ramBuffer.id db
  ramBuffer.start dw
  ramBuffer.length dw
.endst

.struct oamStruct
  ;following only used by sprites
  tilesBig.start dw
  tilesBig.length dw
  tilesBig.maintable dw
  frame.tilesBig.length dw
  buffer.flags dw
  buffer.flagsBig dw

  ;these current buffers are req'd so that differing frames of normal/big tiles can be displayed (in case one of them hasnt finished uploading to vram yet)
  current.normal.length db ;length, lower byte of pointer into extern.sprite_normal.writeOamLut,x
  current.normal.pointer dw
  current.big.length db ;length, lower byte of pointer into extern.sprite_big.writeOamLut,x
  current.big.pointer dw

.endst

.struct hdmaStruct
  channel db	;msb set if allocated
  isActive db
  target db
  indirect.bank db
  flags db	;directly correspond to dmap0-flags
  table.adress ds 3
  ramBuffer.start dw
  ramBuffer.length dw
  ramBuffer.id db

  ;animation stuff
  animation.id db
  animation.type db
  animation.pointer ds 3
  animation.flags dw
  animation.speed db
  animation.timer db
  animation.frame.loopstart dw
  animation.frame.current dw
  animation.frame.last dw
  animation.frame.max dw
  animation.frame.pointer ds 3
.endst

.struct textlayerStruct
  bg db
  string.id dw  ;current string
  flags db
  font.tiles.start.id db
  font.tiles ds 3
  font.tiles.length dw
  font.palette ds 3
  font.palette.length dw
.endst

.struct vwfLayerStruct
  bg dw
  tile.allocation.size.total dw
  tile.allocation.size.current dw
  delay dw
  charspeed dw
  palette.bits dw
  tiles.startid dw
  current.font dw
  current.font.pointer ds 3
  current.string.pointer ds 3
  current.tilebuffer.size dw
  current.tileline.width dw
  current.tileline.height dw
  current.position.x dw
  current.position.y dw
  renderer.last ds _sizeof_oopObjHash
.endst

.struct static.string.struct
  current.pointer ds 3
  cursor.position.x dw
  cursor.position.y dw
  cursor.margin.left dw
  font.size.x dw
  font.size.y dw
  render.callback ds 3
  render.context ds _sizeof_oopObjHash
  render.dp dw
  substring.length dw
  substring.pointer ds 3
  current.stack	dw
  substring.buffer ds 4
.endst

.struct paletteStruct
  color.start dw
  color.length dw

  ramBuffer.id db
  ramBuffer.start dw
  ramBuffer.length dw

  ;animation stuff
  animation.id db
  animation.type db
  animation.pointer ds 3
  animation.flags dw
  animation.speed db
  animation.timer db
  animation.length.max dw
  animation.frame.loopstart dw
  animation.frame.current dw
  animation.frame.last dw
  animation.frame.max dw
  animation.frame.pointer ds 3

.endst

.struct poolEntry
  hash dw
  subscribers db
  allocation.id db
  allocation.start dw
  allocation.startBig dw
.endst

.struct projectileEntry
  pos.x dw
  pos.y dw
  pos.last.x dw
  pos.last.y dw
  speed db
  angle db
  elevation db
  type db
  age dw  
  power dw
  target.properties dw
  target ds _sizeof_oopObjHash
  caller ds _sizeof_oopObjHash
.endst

.struct playerStruct
  obj.hud ds _sizeof_oopObjHash
  dash.counter dw
  dash.direction dw
.endst

.struct enemyStruct
  level dw
  offscreenCounter dw
  dropsNoScore dw
.endst

;structs:
.struct oamSlot ;must be 8 bytes in length
  x db
  y db
  tile db
  flags db
.endst

