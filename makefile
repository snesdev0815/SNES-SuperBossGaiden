sourcedir := src
datadir := data
builddir := build
distdir := dist
linkdir := $(builddir)/lnk

romext := sfc
romname := Super\ Boss\ Gaiden\ \(J\)
romfile := $(distdir)/$(romname).$(romext)

linker := wlalink
spcasm = wla-spc700
assembler := wla-65816

graconFolder := 
gralibFolder := ../gralib/

gfxconverter := $(graconFolder)graconGfx.py
levelconverter := $(graconFolder)graconMap.py
textconverter := $(graconFolder)graconText.py

animation_converter := $(graconFolder)graconGfxAnimation.py
palette_converter := $(graconFolder)graconPaletteAnimation.py
hdma_window_converter := $(graconFolder)graconHdmaWindowOverlay.py
hdma_color_converter := $(graconFolder)graconHdmaFixedColorGradient.py
hdma_palette_converter := $(graconFolder)graconHdmaPaletteGradient.py
hdma_scroll_converter := $(graconFolder)graconHdmaZscroll.py
vwf_font_converter := $(graconFolder)graconFont.py
songconverter := $(graconFolder)graconMusic.py

sound_converter := snesbrr

linkflags := -dSrv
linkobjectfile := $(linkdir)/linkobjs.lst
samplelinkobjectfile := $(linkdir)/samplelinkobjs.lst

assemblerflags := -o

emulator := bsnes

spcflags = -o
spclinkflags := -sb
spclinkobjectfile := $(linkdir)/spclinkobjs.lst

verify := -verify on
gfx_font_flags := $(verify) -optimize off -palettes 1 -bpp 2 -mode bg -refpalette ./data/font/fixed8x8.palette.png
gfx_font4bpp_flags := $(verify) -optimize off -palettes 1 -bpp 4 -mode bg

threshold := 15

gfx_bg_flags := $(verify) -optimize on -partitionTilemap on -tilethreshold $(threshold) -palettes 7 -bpp 4 -mode bg
gfx_bg_static_flags := $(verify) -optimize on -partitionTilemap on  -tilethreshold $(threshold) -palettes 7 -bpp 4 -mode bg -statictiles on
gfx_bg_noop_flags := $(verify) -optimize off -partitionTilemap off  -tilethreshold 0 -palettes 1 -bpp 4 -mode bg -statictiles on
gfx_status_flags := $(verify) -optimize on -tilethreshold $(threshold) -palettes 4 -bpp 2 -mode bg
gfx_status_static_flags := $(verify) -optimize on -tilethreshold 0 -palettes 4 -bpp 2 -mode bg -statictiles on
gfx_level_flags := $(verify) -optimize on -collisionTileModifiable 0 -tilethreshold $(threshold) -palettes 7 -bpp 4 -mode bg -maxtiles 768 -mapwidth 256
gfx_sprite_flags := $(verify) -optimize on -palettes 2 -bpp 4 -mode sprite -tilemultiplier 4 -xMirrorTilemap on  -bigtilethreshold 3
gfx_sprite_noop_flags := $(verify) -optimize off -tilethreshold 0 -palettes 2 -bpp 4 -mode sprite -tilemultiplier 4 -xMirrorTilemap on
gfx_sprite_full_flags := $(gfx_sprite_flags) -baseframerate 0 -tilethreshold $(threshold)
gfx_sprite_half_flags := $(gfx_sprite_flags) -baseframerate 1 -tilethreshold $(threshold)
gfx_sprite_quarter_flags := $(gfx_sprite_flags) -baseframerate 2 -tilethreshold $(threshold)
gfx_sprite_eighth_flags := $(gfx_sprite_flags) -baseframerate 3
gfx_sprite_static_flags := $(gfx_sprite_flags) -statictiles on
gfx_sprite_static_big_flags := $(gfx_sprite_flags) -statictiles on
gfx_sprite_static_full_flags := $(gfx_sprite_static_flags) -baseframerate 0
gfx_sprite_static_half_flags := $(gfx_sprite_static_flags) -baseframerate 1
gfx_sprite_static_quarter_flags := $(gfx_sprite_static_flags) -baseframerate 2
gfx_sprite_static_eighth_flags := $(gfx_sprite_static_flags) -baseframerate 3

gfx_vwf_font_8x8_flags := -tilesize 8
gfx_vwf_font_8x8_2bpp_flags := -tilesize 8 -bpp 2
gfx_vwf_font_16x16_flags := -tilesize 16
gfx_vwf_font_16x16_2bpp_flags := -tilesize 16 -bpp 2

RD := $(RM) -r
MD := mkdir -p

empty :=
space := $(empty) $(empty)

asmsource := 65816
asmobj := o
asmheader := h

spcsource := spc700
spcobject := spo
spcbinary := bin

levelsource := tmx
leveltarget := asm

image := png
tile := tiles
spriteanimation := animation
paletteanimation := animation
hdmawindowanimation := animation
hdmascrollanimation := animation
font := font

samplepack := samplepack
spcsamplepack := samplepack.bin

song := mod
spcsong := spcmod

sound := wav
spcsound := brr

sourcefiles := $(shell find $(sourcedir)/ -type f -name '*.$(asmsource)')
objects := $(addprefix $(builddir)/,$(patsubst %.$(asmsource), %.$(asmobj), $(sourcefiles)))
configfiles := $(shell find $(sourcedir)/ -type f -name '*.inc' -o -name '*.opcodes' -o -name '*.registers')
includefiles := $(shell find $(sourcedir)/ -type f -name '*.inc' -o -name '*.opcodes' -o -name '*.include')
scriptfiles := $(shell find $(sourcedir)/ -type f -name '*.inc' -o -name '*.opcodes' -o -name '*.script') $(shell find $(datadir)/ -type f -name '*.inc' -o -name '*.opcodes' -o -name '*.script')
interfacefiles := $(shell find $(sourcedir)/ -type f -name '*.interface')
inheritancefiles := $(shell find $(sourcedir)/ -type f -name '*.inheritance')

textfilefolder := $(datadir)/text/
textfiles := $(shell find $(textfilefolder) -type f -name '*.txt')
textfile :=  $(builddir)/$(textfilefolder)textstrings.asm


spcsourcefiles := $(shell find $(sourcedir)/ -type f -name '*.$(spcsource)')
spcobjects := $(addprefix $(builddir)/,$(patsubst %.$(spcsource), %.$(spcobject), $(spcsourcefiles)))
spcbin = $(firstword $(addprefix $(builddir)/,$(patsubst %.$(spcsource), %.$(spcbinary), $(spcsourcefiles))))


graphics := $(shell find $(datadir)/ -type f -name '*.gfx_normal.$(image)')
graphics += $(shell find $(datadir)/ -type f -name '*.gfx_font*.$(image)')
converted_graphics := $(sort $(addprefix $(builddir)/,$(patsubst %.$(image), %.$(tile), $(graphics))))

levels += $(shell find $(datadir)/ -type f -name '*.$(levelsource)')
converted_levels := $(sort $(addprefix $(builddir)/,$(patsubst %.$(levelsource), %.$(leveltarget), $(levels))))

patterns += $(shell find $(datadir)/ -type f -name '*.pattern')

animations := $(shell find $(datadir)/ -type d -name '*.gfx_bg*')
animations += $(shell find $(datadir)/ -type d -name '*.gfx_directcolor')
animations += $(shell find $(datadir)/ -type d -name '*.gfx_level')
animations += $(shell find $(datadir)/ -type d -name '*.gfx_status*')
animations += $(shell find $(datadir)/ -type d -name '*.gfx_sprite*')
converted_animations := $(sort $(addprefix $(builddir)/,$(addsuffix .$(spriteanimation), $(animations))))

fonts += $(shell find $(datadir)/ -type f -name '*.gfx_vwf_font_*')
converted_fonts := $(sort $(addprefix $(builddir)/,$(addsuffix .$(font), $(fonts))))

palettes := $(shell find $(datadir)/ -type d -name '*.palette*')
converted_palettes := $(sort $(addprefix $(builddir)/,$(addsuffix .$(paletteanimation), $(palettes))))

hdma_window_animations += $(shell find $(datadir)/ -type d -name '*.hdma_window')
converted_hdma_window_animations := $(sort $(addprefix $(builddir)/,$(addsuffix .$(hdmawindowanimation), $(hdma_window_animations))))

hdma_window_single_animations += $(shell find $(datadir)/ -type d -name '*.hdma_window_single')
converted_hdma_window_single_animations := $(sort $(addprefix $(builddir)/,$(addsuffix .$(hdmawindowanimation), $(hdma_window_single_animations))))

hdma_color_animations += $(shell find $(datadir)/ -type d -name '*.hdma_color')
converted_hdma_color_animations := $(sort $(addprefix $(builddir)/,$(addsuffix .$(hdmawindowanimation), $(hdma_color_animations))))

hdma_palette_animations += $(shell find $(datadir)/ -type d -name '*.hdma_palette')
converted_hdma_palette_animations := $(sort $(addprefix $(builddir)/,$(addsuffix .$(hdmawindowanimation), $(hdma_palette_animations))))

hdma_scroll_animations += $(shell find $(datadir)/ -type d -name '*.hdma_scroll')
converted_hdma_scroll_animations := $(sort $(addprefix $(builddir)/,$(addsuffix .$(hdmawindowanimation), $(hdma_scroll_animations))))

songs := $(shell find $(datadir)/ -type f -name '*.$(song)')
converted_songs := $(addprefix $(builddir)/,$(patsubst %.$(song), %.$(spcsong), $(songs)))

samplepacks := $(shell find $(sourcedir)/ -type f -name '*.$(samplepack)')
converted_samplepacks := $(addprefix $(builddir)/,$(patsubst %.$(samplepack), %.$(spcsamplepack), $(samplepacks)))

sounds := $(shell find $(datadir)/ -type f -name '*.sfx_normal.$(sound)')
sounds += $(shell find $(datadir)/ -type f -name '*.sfx_loop.$(sound)')

converted_sounds := $(sort $(addprefix $(builddir)/,$(patsubst %.$(sound), %.$(spcsound), $(sounds))))

sfx_normal_flags := -e
sfx_loop_flags := -e -l 0

datafiles := $(converted_graphics) $(converted_animations) $(converted_fonts) $(converted_palettes) $(converted_hdma_window_animations) $(converted_hdma_window_single_animations) $(converted_hdma_color_animations) $(converted_hdma_palette_animations) $(converted_hdma_scroll_animations) $(converted_songs) $(converted_samplepacks) $(spcbin) $(converted_levels) $(textfile) $(patterns) $(converted_sounds)
builddirs := $(sort $(dir $(objects) $(datafiles)) $(linkdir) $(distdir)) 

#link 65816 objects
all: $(linkobjectfile)	
	$(linker) $(linkflags) $(linkobjectfile) $(romfile)
run:	
	$(emulator) $(romfile)

copysd:	
	cp $(romfile) /media/3666-3130/

#create necessary directory substructure in build directory
$(builddirs):
	$(MD) $@

#create 65816 object linkfile
$(linkobjectfile): $(objects)
	$(shell echo "[objects]" > $(linkobjectfile))
	$(foreach obj, $(objects), $(shell echo "$(obj)" >> $(linkobjectfile)))

#compile 65816 assembler sourcefiles
$(objects): $(builddir)/%.$(asmobj): %.$(asmsource) %.$(asmheader) $(configfiles) $(includefiles) $(scriptfiles) $(interfacefiles) $(inheritancefiles) $(datafiles) | $(builddirs)
	$(assembler) $(assemblerflags) $< $@

#link spc700 objects
$(spcbin): $(spclinkobjectfile)	
	$(linker) $(spclinkflags) $(spclinkobjectfile) $(spcbin)
	lz4 --content-size -9 -f $(spcbin) $(spcbin).lz4

#create spc700 object linkfile
$(spclinkobjectfile): $(spcobjects)
	$(shell echo "[objects]" > $(spclinkobjectfile))
	$(foreach obj, $(spcobjects), $(shell echo "$(obj)" >> $(spclinkobjectfile)))

#compile spc700 assembler sourcefiles
$(spcobjects): $(builddir)/%.$(spcobject): %.$(spcsource) | $(builddirs)
	$(spcasm) $(spcflags) $< $@


#convert graphic files. conversion flags are determined by special string inside filename ".gfx_%." (e.g. fixed8x8.gfx_font.png) and fetched from corresponding variable name ($(gfx_font_flags) in this case)
$(converted_graphics): $(builddir)/%.$(tile): %.$(image) | $(builddirs)
	$(gfxconverter) $($(filter gfx_%, $(subst .,$(space), $@))_flags) -infile $< -outfilebase $(patsubst %.$(tile), %, $@)


#convert pro tracker mod files to custom spcmod format
$(converted_songs): $(builddir)/%.$(spcsong): %.$(song) | $(builddirs)
	$(songconverter) $< $(patsubst %.$(spcsong), %, $@)
	lz4 --content-size -9 -f $(patsubst %.$(spcsong), %, $@).$(spcsong) $(patsubst %.$(spcsong), %, $@).$(spcsong).lz4

#compile textstrings from multiple languages into asm include file
$(textfile): $(textfiles) | $(builddirs)
	$(textconverter) -infolder $(textfilefolder) -outfile $@

#convert wav files to brr sample format
$(converted_sounds): $(builddir)/%.$(spcsound): %.$(sound) | $(builddirs)
	$(sound_converter) $($(filter sfx_%, $(subst .,$(space), $@))_flags) $< $@

#pack brr samples into samplepack
$(converted_samplepacks): $(builddir)/%.$(spcsamplepack): %.$(samplepack) $(converted_sounds) | $(builddirs)
	$(shell echo "[objects]" > $(samplelinkobjectfile))
	$(shell echo "build/temp.o" >> $(samplelinkobjectfile))
	$(assembler) -o $< build/temp.o
	$(linker) -b $(samplelinkobjectfile) $@
	lz4 --content-size -9 -f $@ $@.lz4


#convert level files to asm include files
$(converted_levels): $(builddir)/%.$(leveltarget): %.$(levelsource) | $(builddirs)
	$(levelconverter) $(gfx_level_flags) -dump on -infile $< -outfile $@

#convert animation folders to animation files
$(converted_animations): $(builddir)/%.$(spriteanimation): % | $(builddirs)
	$(animation_converter) $($(filter gfx_%, $(subst .,$(space), $@))_flags) -infolder $< -outfile $@

#convert fonts to animation files
$(converted_fonts): $(builddir)/%.$(font): % | $(builddirs)
	$(vwf_font_converter) $($(filter gfx_%, $(subst .,$(space), $@))_flags) -infile $< -outfile $@
	lz4 --content-size -9 -f $@ $@.lz4

#convert palette animation folders to animation files
$(converted_palettes): $(builddir)/%.$(paletteanimation): % | $(builddirs)
	$(palette_converter) -infolder $< -outfile $@

#convert hdma window animation folders to hdma list animation files
$(converted_hdma_window_animations): $(builddir)/%.$(hdmawindowanimation): % | $(builddirs)
	$(hdma_window_converter) -infolder $< -outfile $@

#convert hdma window animation (using single window instead of two) folders to hdma list animation files
$(converted_hdma_window_single_animations): $(builddir)/%.$(hdmawindowanimation): % | $(builddirs)
	$(hdma_window_converter) -single on -infolder $< -outfile $@

#convert hdma color animation folders to hdma list animation files
$(converted_hdma_color_animations): $(builddir)/%.$(hdmawindowanimation): % | $(builddirs)
	$(hdma_color_converter) -infolder $< -outfile $@


#convert hdma palette animation folders to hdma list animation files. options in source folder in the format "-[option]_[value]" are stripped from target filename and passed as argument
$(converted_hdma_palette_animations): $(builddir)/%.$(hdmawindowanimation): % | $(builddirs)
	touch $@
	$(hdma_palette_converter) -infolder $< -outfile $(subst $(space),.,$(filter-out -%,$(subst .,$(space),$@))) $(subst _,$(space),$(filter -%, $(subst .,$(space), $<)))

#convert hdma scroll animation folders to hdma list animation files
$(converted_hdma_scroll_animations): $(builddir)/%.$(hdmawindowanimation): % | $(builddirs)
	$(hdma_scroll_converter) -infolder $< -outfile $@


clean:
	$(RD) $(builddir)
	$(RD) $(distdir)
