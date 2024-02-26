#include "../resource/header.h"

int WinMain(int argc, char *argv[]) {

    sdl_init();
    SDL_Window* window = sdl_window();
    SDL_Renderer* renderer = sdl_render(window);
    SDL_Rect hero = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 120, 160};

    SDL_Texture* bgTexture = load_texture("../resource/static/room-floor/first-room-floor.PNG", renderer);

    if (!bgTexture) {
        printf("err texture\n");
        exit(1);
    }

    int speed = 1;

    //first room
    Room room = room_build(1480, 600, bgTexture); // Создание комнаты
    object* first_rom_obj = init_first_room(renderer);

    int len1 = 0;
    while (first_rom_obj[len1].bg != NULL) {
        len1++;
    }


    printf("len: %d\n", len1);

    bool running = true;
    while (running) {
        update_hero(&hero, speed, &room, &running); // Обновление позиции героя

        render_main(renderer, &hero, &room, first_rom_obj, len1); // Отрисовка кадра

        SDL_RenderPresent(renderer); // Обновление экрана
        SDL_Delay(1); // Управление частотой кадров
    }

    SDL_DestroyTexture(bgTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}