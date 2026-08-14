set EMXOMFLD_TYPE=WLINK
set EMXOMFLD_LINKER=wl.exe
set EMXOMFLD_PRELINK=0
make -f makefile.os2 clean
make -f makefile.os2 2>&1 | tee compile.log
