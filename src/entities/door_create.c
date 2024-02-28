#include "../../resource/header.h"

Door door_create(SDL_Rect position, int height, int width, bool open, int toRoom) {
    Door door;
    door.position = position;
    door.height = height;
    door.width = width;
    door.open = open;
    door.toRoom = toRoom;
    return door;
}