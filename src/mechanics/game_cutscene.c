#include "../../resource/header.h"

int game_cutscene(SDL_Renderer* render, bool cutsceneActive) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
            cutsceneActive = false;
            break;
        }
    }

    if (!cutsceneActive) return 1;

    SDL_RenderClear(render);
    render_bg(render, load_texture("../resource/static/cutscene_bg.PNG", render)); // Использование вашей функции для рендеринга фона
    SDL_RenderPresent(render);
    SDL_Delay(100); // небольшая задержка для снижения нагрузки на ЦП

    return 0;
}