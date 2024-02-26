#include "../../resource/header.h"


Object* init_room(SDL_Renderer* renderer, char** filenames, SDL_Rect* positions, bool** dummies) {

    Object* objects = malloc(sizeof(Object) * 11);

    for (int i = 0; i < 11; i++) {
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
        printf("w: %d, h: %d\n", width, height);
    }

    return objects;
}