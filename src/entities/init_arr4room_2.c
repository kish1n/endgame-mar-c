#include "../../resource/header.h"

void init_arr4room_2( char*** filenames, SDL_Rect** positions, bool** dummies,
                      void (***functions)(SDL_Renderer*, SDL_Texture**, SDL_Rect*, SDL_Texture** this_texture), Door** doors) {

    static char* local_filenames[] = {
            "../resource/static/second_room/non_active/lean.PNG",
            "../resource/static/second_room/non_active/blue_chair.PNG",
            "../resource/static/second_room/non_active/purple_chair.PNG",
            "../resource/static/second_room/non_active/piano_close.PNG",
            "../resource/static/second_room/non_active/table.PNG",
            "../resource/static/second_room/non_active/mini_table.PNG",
            "../resource/static/second_room/non_active/gazeta.PNG",
            "../resource/static/second_room/non_active/shkef_cl.PNG",
            "../resource/static/second_room/non_active/note_click.PNG",
    };

    static SDL_Rect local_positions[] = {
            {0, 0, 1920, 1080},
            {900, 800, 200, 200},
            {300, 800, 200, 200},
            {450, 300, 400, 300},
            {500, 800, 400, 200},
            {1300, 800, 350, 200},
            {650, 850, 90, 60},
            {1100, 200, 330, 370},
            {525, 605, 100, 70}
    };

    static bool local_dummies[] = {
            true,
            true,
            true,
            true,
            true,
            true,
            true,
            true,
            true
    };

    static void (*local_functions[])(SDL_Renderer*, SDL_Texture**, SDL_Rect*, SDL_Texture** this_texture) = {
            nuul_obj,
            nuul_obj,
            chair_chek,
            piano_note,
            nuul_obj,
            nuul_obj,
            gazeta_op,
            open_cupboard,
            under_piano
    };

    static Door local_doors[] = {
            (SDL_Rect){210, 595, 30, 170}, 200, 30, true, 1, 200, 610,
            (SDL_Rect){1150, 400, 200, 30}, 30, 200, true, 3, 200, 610
    };

    *filenames = local_filenames;
    *positions = local_positions;
    *dummies = local_dummies;
    *functions = local_functions;
    *doors = local_doors;
}

