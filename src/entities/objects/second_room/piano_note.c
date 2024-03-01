#include "../../../../resource/header.h"

void piano_note(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture){
    *texture = load_texture("../resource/static/second_room/active/note_4.PNG", render);
    *this_texture = load_texture("../resource/static/second_room/non_active/piano.PNG", render);
    *position = (SDL_Rect) {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    printf("Book is opened\n");
}