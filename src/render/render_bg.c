#include "../../resource/header.h"

void render_bg(SDL_Renderer* renderer, SDL_Texture* texture) { // Рендеринг фона заднего
    SDL_RenderCopy(renderer, texture, NULL, NULL); // Копирование текстуры на весь экран
}