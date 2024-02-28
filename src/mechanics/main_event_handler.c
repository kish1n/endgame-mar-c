#include "../../resource/header.h"

void main_event_handler(SDL_Event *event, SDL_Renderer* render, Object** first_rom_obj, int *len1, Mix_Chunk** clickButton, bool* isMenuOpen, bool* settingsOpened, bool* renderActiveObject, SDL_Texture** active_texture, SDL_Rect* active_position, Object* active_obj) {
    if ((*event).type == SDL_KEYDOWN) {
        if ((*event).key.keysym.sym == SDLK_ESCAPE) {
            ingame_menu_esc_render(isMenuOpen, settingsOpened, *clickButton);
        } else if ((*event).key.keysym.sym == SDLK_SPACE) {
            if (*renderActiveObject) {
                *renderActiveObject = false;
                if (*active_texture != NULL) {
                    SDL_DestroyTexture(*active_texture);
                    *active_texture = NULL;
                }
            }
        }
    } else if ((*event).type == SDL_MOUSEBUTTONDOWN) {
        if (*isMenuOpen && !*settingsOpened) {
            ingame_main_menu_set(*event, isMenuOpen, settingsOpened, *clickButton);
        } else if (*settingsOpened) {
            ingame_voice_menu_set(*event, isMenuOpen, settingsOpened, *clickButton);
        } else {
            handle_mouse_click_for_objects(render, *event, *first_rom_obj, *len1, active_texture, active_position, active_obj, renderActiveObject);
        }
    }
}