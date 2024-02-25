#include "../../resource/header.h"

void draw_hero(SDL_Renderer* renderer, SDL_Rect* hero) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Установка зеленого цвета для героя
    SDL_RenderFillRect(renderer, hero); // Отрисовка прямоугольника героя
}