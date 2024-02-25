#include "../../resource/header.h"

Room room_build(int roomWidth, int roomHeight) {
    int roomX = (SCREEN_WIDTH - roomWidth) / 2;
    int roomY = (SCREEN_HEIGHT - roomHeight) / 2;

    Room room;
    room.topWall = (SDL_Rect){roomX, roomY, roomWidth, 10};
    room.bottomWall = (SDL_Rect){roomX, roomY + roomHeight - 10, roomWidth, 10};
    room.leftWall = (SDL_Rect){roomX, roomY, 10, roomHeight};
    room.rightWall = (SDL_Rect){roomX + roomWidth - 10, roomY, 10, roomHeight};

    printf("Top Wall: %d %d %d %d\n", room.topWall.x, room.topWall.y, room.topWall.w, room.topWall.h);
    printf("Bottom Wall: %d %d %d %d\n", room.bottomWall.x, room.bottomWall.y, room.bottomWall.w, room.bottomWall.h);
    printf("Left Wall: %d %d %d %d\n", room.leftWall.x, room.leftWall.y, room.leftWall.w, room.leftWall.h);
    printf("Right Wall: %d %d %d %d\n", room.rightWall.x, room.rightWall.y, room.rightWall.w, room.rightWall.h);

    return room;
}