#include "../../resource/header.h"

bool check_collision(const SDL_Rect* a, const SDL_Rect* b) { // Проверка на столкновение не трогать ключевая функция!
    return (a->x < b->x + b->w) &&
           (a->x + a->w > b->x) &&
           (a->y < b->y + b->h) &&
           (a->y + a->h > b->y);
}