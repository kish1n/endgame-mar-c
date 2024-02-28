#include "../resource/header.h"

void game_cutscene(SDL_Renderer* renderer)
{
    render_bg(renderer, load_texture("../resource/static/cutscene_bg.PNG", renderer));
}


int start_game(SDL_Window* window, SDL_Renderer* render, Mix_Chunk* clickButton) {

    sdl_init();
    SDL_Rect hero = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 140, 200};

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

    char* filenames1[] = {
            "../resource/static/first_room/non_active/clock.PNG",
            "../resource/static/first_room/non_active/cupboard.PNG",
            "../resource/static/first_room/non_active/cupboard_books.PNG",
            "../resource/static/first_room/non_active/fireplace.PNG",
            "../resource/static/first_room/non_active/greenandblue_mushroom.PNG",
            "../resource/static/first_room/non_active/picture.PNG",
            "../resource/static/first_room/non_active/pudge.PNG",
            "../resource/static/first_room/non_active/red_mushroom.PNG",
            "../resource/static/first_room/non_active/tumbler.PNG",
            "../resource/static/first_room/non_active/win.PNG",
            "../resource/static/first_room/non_active/yellow_mushroom.PNG",
            "../resource/static/first_room/non_active/mushroom_light.PNG",
            "../resource/static/first_room/non_active/moon_light.PNG",
            "../resource/static/first_room/active/list.PNG"
    };

    SDL_Rect positions1[] = {
            { 270, 110, 140, 140},
            { 230, 550, 240, 360},
            { 450, 140, 300, 400},
            { 1210, 260, 500, 250 },
            { 270, 260, 105, 305 },
            { 1290, 55, 360, 200 },
            { 720, 350, 140, 140},
            { 1465, 780, 230, 230 },
            { 550, 840, 170, 170 },
            { 800, 60, 421, 300},
            { 270, 840, 170, 170 },
            {1,1,1920,1080},
            {1,1,1920,1080},
            { 300, 660, 90, 90},
    };

    bool dummies1[] = {
            true,
            false,
            true,
            true,
            true,
            false,
            true,
            true,
            false,
            true,
            true,
            true,
            true,
            true
    };

    void (*funk1[])(SDL_Renderer*, SDL_Texture**, SDL_Rect*) = {
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            nuul_obj,
            open_book
    };

    char* filenames2[] = {};
    SDL_Rect positions2[] = {};
    bool dummies2[] = {};
    void (*funk2[])(SDL_Renderer*, SDL_Texture**, SDL_Rect*) = {};

    SDL_Texture* mainHeroTexture = IMG_LoadTexture(render, "../resource/static/mh.PNG");

    int len1 = sizeof(filenames1) / sizeof(filenames1[0]);
    int len2 = sizeof(filenames1) / sizeof(filenames1[0]);
    printf("len: %d\n", len1);

    Board room = room_build(1480, 600, bgTexture_2); // Создание комнаты

    Object* first_rom_obj = init_room(render, filenames1, positions1, dummies1, funk1, len1); // Инициализация объектов в комнате
//    Object* second_rom_obj = init_room(render, filenames2, positions2, dummies2, funk2, len2); // Инициализация объектов в комнате

    bool renderActiveObject = false;

    SDL_Texture* active_texture = NULL;
    SDL_Rect active_position;
    Object active_obj = {0};

    bool isMenuOpen = false;
    bool settingsOpened = false;
    bool isRunning = true;

    Uint32 startTime = SDL_GetTicks();
    bool cutsceneActive = true;

    while (SDL_GetTicks() - startTime < 10000 && cutsceneActive) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
                cutsceneActive = false;
                break;
            }
        }

        if (!cutsceneActive) break;

        SDL_RenderClear(render);
        game_cutscene(render); // Использование вашей функции для рендеринга фона
        SDL_RenderPresent(render);
        SDL_Delay(100); // небольшая задержка для снижения нагрузки на ЦП
    }


    while (isRunning) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            main_event_handler(&event, render, &first_rom_obj, &len1, &clickButton, &isMenuOpen, &settingsOpened, &renderActiveObject, &active_texture, &active_position, &active_obj);
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

            render_main(render, &hero, &room, &active_obj, first_rom_obj, mainHeroTexture, len1);

            update_hero(&hero, speed, &room, &isRunning, first_rom_obj, len1);

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