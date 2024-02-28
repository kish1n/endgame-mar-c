#include "../resource/header.h"

//когда открываешь меню, и идешь в настройки там ниче не рабоатет, потому что игра под 1920 1080 (,
// работают две кнопки которые волюме переключают, но музыки пока нету, поэтому они пока тоже не работают

int start_game(SDL_Window* window, SDL_Renderer* renderer) {

    sdl_init();
    SDL_Rect hero = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 160, 320};

    SDL_Texture* bgTexture = load_texture("../resource/static/room-floor/first-room-floor.PNG", renderer);
    Mix_Chunk* clickbutton = load_sound("../menu/volume/clickbutton.wav");
    SDL_Texture* menuInGameBackground;
    SDL_Texture* backgroundsettings;
    SDL_Texture* settingsButtonTextures[7];
    SDL_Texture* menuButtonTexture[3];
    init_texture_menuInGane(renderer, &backgroundsettings, &menuInGameBackground, menuButtonTexture, settingsButtonTextures);


    if (!bgTexture || !menuInGameBackground || !menuButtonTexture[0] || !menuButtonTexture[1] || !menuButtonTexture[2]) {
        printf("err texture\n");
        exit(1);
    }

    int speed = 1;

    //first room
    Board room = board_build(1480, 600, bgTexture); // Создание комнаты
    Object* first_rom_obj = init_first_room(renderer);

    int len1 = 11;
    // while (first_rom_obj[len1].bg != NULL) {
    //     len1++;
    // }

    printf("len: %d\n", len1);

    bool quit = false;
    bool isMenuOpen = false;
    bool settingsOpened = false;

    while (!quit) {
        SDL_Event event;
        update_hero(&hero, speed, &room, &quit); // Обновление позиции героя

        if (isMenuOpen) {
            if (settingsOpened) {
                win_build_Settings(renderer, window,settingsButtonTextures, backgroundsettings);
            } else if (!settingsOpened){
                SDL_RenderCopy(renderer, menuInGameBackground, NULL, NULL);
                win_buildMenuButtons(renderer, menuButtonTexture);
            }
        } else {
            render_main(renderer, &hero, &room, first_rom_obj, len1); // Отрисовка кадра
            SDL_RenderPresent(renderer);
        }

        SDL_Delay(1); // Управление частотой кадров

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    if (!isMenuOpen) {
                        play_sound(clickbutton);
                        isMenuOpen = true;
                    }
                    else if (isMenuOpen && settingsOpened){
                        play_sound(clickbutton);
                        settingsOpened = false;
                    }
                    else if (isMenuOpen){
                        play_sound(clickbutton);
                        isMenuOpen = false;
                    }
                    if (settingsOpened){
                        settingsOpened = false;
                    }
                }
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (isMenuOpen && !settingsOpened) {
                    if(handle_mouse_button_down(event, 680, 1280, 300, 450, play_sound, clickbutton )) {
                        isMenuOpen = false;
                    }
                    if(handle_mouse_button_down(event, 680, 1280, 500, 650, play_sound, clickbutton )) {
                        settingsOpened = true;
                    }
                    if(handle_mouse_button_down(event, 680, 1280, 700, 850, play_sound, clickbutton )) {
                        SDL_Quit();
                        exit(0);
                    }
                }
                if (settingsOpened) {
                    if (handle_mouse_button_down(event, 720, 920, 815, 890, play_sound, clickbutton)) {
                        //volume на паузу
                    }
                    if (handle_mouse_button_down(event, 1020, 1220, 815, 890, play_sound, clickbutton)) {
                        //volume на плей
                    }
                }
            }
        }
    }

    for (int i = 0; i < len1; i++) {
        SDL_DestroyTexture(first_rom_obj[i].bg);
    }

    SDL_DestroyTexture(bgTexture);
    SDL_DestroyTexture(menuInGameBackground);
    SDL_DestroyTexture(backgroundsettings);
    for (int i = 0; i < 3; ++i)
        SDL_DestroyTexture(menuButtonTexture[i]);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
