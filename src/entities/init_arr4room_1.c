#include "../../resource/header.h"

void init_arr4room_1( char*** filenames, SDL_Rect** positions, bool** dummies,
      void (***functions)(SDL_Renderer*, SDL_Texture**, SDL_Rect*, SDL_Texture** this_texture), Door** doors) {

    static char* local_filenames[] = {
            "../resource/static/first_room/non_active/clock.PNG",
            "../resource/static/first_room/non_active/cupboard.PNG",
            "../resource/static/first_room/non_active/cupboard_books.PNG",
            "../resource/static/first_room/non_active/fireplace.PNG",
            "../resource/static/first_room/non_active/greenandblue_mushroom.PNG",
            "../resource/static/first_room/non_active/picture.PNG",
            "../resource/static/first_room/non_active/pudge.PNG",
            "../resource/static/first_room/non_active/red_mushroom.PNG",
            "../resource/static/first_room/non_active/tumbler.PNG",
            "../resource/static/first_room/non_active/win.PNG",
            "../resource/static/first_room/non_active/yellow_mushroom.PNG",
            "../resource/static/first_room/non_active/mushroom_light.PNG",
            "../resource/static/first_room/non_active/moon_light.PNG",
            "../resource/static/first_room/active/list.PNG"
    };

    static SDL_Rect local_positions[] = {
            { 270, 110, 140, 140},
            { 230, 550, 240, 360},
            { 450, 140, 300, 400},
            { 1210, 260, 470, 350 },
            { 270, 260, 105, 305 },
            { 1290, 55, 360, 200 },
            { 720, 350, 140, 140},
            { 1465, 780, 230, 230 },
            { 550, 840, 170, 170 },
            { 800, 60, 421, 300},
            { 270, 840, 170, 170 },
            {1,1,1920,1080},
            {1,1,1920,1080},
            { 300, 660, 90, 90},
    };

    static bool local_dummies[] = {
            true,
            false,
            true,
            true,
            true,
            false,
            true,
            true,
            false,
            true,
            true,
            true,
            true,
            true
    };

    static void (*local_functions[])(SDL_Renderer*, SDL_Texture**, SDL_Rect*, SDL_Texture** this_texture) = {
            nuul_obj,
            nuul_obj,
            book_note,
            camin_on,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            open_book
    };

    static Door local_doors[] = {
            (SDL_Rect){1210, 300, 200, 30}, 30, 200, true, 2, 200, 610
    };

    *filenames = local_filenames;
    *positions = local_positions;
    *dummies = local_dummies;
    *functions = local_functions;
    *doors = local_doors;
}

