#include "../../resource/header.h"

int update_hero(SDL_Rect* hero, int speed, Board* room, bool* running, Object* objects, int len_objs, Door* doors, int len_doors) {
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

    // Проверка столкновений с стенами комнаты
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
                collisionWithObjects = true;
                break;
            }
        }

        for (int i = 0; i < len_doors; i++) {
            if (check_collision(&newHeroRect, &doors[i].position)) {
                printf("Door to room: %d\n", doors[i].toRoom);
                return doors[i].toRoom; // Если столкновение найдено, прерываем цикл
            }
        }

        if (!collisionWithObjects) {
            hero->x = newX;
            hero->y = newY;
        }
    }

    return -1;
}
