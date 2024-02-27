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
    Board room = board_build(1480, 600, bgTexture); // Создание комнаты
    Object* first_rom_obj = init_first_room(renderer);

    int len1 = 11;
//    while (first_rom_obj[len1].bg != NULL) {
//        len1++;
//    }

    printf("len: %d\n", len1);

    bool running = true;
    while (running) {
        update_hero(&hero, speed, &room, &running); // Обновление позиции героя

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