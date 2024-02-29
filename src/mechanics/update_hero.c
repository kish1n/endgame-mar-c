#include "../../resource/header.h"

int update_hero(SDL_Rect* hero, int speed, Board* room, bool* running, Object* objects, int len_objs, Door* doors, int len_doors, int *index_room) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *running = false;
        }
    }

    const Uint8* state = SDL_GetKeyboardState(NULL);
    int newX = hero->x, newY = hero->y;

    if (state[SDL_SCANCODE_W]) {
        newY -= speed;
    }
    if (state[SDL_SCANCODE_S]) {
        newY += speed;
    }
    if (state[SDL_SCANCODE_A]) {
        newX -= speed;
    }
    if (state[SDL_SCANCODE_D]) {
        newX += speed;
    }

    SDL_Rect newHeroRect = {newX, newY, hero->w, hero->h};

    if (!check_collision(&newHeroRect, &room->topWall) &&
        !check_collision(&newHeroRect, &room->bottomWall) &&
        !check_collision(&newHeroRect, &room->leftWall) &&
        !check_collision(&newHeroRect, &room->rightWall)) {
        // Проверка столкновений с объектами
        bool collisionWithObjects = false;
        for (int i = 0; i < len_objs; i++) {
            if (check_collision(&newHeroRect, &objects[i].position)) {
                if(objects[i].dummy) {
                    collisionWithObjects = false;
                    continue;
                }
                collisionWithObjects = true;// Modify hero's position if index_room is 3
                if (*index_room == 3) {
                    hero->x = 1330;
                    hero->y = 900;
                    hero->w = 60;
                    hero->h = 100;
                    break; // Break out of the loop after setting position
                }
                break;
            }
        }

        for (int i = 0; i < len_doors; i++) {
            if (check_collision(&newHeroRect, &doors[i].position)) {
                if( 0 < doors[i].toRoom && doors[i].toRoom < 4)
                    *index_room =  doors[i].toRoom;
            }
        }

        if (!collisionWithObjects) {
            hero->x = newX;
            hero->y = newY;
        }
    }
    if( 0 < *index_room && *index_room < 4)
        return *index_room;
    else
        printf("Error: index_room is out of range %n\n", index_room);
    return 1;
}
