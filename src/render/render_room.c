#include "header.h"

Room render_room(SDL_Renderer* renderer, const Room* room) {
    // Установка цвета для фона
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Серый фон
    SDL_RenderClear(renderer); // Очищаем рендерер для рисования фона

//    // Рисуем стены
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Красный цвет для стен
    SDL_RenderFillRect(renderer, &room->topWall);
    SDL_RenderFillRect(renderer, &room->bottomWall);
    SDL_RenderFillRect(renderer, &room->leftWall);
    SDL_RenderFillRect(renderer, &room->rightWall);
}
