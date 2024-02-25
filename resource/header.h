#include "SDL2-2.30.0/include/SDL.h"
#include "SDL2_image-2.8.2/include/SDL_image.h"
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
    SDL_Texture* bg;
} Room;

//errs
void sdl_init();
SDL_Window* sdl_window();
SDL_Renderer* sdl_render(SDL_Window* window);

//entities
Room room_build(int roomWidth, int roomHeight, SDL_Texture* bgPath);

//mechanics
void update_hero(SDL_Rect* hero, int speed, Room* room, bool* running);
bool check_collision(const SDL_Rect* a, const SDL_Rect* b);

//render
Room render_room(SDL_Renderer* renderer, const Room* room);
void render_hero(SDL_Renderer* renderer, SDL_Rect* hero, SDL_Texture* texture);
void render_main(SDL_Renderer* renderer, SDL_Rect* hero, Room* room);

//graphics
SDL_Texture* load_texture(const char* filename, SDL_Renderer* renderer);
void render_bg(SDL_Renderer* renderer, SDL_Texture* texture);
