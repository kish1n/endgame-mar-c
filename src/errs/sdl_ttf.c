#include "../../resource/header.h"

void sdl_ttf()
{
    if (TTF_Init() < 0) {
        printf("SDL_ttf initialization failed: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }
}