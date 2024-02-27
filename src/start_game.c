#include "../resource/header.h"

int start_game(SDL_Window* window, SDL_Renderer* renderer) {

    sdl_init();
    SDL_Rect hero = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 160, 320};

    SDL_Texture* bgTexture = load_texture("../resource/static/room-floor/first-room-floor.PNG", renderer);

    if (!bgTexture) {
        printf("err texture\n");
        exit(1);
    }

    int speed = 1;

    //first room
    char* filenames1[] = {
            "../resource/static/non_active/clock.PNG",
            "../resource/static/non_active/cupboard.PNG",
            "../resource/static/non_active/cupboard_books.PNG",
            "../resource/static/non_active/fireplace.PNG",
            "../resource/static/non_active/greenandblue_mushroom.PNG",
            "../resource/static/non_active/picture.PNG",
            "../resource/static/non_active/pudge.PNG",
            "../resource/static/non_active/red_mushroom.PNG",
            "../resource/static/non_active/tumbler.PNG",
            "../resource/static/non_active/win.PNG",
            "../resource/static/non_active/yellow_mushroom.PNG"
    };

    SDL_Rect positions1[] = {
            { 270, 110, 140, 140},
            { 230, 550, 240, 360},
            { 450, 140, 300, 400},
            { 1210, 260, 500, 250 },
            { 270, 260, 105, 305 },
            { 1290, 55, 360, 200 },
            { 720, 350, 140, 140},
            { 1280, 600, 400, 400 },
            { 550, 840, 170, 170 },
            { 800, 60, 421, 300},
            { 270, 840, 170, 170 },
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
            true
    };

    Board room = room_build(1480, 600, bgTexture); // Создание комнаты
    Object* first_rom_obj = init_room(renderer, filenames1, positions1, dummies1);

    int len1 = 11;
//    while (first_rom_obj[len1].bg != NULL) {
//        len1++;
//    }

    printf("len: %d\n", len1);

    bool running = true;
    while (running) {
        update_hero(&hero, speed, &room, &running, first_rom_obj, len1);// Обновление позиции героя

        render_main(renderer, &hero, &room, first_rom_obj, len1); // Отрисовка кадра

        SDL_RenderPresent(renderer); // Обновление экрана
        SDL_Delay(1); // Управление частотой кадров
    }

    for (int i = 0; i < len1; i++) {
        SDL_DestroyTexture(first_rom_obj[i].bg);
    }

    SDL_DestroyTexture(bgTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}