#include "../resource/header.h"

void nuul_obj(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position) {
    printf("function1\n");
}

int start_game(SDL_Window* window, SDL_Renderer* render) {

    sdl_init();
    SDL_Rect hero = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 140, 200};

    SDL_Texture* bgTexture = load_texture("../resource/static/first_room/room-floor/first-room-floor.PNG", render);

    if (!bgTexture) {
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

    SDL_Texture* mainHeroTexture = IMG_LoadTexture(render, "../resource/static/mh.PNG");

    int len1 = sizeof(filenames1) / sizeof(filenames1[0]);
    printf("len: %d\n", len1);

    Board room = room_build(1480, 600, bgTexture); // Создание комнаты
    Object* first_rom_obj = init_room(render, filenames1, positions1, dummies1, funk1, len1); // Инициализация объектов в комнате

    bool renderActiveObject = false;
    bool running = true;
    SDL_Texture* active_texture = NULL;
    SDL_Rect active_position;
    Object active_obj = {0};

    while (running) {
        SDL_Event e;

        if (e.type == SDL_QUIT) {
            running = false;
        }

        while (SDL_PollEvent(&e)) {

             if (e.key.keysym.sym == SDLK_ESCAPE) {
                if (renderActiveObject) {
                    renderActiveObject = false;
                    if (active_texture != NULL) {
                        SDL_DestroyTexture(active_texture);
                        active_texture = NULL;
                    }
                }
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                for (int i = 0; i < len1; i++) {
                    if (x >= first_rom_obj[i].position.x && x <= first_rom_obj[i].position.x + first_rom_obj[i].position.w &&
                        y >= first_rom_obj[i].position.y && y <= first_rom_obj[i].position.y + first_rom_obj[i].position.h) {
                        if (first_rom_obj[i].onClick != NULL) {
                            first_rom_obj[i].onClick(render, &active_texture, &active_position);
                            active_obj = (Object) {active_texture, active_position, 0, 0, true, NULL};
                            renderActiveObject = true;
                        }
                    }
                }
            }
        }

        update_hero(&hero, speed, &room, &running, first_rom_obj, len1);

        render_main(render, &hero, &room, first_rom_obj, mainHeroTexture, len1);

        if (renderActiveObject) {
            render_obj(render, active_obj);
        }

        SDL_RenderPresent(render);
        SDL_Delay(3);
    }

    for (int i = 0; i < len1; i++) {
        SDL_DestroyTexture(first_rom_obj[i].bg);
    }

    SDL_DestroyTexture(bgTexture);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}