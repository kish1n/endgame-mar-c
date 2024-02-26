#include "header.h"

Room render_room(SDL_Renderer* renderer, const Room* room) {
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

//    render_bg(renderer, room->bg);
    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0); // Красный цвет для стен
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);

    SDL_RenderFillRect(renderer, &room->topWall);
    SDL_RenderFillRect(renderer, &room->bottomWall);
    SDL_RenderFillRect(renderer, &room->leftWall);
    SDL_RenderFillRect(renderer, &room->rightWall);
}