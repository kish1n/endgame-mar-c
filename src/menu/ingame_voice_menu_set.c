#include "../../resource/header.h"

void ingame_voice_menu_set(SDL_Event event, bool *isMenuOpen, bool *settingsOpened, Mix_Chunk *clickButton) {
    if (handle_mouse_button_down(event, 720, 920, 815, 890, play_sound, clickButton)) {
        //volume на паузу
    }
    if (handle_mouse_button_down(event, 1020, 1220, 815, 890, play_sound, clickButton)) {
        //volume на плей
    }
}
