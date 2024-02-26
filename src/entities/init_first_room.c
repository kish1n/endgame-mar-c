#include "../../resource/header.h"


object* init_first_room(SDL_Renderer* renderer) {
    char* filenames[] = {
            "../resource/static/non_active/clock.PNG",
            "../resource/static/non_active/cupboard.PNG",
            "../resource/static/non_active/cupboard_books.PNG",
            "../resource/static/non_active/fireplace",
            "../resource/static/non_active/greenandblue_mushroom.PNG",
            "../resource/static/non_active/picture.PNG",
            "../resource/static/non_active/pudge.PNG",
            "../resource/static/non_active/red_mushroom.PNG",
            "../resource/static/non_active/tumbler.PNG",
            "../resource/static/non_active/win.PNG",
            "../resource/static/non_active/yellow_mushroom.PNG"
    };

    SDL_Rect positions[] = {
            { 270, 120, 130, 130},
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }
    };

    object* objects = malloc(sizeof(object) * 11);

    for (int i = 0; i < 11; i++) {
        objects[i].bg = malloc(strlen(filenames[i]) + 1);
        objects[i].bg = load_texture(filenames[i], renderer);
        objects[i].position = positions[i];
    }


    return objects;
}