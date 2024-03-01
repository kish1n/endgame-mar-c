#include "../../../../resource/header.h"

void camin_on(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture) {
    *this_texture = load_texture("../resource/static/first_room/active/camin_on.PNG", render);
    printf("Camin is on\n");
}