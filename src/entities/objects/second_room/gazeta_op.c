#include "../../../../resource/header.h"

void gazeta_op(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture){
    *texture = load_texture("../resource/static/second_room/active/gazeta.PNG", render);
    *position = (SDL_Rect) {100, 150, SCREEN_WIDTH-200, SCREEN_HEIGHT-300};
    printf("Gazeta is opened\n");
}