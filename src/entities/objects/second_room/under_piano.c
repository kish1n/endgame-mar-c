#include "../../../../resource/header.h"

void under_piano(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture){
    *texture = load_texture("../resource/static/second_room/active/note_3.PNG", render);
    *position = (SDL_Rect) {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    printf("under_piano is opened\n");
}