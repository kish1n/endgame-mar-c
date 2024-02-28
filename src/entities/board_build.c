#include "../../resource/header.h"

Board board_build(Object obj) {
    Board border;

    int shrinkWidth = obj.position.w;
    int shrinkHeight = obj.position.h;

    int offsetX = shrinkWidth / 2;
    int offsetY = shrinkHeight / 2;

    border.topWall = (SDL_Rect){obj.position.x + offsetX, obj.position.y + offsetY, obj.position.w - shrinkWidth, 1};
    border.bottomWall = (SDL_Rect){obj.position.x + offsetX, obj.position.y + offsetY + obj.position.h - shrinkHeight, obj.position.w - shrinkWidth, 1};
    border.leftWall = (SDL_Rect){obj.position.x + offsetX, obj.position.y + offsetY, 1, obj.position.h - shrinkHeight};
    border.rightWall = (SDL_Rect){obj.position.x + offsetX + obj.position.w - shrinkWidth, obj.position.y + offsetY, 1, obj.position.h - shrinkHeight};

    return border;
}