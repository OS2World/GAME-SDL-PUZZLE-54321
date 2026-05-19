############################################################
CXX := c++
STRIP := echo
############################################################
MKDIR_CMD = test -d $(@D) || mkdir -p $(@D)
############################################################

SDL :=/@unixroot/usr/local
SDL_IMAGE := /@unixroot/usr/local

CPPFLAGS += -I${SDL}/include/SDL -I${SDL_IMAGE}/include/SDL
LDFLAGS += \
	-Zomf \
	-L${SDL_IMAGE}/lib  \
	-L${SDL}/lib  \
	-lSDL_image -lSDL -lpthread -lpng

prog:	Release/54321.exe-$(ARCH)

Release/54321.exe-$(ARCH):
	-@$(MKDIR_CMD)
	echo '#!/bin/sh' > $@
	echo "cd ./bin/$(ARCH) && exec ./54321.exe \$$*" >> $@
	chmod 755 $@
