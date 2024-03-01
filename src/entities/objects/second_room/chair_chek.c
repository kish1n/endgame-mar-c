#include "../../../../resource/header.h"

void chair_chek(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture) {
    *texture = load_texture("../resource/static/second_room/active/nardia.PNG", render);
    *position = (SDL_Rect) {SCREEN_WIDTH /3, SCREEN_HEIGHT/3, SCREEN_WIDTH /4, SCREEN_HEIGHT/2};
    printf("chair_chel is on\n");
}