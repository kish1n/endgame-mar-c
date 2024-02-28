#include "../../resource/header.h"

void ingame_main_menu_set(SDL_Event event, bool *isMenuOpen, bool *settingsOpened, Mix_Chunk *clickButton) {
    if(handle_mouse_button_down(event, 680, 1280, 300, 450, play_sound, clickButton)) {
        *isMenuOpen = false;
    }
    if(handle_mouse_button_down(event, 680, 1280, 500, 650, play_sound, clickButton)) {
        *settingsOpened = true;
    }
    if(handle_mouse_button_down(event, 680, 1280, 700, 850, play_sound, clickButton)) {
        SDL_Quit();
        exit(0);
    }
}

