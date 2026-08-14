############################################################
CXX := c++
STRIP := echo
############################################################
MKDIR_CMD = test -d $(@D) || mkdir -p $(@D)
############################################################

export EMXOMFLD_TYPE    = WLINK
export EMXOMFLD_LINKER  = wl.exe
export EMXOMFLD_PRELINK = 0
export EMXOMFLD_SYSTEM  = os2v2_pm

SDL     := /@unixroot/usr
SDL_IMG := /@unixroot/usr

CPPFLAGS += \
	-I${SDL}/include/SDL2 \
	-I${SDL_IMG}/include/SDL2 \
	-include $(CODE)/sdl2compat.h

LDFLAGS += \
	-Zomf \
	-Zhigh-mem \
	-Zmap \
	-Zstack 0x10000 \
	${SDL}/lib/SDL2main.a \
	-L${SDL_IMG}/lib \
	-L${SDL}/lib \
	-lSDL2_image -lSDL2 -lpthread -lpng

prog:	Release/54321.exe-$(ARCH)

Release/54321.exe-$(ARCH):
	-@$(MKDIR_CMD)
	echo '#!/bin/sh' > $@
	echo "cd ./bin/$(ARCH) && exec ./54321.exe \$$*" >> $@
	chmod 755 $@
