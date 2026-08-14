#ifndef SDL2COMPAT_H
#define SDL2COMPAT_H

/*
 * sdl2compat.h - SDL1 -> SDL2 shim for 54321.
 *
 * Force-included via -include in CPPFLAGS so every translation unit gets
 * the SDL_UpdateRect replacement without touching individual source files.
 *
 * SDL2_SetRenderer() must be called once from main() after the renderer
 * is created.  Thereafter every SDL_UpdateRect() call flushes the shadow
 * SDL_Surface to the renderer and presents it.
 */

#include <SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

void SDL2_SetRenderer(SDL_Renderer* r);
void SDL2_Present(SDL_Surface* surf);

#ifdef __cplusplus
}
#endif

/* Replace SDL1 partial-update calls with a full present of the shadow surface. */
#define SDL_UpdateRect(surf, x, y, w, h)  SDL2_Present(surf)

#endif /* SDL2COMPAT_H */
