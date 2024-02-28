#include "../../resource/header.h"

void ingame_menu_esc_render(bool *isMenuOpen, bool *settingsOpened, Mix_Chunk *clickButton) {
    if (!(*isMenuOpen)) {
        play_sound(clickButton);
        *isMenuOpen = true;
    } else if (*isMenuOpen && *settingsOpened) {
        play_sound(clickButton);
        *settingsOpened = false;
    } else if (*isMenuOpen) {
        play_sound(clickButton);
        *isMenuOpen = false;
    }
    if (*settingsOpened) {
        *settingsOpened = false;
    }
}