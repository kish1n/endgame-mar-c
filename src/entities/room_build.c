#include "../../resource/header.h"

Board room_build(int roomWidth, int roomHeight, SDL_Texture* bgPath) {
    int roomX = (SCREEN_WIDTH - roomWidth) / 2;
    int roomY = (int)((SCREEN_HEIGHT - roomHeight) / 1.17);

    Board room;
    room.topWall = (SDL_Rect){roomX, roomY - 100, roomWidth, 10};
    room.bottomWall = (SDL_Rect){roomX, roomY + roomHeight, roomWidth, 10};
    room.leftWall = (SDL_Rect){roomX, roomY - 140, 10, roomHeight + 140};
    room.rightWall = (SDL_Rect){roomX + roomWidth, roomY -140 , 10, roomHeight + 140};
    room.bg = bgPath;

    return room;
}