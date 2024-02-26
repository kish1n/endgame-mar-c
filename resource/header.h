#include "SDL2-2.30.0/include/SDL.h"
#include "SDL2_image-2.8.2/include/SDL_image.h"
#include <stdio.h>
#include <stdbool.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

typedef struct Coordinates {
    int x;
    int y;
} coord;

typedef struct Character {
    coord position;
} Hero;

typedef struct board {
    SDL_Rect topWall;
    SDL_Rect bottomWall;
    SDL_Rect leftWall;
    SDL_Rect rightWall;
    SDL_Texture* bg;
} Board;

typedef struct object {
    SDL_Texture* bg;
    SDL_Rect position;
    int height; // высота фото
    int width;  // ширина фото
    bool dummy;
} Object;

//errs
void sdl_init();
SDL_Window* sdl_window();
SDL_Renderer* sdl_render(SDL_Window* window);

//entities
Board room_build(int roomWidth, int roomHeight, SDL_Texture* bgPath);
Board board_build(Object obj);
Object* init_room(SDL_Renderer* renderer, char** filenames, SDL_Rect* positions, bool** dummies);
void render_all_room(SDL_Renderer* renderer, const Board* room, Object* objects, int len_objs);
void render_obj(SDL_Renderer* renderer, Object obj);

//mechanics
void update_hero(SDL_Rect* hero, int speed, Board* room, bool* running, Object* objects, int len_objs);
bool check_collision(const SDL_Rect* a, const SDL_Rect* b);

//render
Board render_board(SDL_Renderer* renderer, const Board* room);
void render_hero(SDL_Renderer* renderer, SDL_Rect* hero, SDL_Texture* texture);
void render_main(SDL_Renderer* renderer, SDL_Rect* hero, Board* board, Object* objects, int len_objs);

//graphics
SDL_Texture* load_texture(const char* filename, SDL_Renderer* renderer);
void render_bg(SDL_Renderer* renderer, SDL_Texture* texture);
