#include "../resource/header.h"

int start_game(SDL_Window* window, SDL_Renderer* render, Mix_Chunk* clickButton) {
    sdl_init();
    sdl_ttf();


    SDL_Texture* active_bg[4];
        active_bg[0] = load_texture("../resource/static/second_room/room-floor/second-room-floor.PNG", render);
        active_bg[1] = load_texture("../resource/static/first_room/room-floor/first-room-floor.PNG", render);
        active_bg[2] = load_texture("../resource/static/second_room/room-floor/second-room-floor.PNG", render);
        active_bg[3] = load_texture("../resource/static/third_room/room-floor/third-room-floor.PNG", render);

    SDL_Texture* mainHeroTexture = IMG_LoadTexture(render, "../resource/static/mh.PNG");

    SDL_Texture* menuInGameBackground;
    SDL_Texture* backgroundsettings;
    SDL_Texture* settingsButtonTextures[7];
    SDL_Texture* menuButtonTexture[3];
    init_texture_menuInGane(render, &backgroundsettings, &menuInGameBackground, menuButtonTexture, settingsButtonTextures);

    int speed = 1;

    //zero room
    char** filenames0;
    SDL_Rect* positions0;
    bool* dummies0;
    void (**funk0)(SDL_Renderer*, SDL_Texture**, SDL_Rect*, SDL_Texture** this_texture);
    Door* doors0;
    int len0 = 0;
    int len_doors0 = 0;

    init_arr4room_0(&filenames0, &positions0, &dummies0, &funk0, &doors0);

    //first room
    char** filenames1;
    SDL_Rect* positions1;
    bool* dummies1;
    Door* doors1;
    void (**funk1)(SDL_Renderer*, SDL_Texture**, SDL_Rect*, SDL_Texture** this_texture);
    int len1 = 14;
    int len_doors1 = 1;

    init_arr4room_1(&filenames1, &positions1, &dummies1, &funk1, &doors1);

    //second room
    char** filenames2;
    SDL_Rect* positions2;
    bool* dummies2;
    void (**funk2)(SDL_Renderer*, SDL_Texture**, SDL_Rect*, SDL_Texture** this_texture);
    Door* doors2;
    int len2 = 9;
    int len_doors2 = 2;

    init_arr4room_2(&filenames2, &positions2, &dummies2, &funk2, &doors2);


    //fourth room
    char** filenames3;
    SDL_Rect* positions3;
    bool* dummies3;
    void (**funk3)(SDL_Renderer*, SDL_Texture**, SDL_Rect*, SDL_Texture** this_texturea);
    Door* doors3;
    int len3 = 4;
    int len_doors3 = 2;

    init_arr4room_3(&filenames3, &positions3, &dummies3, &funk3, &doors3);

    Object* rooms[4]; // Создаем массив из четырех комнат
        rooms[0] = init_room(render, filenames0, positions0, dummies0, funk0, len0); // Инициализация объектов в комнате 0
        rooms[1] = init_room(render, filenames1, positions1, dummies1, funk1, len1); // Инициализация объектов в комнате 1
        rooms[2] = init_room(render, filenames2, positions2, dummies2, funk2, len2); // Инициализация объектов в комнате 2
        rooms[3] = init_room(render, filenames3, positions3, dummies3, funk3, len3); // Инициализация объектов в комнате 3

    int lens[4] = {len0, len1, len2, len3};

    int len_doors[4] = {len_doors0, len_doors1, len_doors2, len_doors3};

    Door* doors[4] = {doors0, doors1, doors2, doors3};

    bool renderActiveObject = false;
    SDL_Texture* active_texture = NULL;
    SDL_Rect active_position;
    Object active_obj = {0};

    bool isMenuOpen = false;
    bool settingsOpened = false;
    bool isRunning = true;

    Uint32 startTime = SDL_GetTicks();
    bool cutsceneActive = true;


    int index_room = 1;
    int cur_index = 1;

    SDL_Rect hero = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 140, 200};

    game_cutscene1(render, window);

    while (isRunning) {
        SDL_Event event;
        cur_index = index_room;
        SDL_Texture *now_bg = active_bg[index_room];
        Board room = room_build(1480, 600, now_bg);
        Object* now_obj = rooms[index_room];
        int len_objs = lens[index_room];

        while (SDL_PollEvent(&event)) {
            main_event_handler(&event, render, &now_obj, &len1, &clickButton, &isMenuOpen, &settingsOpened,
                               &renderActiveObject, &active_texture, &active_position, &active_obj);
        }

        if (isMenuOpen) {
            if (settingsOpened) {
                win_build_Settings(render, window, settingsButtonTextures, backgroundsettings);
            } else {
                SDL_RenderCopy(render, menuInGameBackground, NULL, NULL);
                win_buildMenuButtons(render, menuButtonTexture);
            }
        }
        else {
            index_room = update_hero(&hero, speed, &room, &isRunning, now_obj, lens[index_room], doors[index_room], len_doors[index_room], &index_room);
            render_main(render, &hero, &room, &active_obj, now_obj, mainHeroTexture, len_objs);
        }
        if (index_room == 4) {
            printf("Game over\n");
            isRunning = false;
        }

        if (cur_index != index_room) {
            if (index_room == 3) {
                hero =  (SDL_Rect) { 1330, 900, 60, 100};
            } else if (index_room != 4) {
                hero = (SDL_Rect) {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 140, 200};
            }
        }

        SDL_Delay(1);
        SDL_RenderPresent(render);
    }

    game_cutscene2(render, window);

    for (int i = 0; i < 4; i++) {
        SDL_DestroyTexture(active_bg[i]);
    }

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}