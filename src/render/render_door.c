#include "../../resource/header.h"

void render_door(SDL_Renderer* render, const Door* door) {
    SDL_RenderCopy(render, load_texture("../resource/static/door.png", render), NULL, &door->position);
}