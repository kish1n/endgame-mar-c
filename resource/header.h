#include "SDL2-2.30.0/include/SDL.h"
#include <stdio.h>
#include <stdbool.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080



typedef struct coordinates {
    int x;
    int y;
} coord;

typedef struct character {
    coord position;
} hero;
typedef struct {
    SDL_Rect topWall;
    SDL_Rect bottomWall;
    SDL_Rect leftWall;
    SDL_Rect rightWall;
} Room;

void sdl_init();
SDL_Window* sdl_window();
SDL_Renderer* sdl_render(SDL_Window* window);

Room room_build(int roomWidth, int roomHeight);

void update_hero(SDL_Rect* hero, double speed, Room* room, bool* running);
bool check_collision(const SDL_Rect* a, const SDL_Rect* b);

Room render_room(SDL_Renderer* renderer, const Room* room);
void render_hero(SDL_Renderer* renderer, SDL_Rect* hero);
void render_main(SDL_Renderer* renderer, SDL_Rect* hero, Room* room);
