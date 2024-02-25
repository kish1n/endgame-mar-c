#include "../../resource/header.h"

void render_hero(SDL_Renderer* renderer, SDL_Rect* hero) {

    // Отрисовка героя
    draw_hero(renderer, hero);

    // Отображение отрисованного кадра
    SDL_RenderPresent(renderer);
}
