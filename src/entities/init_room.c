#include "../../resource/header.h"

Object* init_room(SDL_Renderer* renderer, char** filenames, SDL_Rect* positions, bool* dummies, void (*onClickFunctions[])(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture), int length) {
    Object* objects = malloc(sizeof(Object) * length);

    for (int i = 0; i < length; i++) {
        objects[i].bg = malloc(strlen(filenames[i]) + 1);
        objects[i].bg = load_texture(filenames[i], renderer);
        objects[i].position = positions[i];
        int width, height;
        if (SDL_QueryTexture(objects[i].bg, NULL, NULL, &width, &height) != 0) {
            SDL_Log("err h w texture %s", SDL_GetError());
        }
        objects[i].height = height;
        objects[i].width = width;
        objects[i].dummy = dummies[i];
        if (objects[i].dummy) {
            objects[i].height = 0;
            objects[i].width = 0;
        }
        objects[i].onClick = onClickFunctions[i];
    }

    return objects;
}