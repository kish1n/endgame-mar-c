#include "../../resource/header.h"

void init_arr4room_2( char*** filenames, SDL_Rect** positions, bool** dummies,
                      void (***functions)(SDL_Renderer*, SDL_Texture**, SDL_Rect*), Door** doors) {

    static char* local_filenames[] = {
            "../resource/static/second_room/non_active/blue_chair.PNG",
            "../resource/static/second_room/non_active/lean.PNG",
            "../resource/static/second_room/non_active/purple_chair.PNG",
            "../resource/static/second_room/non_active/piano.PNG",
            "../resource/static/second_room/non_active/table.PNG",
            "../resource/static/second_room/non_active/mini_table.PNG",
    };

    static SDL_Rect local_positions[] = {
            {1,1,1920,1080},
            {1,1,1920,1080},
            {1,1,1920,1080},
            {1,1,1920,1080},
            {1,1,1920,1080},
            {1,1,1920,1080}
    };

    static bool local_dummies[] = {
            true,
            true,
            true,
            true,
            true,
            true
    };

    static void (*local_functions[])(SDL_Renderer*, SDL_Texture**, SDL_Rect*) = {
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
    };

    static Door local_doors[] = {
            (SDL_Rect){210, 595, 30, 170}, 200, 30, true, 1,
    };

    *filenames = local_filenames;
    *positions = local_positions;
    *dummies = local_dummies;
    *functions = local_functions;
    *doors = local_doors;
}

