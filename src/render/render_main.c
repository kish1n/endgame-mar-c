#include "../../resource/header.h"

void render_main(SDL_Renderer* renderer, SDL_Rect* hero, Board* room, Object* objects, SDL_Texture* mainHeroTexture, int len_objs) {
    // Очистка экрана
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Черный фон
    SDL_RenderClear(renderer);

    // Рендеринг комнаты
    if (room != NULL) {

        render_all_room(renderer, room, objects, len_objs);
    }

    // Рендеринг героя
    if (hero != NULL) {
        render_hero(renderer, hero, mainHeroTexture);
    };
}