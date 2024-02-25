#include "../resource/header.h"

int WinMain(int argc, char *argv[]) {

    sdl_init();
    SDL_Window* window = sdl_window();
    SDL_Renderer* renderer = sdl_render(window);
    SDL_Rect hero = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 20, 20};

    SDL_Texture* bgTexture = load_texture("../resource/static/room-floor/first-room-floor.PNG", renderer);
    if (!bgTexture) {
        printf("err texture\n");
        exit(1);
    }

    double speed = 1;
    Room room = room_build(400, 300); // Создание комнаты

    bool running = true;
    while (running) {
        update_hero(&hero, speed, &room, &running); // Обновление позиции героя

        render_main(renderer, &hero, &room); // Отрисовка кадра
        
        SDL_RenderPresent(renderer); // Обновление экрана
        SDL_Delay(1); // Управление частотой кадров
    }

    SDL_DestroyTexture(bgTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}