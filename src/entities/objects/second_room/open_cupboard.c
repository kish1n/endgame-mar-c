#include "../../../../resource/header.h"

void open_cupboard(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture){
    *this_texture = load_texture("../resource/static/second_room/active/shkef_op.PNG", render);
    *position = (SDL_Rect) {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    *texture = load_texture("../resource/static/second_room/active/zoo_note.PNG", render);
    printf("Cupboard is opened\n");
}