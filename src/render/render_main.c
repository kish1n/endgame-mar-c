#include "../../resource/header.h"

void render_main(SDL_Renderer* renderer, SDL_Rect* hero, Room* room) {
    SDL_Texture* mainHeroTexture = IMG_LoadTexture(renderer, "../resource/static/mh.PNG");
    // Очистка экрана
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Черный фон
    SDL_RenderClear(renderer);

    // Рендеринг комнаты
    if (room != NULL) {
        render_room(renderer, room);
    }

    // Рендеринг героя
    if (hero != NULL) {
        render_hero(renderer, hero, mainHeroTexture);
    }



    // Другие элементы рендеринга могут быть добавлены здесь

    SDL_RenderPresent(renderer);
}