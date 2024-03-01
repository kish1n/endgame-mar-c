#include "../../resource/header.h"

void handle_mouse_click_for_objects(SDL_Renderer* render, SDL_Event e, Object* objects, int len_obj, SDL_Texture** active_texture, SDL_Rect* active_position, Object* active_obj, bool* renderActiveObject) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    for (int i = 0; i < len_obj; i++) {
        if (x >= objects[i].position.x &&
            x <= objects[i].position.x + objects[i].position.w &&
            y >= objects[i].position.y &&
            y <= objects[i].position.y + objects[i].position.h) {
            if (objects[i].onClick != NULL) {
                objects[i].onClick(render, active_texture, active_position, &objects[i].bg);
                *active_obj = (Object) {*active_texture, *active_position, 0, 0, true, NULL};
                *renderActiveObject = true;
            }
        }
    }
}
