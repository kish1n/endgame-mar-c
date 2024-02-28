#include "SDL2-2.30.0/include/SDL.h"
#include "SDL2_image-2.8.2/include/SDL_image.h"
#include "SDL2_mixer-2.8.0/include/SDL_mixer.h"
#include "SDL2_ttf-2.22.0/include/SDL_ttf.h"

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
    void (*onClick)(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position);
} Object;

int WinMain(int argc, char* args[]);

int menu();

int start_game(SDL_Window* window, SDL_Renderer* render);

//errs
void sdl_init();
SDL_Window* sdl_window();
SDL_Renderer* sdl_render(SDL_Window* window);

//entities
Object* init_room(SDL_Renderer* renderer, char** filenames, SDL_Rect* positions, bool* dummies,
                  void (*onClickFunctions[])(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position1), int length);
Board room_build(int roomWidth, int roomHeight, SDL_Texture* bgPath);
Board board_build(Object obj);

//entities-first-room
void open_book(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position);

//mechanics
void update_hero(SDL_Rect* hero, int speed, Board* room, bool* running, Object* objects, int len_objs);
bool check_collision(const SDL_Rect* a, const SDL_Rect* b);

//render
Board render_board(SDL_Renderer* renderer, const Board* room);
void render_hero(SDL_Renderer* renderer, SDL_Rect* hero, SDL_Texture* texture);
void render_main(SDL_Renderer* renderer, SDL_Rect* hero, Board* room, Object* objects, SDL_Texture* mainHeroTexture, int len_objs);
void render_all_room(SDL_Renderer* renderer, const Board* room, Object* objects, int len_objs);
void render_obj(SDL_Renderer* renderer, Object obj);

//graphics
SDL_Texture* load_texture(const char* filename, SDL_Renderer* renderer);
void render_bg(SDL_Renderer* renderer, SDL_Texture* texture);
void render_button(SDL_Renderer* renderer, SDL_Texture* buttonTexture, int x, int y, int w, int h);

//menu
void init_texture_menu(SDL_Renderer* renderer, SDL_Texture* backgroundTexture[], SDL_Texture** authorsBackgroundTexture,
                       SDL_Texture* buttonTextures[], SDL_Texture* settingsButtonTextures[]);
Mix_Chunk* load_sound(const char* path);
void play_sound(Mix_Chunk* sound);

void win_buildFHD(SDL_Renderer* renderer, SDL_Window* window, SDL_Texture* backgroundTexture[], SDL_Texture* buttonTextures[], SDL_Texture* settingsButtonTextures[], SDL_Texture* authorsBackgroundTexture, Mix_Chunk* clickButton, SDL_Event e, bool inSettingsPage, bool inAuthorsPage);
void win_buildHD(SDL_Renderer* renderer, SDL_Window* window, SDL_Texture* backgroundTexture[], SDL_Texture* buttonTextures[], SDL_Texture* settingsButtonTextures[], SDL_Texture* authorsBackgroundTexture, Mix_Chunk* clickButton, SDL_Event e, bool inSettingsPage, bool inAuthorsPage);
void win_buildNHD(SDL_Renderer* renderer, SDL_Window* window, SDL_Texture* backgroundTexture[], SDL_Texture* buttonTextures[], SDL_Texture* settingsButtonTextures[], SDL_Texture* authorsBackgroundTexture, Mix_Chunk* clickButton, SDL_Event e, bool inSettingsPage, bool inAuthorsPage);
void play_click_sound(Mix_Chunk* sound);
bool handle_mouse_button_down(SDL_Event e, int x_min, int x_max, int y_min, int y_max, void (*action)(Mix_Chunk*), Mix_Chunk* soundEffect);