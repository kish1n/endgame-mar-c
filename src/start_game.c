#include "../resource/header.h"

int start_game(SDL_Window* window, SDL_Renderer* render, Mix_Chunk* clickButton) {
    sdl_init();

    SDL_Texture* bgTexture_1 = load_texture("../resource/static/first_room/room-floor/first-room-floor.PNG", render);
    SDL_Texture* bgTexture_2 = load_texture("../resource/static/second_room/room-floor/second-room-floor.PNG", render);

    SDL_Texture* menuInGameBackground;
    SDL_Texture* backgroundsettings;
    SDL_Texture* settingsButtonTextures[7];
    SDL_Texture* menuButtonTexture[3];
    init_texture_menuInGane(render, &backgroundsettings, &menuInGameBackground, menuButtonTexture, settingsButtonTextures);

    if (!bgTexture_1 && !bgTexture_2) {
        printf("err texture\n");
        exit(1);
    }

    int speed = 1;

    //first room
    char** filenames1;
    SDL_Rect* positions1;
    bool* dummies1;
    Door* doors1;
    void (**funk1)(SDL_Renderer*, SDL_Texture**, SDL_Rect*);
    int len1 = 14;
    int len_doors1 = 1;

    //Door door1 = door_create((SDL_Rect){1685, 610, 30, 170}, 200, 30, false, 2);

    init_arr4room_1(&filenames1, &positions1, &dummies1, &funk1, &doors1);
    SDL_Rect hero = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 140, 200};

    SDL_Texture* mainHeroTexture = IMG_LoadTexture(render, "../resource/static/mh.PNG");
    Board room = room_build(1480, 600, bgTexture_1); // Создание комнаты
    Object* first_rom_obj = init_room(render, filenames1, positions1, dummies1, funk1, len1); // Инициализация объектов в комнате

    bool renderActiveObject = false;

    SDL_Texture* active_texture = NULL;
    SDL_Rect active_position;
    Object active_obj = {0};

    bool isMenuOpen = false;
    bool settingsOpened = false;
    bool isRunning = true;

    Uint32 startTime = SDL_GetTicks();
    bool cutsceneActive = true;

    while (SDL_GetTicks() - startTime < 10000 && cutsceneActive, game_cutscene(render, cutsceneActive) == 0) {}

    Object* now_obj = first_rom_obj;
    Door* now_door = doors1;

    while (isRunning) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            main_event_handler(&event, render, &now_obj, &len1, &clickButton, &isMenuOpen, &settingsOpened, &renderActiveObject, &active_texture, &active_position, &active_obj);
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
            render_main(render, &hero, &room, &active_obj, now_obj, mainHeroTexture, len1, now_door, len_doors1);
            update_hero(&hero, speed, &room, &isRunning, now_obj, len1, now_door, len_doors1);
            SDL_RenderPresent(render);
        }

        SDL_Delay(1);
    }

    for (int i = 0; i < len1; i++) {
        SDL_DestroyTexture(first_rom_obj[i].bg);
    }

    SDL_DestroyTexture(bgTexture_1);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;
}