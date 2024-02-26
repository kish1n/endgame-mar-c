#include "../../resource/header.h"

Board board_build(Object obj) {
    Board border;

    // Вычисляем уменьшение размеров на 20%
    int shrinkWidth = obj.position.w;
    int shrinkHeight = obj.position.h;

    // Вычисляем смещение для центрирования уменьшенных границ
    int offsetX = shrinkWidth / 2;
    int offsetY = shrinkHeight / 2;

    // Создаем границы с учетом уменьшения и смещения
    border.topWall = (SDL_Rect){obj.position.x + offsetX, obj.position.y + offsetY, obj.position.w - shrinkWidth, 1};
    border.bottomWall = (SDL_Rect){obj.position.x + offsetX, obj.position.y + offsetY + obj.position.h - shrinkHeight, obj.position.w - shrinkWidth, 1};
    border.leftWall = (SDL_Rect){obj.position.x + offsetX, obj.position.y + offsetY, 1, obj.position.h - shrinkHeight};
    border.rightWall = (SDL_Rect){obj.position.x + offsetX + obj.position.w - shrinkWidth, obj.position.y + offsetY, 1, obj.position.h - shrinkHeight};

    return border;
}
