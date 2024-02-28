#include "../../../../resource/header.h"

void open_book(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position) {
    *texture = load_texture("../resource/static/first_room/active/note_1.PNG", render);
    *position = (SDL_Rect) {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    printf("Book is opened\n");
}