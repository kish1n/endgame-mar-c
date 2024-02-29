#include "../../resource/header.h"

void render_main(SDL_Renderer* renderer, SDL_Rect* hero, Board* room, Object* act_obj, Object* objects, SDL_Texture* mainHeroTexture, int len_objs) {
    //Door* doors, int len_doors
    // Рендеринг комнаты
    if (room != NULL) {
        render_all_room(renderer, room, objects, len_objs);
    }
    // Рендеринг героя
    if (hero != NULL) {
        render_hero(renderer, hero, mainHeroTexture);
    };
    if(act_obj->bg != NULL) {
        render_obj(renderer, *act_obj);
    }
}