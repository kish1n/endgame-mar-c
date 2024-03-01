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
    void (*onClick)(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture);
} Object;

typedef struct door {
    SDL_Rect position;
    int height;
    int width;
    bool open;
    int toRoom;
    int x_coord;
    int y_coord;
} Door;

int WinMain(int argc, char* args[]);

int menu();

int start_game(SDL_Window* window, SDL_Renderer* render, Mix_Chunk* clickButton);

//errs
void sdl_init();
SDL_Window* sdl_window();
SDL_Renderer* sdl_render(SDL_Window* window);
void sdl_ttf();

//entities
Object* init_room(SDL_Renderer* renderer, char** filenames, SDL_Rect* positions, bool* dummies, void (*onClickFunctions[])(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture), int length);
Board room_build(int roomWidth, int roomHeight, SDL_Texture* bgPath);
Board board_build(Object obj);
void nuul_obj(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture);
void handle_mouse_click_for_objects(SDL_Renderer* render, SDL_Event e, Object* objects, int len_obj, SDL_Texture** active_texture, SDL_Rect* active_position, Object* active_obj, bool* renderActiveObject);
Door door_create(SDL_Rect position, int height, int width, bool open, int toRoom);


//entities-first-room
void open_book(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture);
void book_note(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture);
void camin_on(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture);

//entities-second-room
void piano_note(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture);
void gazeta_op(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture);
void under_piano(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture);
void open_cupboard(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture);
void chair_chek(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture);

//mechanics
int update_hero(SDL_Rect* hero, int speed, Board* room, bool* running, Object* objects, int len_objs, Door* doors, int len_doors, int *index_room);
bool check_collision(const SDL_Rect* a, const SDL_Rect* b);
void main_event_handler(SDL_Event *event, SDL_Renderer* render, Object** first_rom_obj, int *len1, Mix_Chunk** clickButton, bool* isMenuOpen, bool* settingsOpened, bool* renderActiveObject, SDL_Texture** active_texture, SDL_Rect* active_position, Object* active_obj);
int game_cutscene(SDL_Renderer* render, bool cutsceneActive);

//render
void render_hero(SDL_Renderer* renderer, SDL_Rect* hero, SDL_Texture* texture);
void render_main(SDL_Renderer* renderer, SDL_Rect* hero, Board* room, Object* act_obj, Object* objects, SDL_Texture* mainHeroTexture, int len_objs);
void render_all_room(SDL_Renderer* renderer, const Board* room, Object* objects, int len_objs);
void render_obj(SDL_Renderer* renderer, Object obj);
void render_door(SDL_Renderer* render, const Door* door);

//graphics
SDL_Texture* load_texture(const char* filename, SDL_Renderer* renderer);
void render_bg(SDL_Renderer* renderer, SDL_Texture* texture);
void render_button(SDL_Renderer* renderer, SDL_Texture* buttonTexture, int x, int y, int w, int h);
void game_cutscene1(SDL_Renderer* renderer, SDL_Window* window);
void game_cutscene2(SDL_Renderer* renderer, SDL_Window* window);
void render_cutscene(SDL_Renderer* renderer, const char* text, SDL_Window* window, int delay);

//menu
void init_texture_menu(SDL_Renderer* renderer, SDL_Texture* backgroundTexture[], SDL_Texture** authorsBackgroundTexture,
                       SDL_Texture* buttonTextures[], SDL_Texture* settingsButtonTextures[]);
Mix_Chunk* load_sound(const char* path);
void play_sound(Mix_Chunk* sound);
void init_texture_menuInGane(SDL_Renderer* renderer, SDL_Texture** backgroundsettings, SDL_Texture** menuInGameBackground, SDL_Texture* menuButtonTexture[], SDL_Texture* settingsButtonTextures[]);
void win_build_Settings(SDL_Renderer* renderer, SDL_Window* window ,SDL_Texture* settingsButtonTextures[], SDL_Texture* backgroundsettings);
void win_buildMenuButtons(SDL_Renderer* renderer, SDL_Texture* menuButtonTexture[]);
void win_buildFHD(SDL_Renderer* renderer, SDL_Window* window, SDL_Texture* backgroundTexture[], SDL_Texture* buttonTextures[], SDL_Texture* settingsButtonTextures[], SDL_Texture* authorsBackgroundTexture, Mix_Chunk* clickButton, SDL_Event e, bool inSettingsPage, bool inAuthorsPage);
void win_buildHD(SDL_Renderer* renderer, SDL_Window* window, SDL_Texture* backgroundTexture[], SDL_Texture* buttonTextures[], SDL_Texture* settingsButtonTextures[], SDL_Texture* authorsBackgroundTexture, Mix_Chunk* clickButton, SDL_Event e, bool inSettingsPage, bool inAuthorsPage);
void win_buildNHD(SDL_Renderer* renderer, SDL_Window* window, SDL_Texture* backgroundTexture[], SDL_Texture* buttonTextures[], SDL_Texture* settingsButtonTextures[], SDL_Texture* authorsBackgroundTexture, Mix_Chunk* clickButton, SDL_Event e, bool inSettingsPage, bool inAuthorsPage);
void play_click_sound(Mix_Chunk* sound);
bool handle_mouse_button_down(SDL_Event e, int x_min, int x_max, int y_min, int y_max, void (*action)(Mix_Chunk*), Mix_Chunk* soundEffect);
void ingame_menu_esc_render(bool *isMenuOpen, bool *settingsOpened, Mix_Chunk *clickButton);
void ingame_main_menu_set(SDL_Event event, bool *isMenuOpen, bool *settingsOpened, Mix_Chunk *clickButton);
void ingame_voice_menu_set(SDL_Event event, bool *isMenuOpen, bool *settingsOpened, Mix_Chunk *clickButton);


void init_arr4room_0( char*** filenames, SDL_Rect** positions, bool** dummies,
                      void (***functions)(SDL_Renderer*, SDL_Texture**, SDL_Rect*, SDL_Texture** this_texture), Door** doors);
void init_arr4room_1( char*** filenames, SDL_Rect** positions, bool** dummies,
                  void (***functions)(SDL_Renderer*, SDL_Texture**, SDL_Rect*, SDL_Texture** this_texture), Door** doors);
void init_arr4room_2( char*** filenames, SDL_Rect** positions, bool** dummies,
                      void (***functions)(SDL_Renderer*, SDL_Texture**, SDL_Rect*, SDL_Texture** this_texture), Door** doors);
void init_arr4room_3( char*** filenames, SDL_Rect** positions, bool** dummies,
                      void (***functions)(SDL_Renderer*, SDL_Texture**, SDL_Rect*, SDL_Texture** this_texture), Door** doors);