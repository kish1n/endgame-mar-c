#include "../../resource/header.h"

void render_door(SDL_Renderer* render, const Door* door) {
    SDL_Texture* doorTexture = load_texture("../resource/static/door.png", render);
    SDL_RenderCopy(render, doorTexture, NULL, &door->position);
}