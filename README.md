# 54321 — Five Games in Four Dimensions

**54321** is five games in four-, three-, or two-dimensions for one player.
It takes five classic two-dimensional puzzle games and extends them into
three and four dimensions.

- Original author: **Patrick Stein** (Rochester, NY)
- Original website: http://old.nklein.com/products/54321/
- Version: **1.0.2001.11.16 Release 2** (ArcaOS SDL2 Port)

![54321 ScreenShot](/doc/54321.png)

---

## The Five Games

| Game | Description |
|------|-------------|
| **FlipFlop** | Toggle lights in sequence to turn them all off |
| **Bomb Squad** | Sweep a multi-dimensional minefield |
| **Maze Runner** | Navigate a maze in 2, 3, or 4 dimensions |
| **Peg Jumper** | Classic peg solitaire extended to higher dimensions |
| **Tile Slider** | Sliding tile puzzle in 2D, 3D, or 4D |

Each game can be played on a 2-, 3-, or 4-dimensional grid at several
difficulty levels. Use the in-game Help button for full rules.

---

## ArcaOS / OS2 Build Instructions

### Requirements

- ArcaOS 5.1 or later (or eComStation / OS/2 Warp 4.52)
- GCC 9.2 (from ANPM / RPM)
- SDL2 and SDL2_image (from ANPM / RPM)
- GNU make (from ANPM / RPM)

### Build

Copy the source tree to your ArcaOS system and run:

```
compile.cmd
```

Or run make directly:

```
make -f makefile.os2
make -f makefile.os2 clean
```

Output is placed in `Release\bin\OS2\54321.exe`.
Image and data files are copied to `Release\data\`.

### Running

From the `Release\bin\OS2\` directory:

```
54321.exe
```

The game starts in fullscreen mode by default.
Pass any command-line argument (e.g. `-window`) to start in windowed mode.

---

## Original Build (Linux / Unix)

```
gmake all size
```

Requires: `gmake`, a C++ compiler, SDL, SDL_image, SDLmain, libpng, zlib.
Optional: pdflatex, noweave, notangle (for generating code documentation).

Platform-specific compiler settings live in `archs/<Platform>/variables.GNU`.

---

## Port Authors

- **Dave Yeo**
- **Martin Iturbide**

---

## Changelog

### Version 1.0.2001.11.16 Release 2 — ArcaOS SDL2 Port (2026-08-14)

- Migrated from SDL 1 to SDL 2 using a shadow-surface compatibility layer
  (`code/sdl2compat.h` / `code/sdl2compat.cpp`), preserving the original
  rendering logic without touching every call site.
- Added ArcaOS/OS2 build system: `makefile.os2` and `compile.cmd`.
- Linked as a PM (Presentation Manager) executable to suppress the VIO
  console window on launch.
- Added OS/2 module definition file `code/54321.def` with BLDLVL version stamp.
- Added shadow headers (`code/os2fix.h`, `code/errno.h`, `code/ctype.h`)
  to neutralize legacy memory-model keywords and runtime symbol conflicts
  under GCC/EMX on ArcaOS.
- Fixed all GCC 9.2 compiler warnings:
  - Removed always-true address-of-reference assert in `cube.cpp`.
  - Made `Font` destructor virtual to allow correct polymorphic deletion.
  - Cast `char` array subscripts to `unsigned char` in `font.cpp`.
  - Fixed sign-compare warnings in `soundDev.cpp`, `view.cpp`,
    `mainmenuView.cpp`, `maze.cpp`, and `tile.cpp`.
  - Fixed actual bug in `view.cpp`: self-comparison `sy < sy` corrected
    to `yy < sy` in `screenToCell()`.
  - Initialized `SDL_Surface** images` pointer in `view.cpp`.
  - Removed unused variables in `mainmenuController.cpp`, `maze.cpp`,
    and `life.cpp`.
  - Fixed `-Wreorder` warning in `mainmenuView.h` constructor.

### Version 1.0.2001.11.16 Release 1 — Original Release (2001-11-16)

- Original release by Patrick Stein.
- Supported platforms: Linux, Solaris, BeOS, MacOS X, Win32.
