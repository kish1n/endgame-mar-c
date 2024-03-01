#include "../../resource/header.h"

void init_arr4room_3( char*** filenames, SDL_Rect** positions, bool** dummies,
                      void (***functions)(SDL_Renderer*, SDL_Texture**, SDL_Rect*, SDL_Texture** this_texture), Door** doors) {

    static char* local_filenames[] = {
        "../resource/static/dast.PNG",
        "../resource/static/dast.PNG",
        "../resource/static/dast.PNG",
        "../resource/static/dast.PNG",
        "../resource/static/mh.PNG"
    };

    static SDL_Rect local_positions[] = {
        {790,415,260,90},
        {550,500,500,210},
        {230,905,1050,110},
        {1280,505,260,380},
        {390,355,300,30}
    };

    static bool local_dummies[] = {
            false,
            false,
            false,
            false,
            true
    };

    static void (*local_functions[])(SDL_Renderer*, SDL_Texture**, SDL_Rect*, SDL_Texture** this_texture) = {
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj
    };

    static Door local_doors[] = {
            (SDL_Rect) {390,355,300,30}, 30, 260, true, 4, 0,0,
            (SDL_Rect) {1430, 1005, 200, 30}, 30, 200, true, 2, 0, 0,
    };

    *filenames = local_filenames;
    *positions = local_positions;
    *dummies = local_dummies;
    *functions = local_functions;
    *doors = local_doors;
}

