    #include <SDL.h>
    #include "sdl2compat.h"

    static SDL_Renderer* s_renderer = 0;

    void SDL2_SetRenderer(SDL_Renderer* r)
    {
        s_renderer = r;
    }

    void SDL2_Present(SDL_Surface* surf)
    {
        if (!s_renderer || !surf) return;
        SDL_Texture* tex = SDL_CreateTextureFromSurface(s_renderer, surf);
        if (tex) {
            SDL_RenderClear(s_renderer);
            SDL_RenderCopy(s_renderer, tex, NULL, NULL);
            SDL_DestroyTexture(tex);
        }
        SDL_RenderPresent(s_renderer);
    }
