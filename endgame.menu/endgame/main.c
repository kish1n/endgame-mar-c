#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
#include <SDL_mixer.h>

SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* path) {
    SDL_Surface* surface = IMG_Load(path);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

Mix_Chunk* loadSound(const char* path) {
    Mix_Chunk* sound = Mix_LoadWAV(path);
    return sound;
}

void playSound(Mix_Chunk* sound) {
    int channel = Mix_GroupAvailable(-1);
    Mix_PlayChannel(channel, sound, 0);
}

void drawButton(SDL_Renderer* renderer, SDL_Texture* buttonTexture, int x, int y, int w, int h) {
    SDL_Rect buttonRect = { x, y, w, h };
    SDL_RenderCopy(renderer, buttonTexture, NULL, &buttonRect);
}

int main(int argc, char* args[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Texture* backgroundTexture[4];
    backgroundTexture[0] = loadTexture(renderer, "images/background.png");
    backgroundTexture[1] = loadTexture(renderer, "images/background2.png");
    backgroundTexture[2] = loadTexture(renderer, "images/background3.png");
    backgroundTexture[3] = loadTexture(renderer, "images/backgroundsettings.png");

    SDL_Texture* authorsBackgroundTexture = loadTexture(renderer, "images/backgroundauthors.png");

    SDL_Texture* buttonTextures[4];
    buttonTextures[0] = loadTexture(renderer, "images/button1.png");
    buttonTextures[1] = loadTexture(renderer, "images/button2.png");
    buttonTextures[2] = loadTexture(renderer, "images/button3.png");
    buttonTextures[3] = loadTexture(renderer, "images/button4.png");

    SDL_Texture* settingsButtonTextures[7];
    settingsButtonTextures[0] = loadTexture(renderer, "images/settingsbutton_fullscreen1.png");
    settingsButtonTextures[1] = loadTexture(renderer, "images/settingsbutton_fullscreen2.png");
    settingsButtonTextures[2] = loadTexture(renderer, "images/settingsbutton_resolution1.png");
    settingsButtonTextures[3] = loadTexture(renderer, "images/settingsbutton_resolution2.png");
    settingsButtonTextures[4] = loadTexture(renderer, "images/settingsbutton_resolution3.png");
    settingsButtonTextures[5] = loadTexture(renderer, "images/buttonVolumeOFF.png");
    settingsButtonTextures[6] = loadTexture(renderer, "images/buttonVolumeON.png");

    Mix_Chunk* clickButton = loadSound("volume/clickbutton.wav");
    Mix_Chunk* backgroundVolume = loadSound("volume/backgroundVolume.wav");
    playSound(backgroundVolume);

    bool SetWindowSize1280x720 = false;
    bool SetWindowSize800x600 = false;
    bool SetWindowSize1920x1080 = true;
    bool inSettingsPage = false;
    bool inAuthorsPage = false;
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            bool isVolumePlay = false;
            if (e.type == SDL_QUIT)
                quit = true;
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (SetWindowSize1920x1080 && !SetWindowSize1280x720 && !SetWindowSize800x600) {
                    if (!inSettingsPage && !inAuthorsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 100 && e.button.x <= 800 && e.button.y >= 210 && e.button.y <= 370) {
                        playSound(clickButton);
                        /////////////////// здесь кнопка играть 1920/1080, сюда код игры
                    }
                    if (!inSettingsPage && !inAuthorsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 100 && e.button.x <= 800 && e.button.y >= 390 && e.button.y <= 550) {
                        playSound(clickButton);
                        inSettingsPage = true;
                    }
                    if (!inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 100 && e.button.x <= 800 && e.button.y >= 570 && e.button.y <= 730) {
                        playSound(clickButton);
                        inAuthorsPage = true;
                    }
                    if (!inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 100 && e.button.x <= 800 && e.button.y >= 750 && e.button.y <= 910)
                        quit = true;
                    if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 460 && e.button.x <= 760 && e.button.y >= 570 && e.button.y <= 681) {
                        playSound(clickButton);
                        SDL_SetWindowSize(window, 800, 600);
                        SetWindowSize1920x1080 = false;
                        SetWindowSize800x600 = true;
                        SetWindowSize1280x720 = false;
                    }
                    if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 810 && e.button.x <= 1120 && e.button.y >= 570 && e.button.y <= 681) {
                        playSound(clickButton);
                        SDL_SetWindowSize(window, 1280, 720);
                        SetWindowSize1920x1080 = false;
                        SetWindowSize800x600 = false;
                        SetWindowSize1280x720 = true;
                    }
                    if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 1170 && e.button.x <= 1470 && e.button.y >= 570 && e.button.y <= 681) {
                        playSound(clickButton);
                        SDL_SetWindowSize(window, 1920, 1080);
                        SetWindowSize1920x1080 = true;
                        SetWindowSize800x600 = false;
                        SetWindowSize1280x720 = false;
                    }
                    if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 720 && e.button.x <= 920 && e.button.y >= 815 && e.button.y <= 890) {
                        playSound(clickButton);
                        if (isVolumePlay) {
                            isVolumePlay = false;
                       }
                    }
                    if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 1020 && e.button.x <= 1220 && e.button.y >= 815 && e.button.y <= 890) {
                        playSound(clickButton);
                    }
                }
                if (!SetWindowSize1920x1080 && SetWindowSize1280x720 && !SetWindowSize800x600) {
                    if (!inSettingsPage && !inAuthorsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 50 && e.button.x <= 500 && e.button.y >= 140 && e.button.y <= 250) {
                        playSound(clickButton);
                        /////////////////// здесь кнопка играть 1280/720, сюда код игры
                    }
                    if (!inSettingsPage && !inAuthorsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 50 && e.button.x <= 500 && e.button.y >= 270 && e.button.y <= 380) {
                        playSound(clickButton);
                        inSettingsPage = true;
                    }
                    if (!inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 50 && e.button.x <= 500 && e.button.y >= 400 && e.button.y <= 510) {
                        playSound(clickButton);
                        inAuthorsPage = true;
                    }
                    if (!inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 50 && e.button.x <= 500 && e.button.y >= 530 && e.button.y <= 640)
                        quit = true;
                    if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 290 && e.button.x <= 490 && e.button.y >= 380 && e.button.y <= 455) {
                        playSound(clickButton);
                        SDL_SetWindowSize(window, 800, 600);
                        SetWindowSize1920x1080 = false;
                        SetWindowSize800x600 = true;
                        SetWindowSize1280x720 = false;
                    }
                    if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 540 && e.button.x <= 740 && e.button.y >= 380 && e.button.y <= 455) {
                        playSound(clickButton);
                        SDL_SetWindowSize(window, 1280, 720);
                        SetWindowSize1920x1080 = false;
                        SetWindowSize800x600 = false;
                        SetWindowSize1280x720 = true;
                    }
                    if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 790 && e.button.x <= 990 && e.button.y >= 380 && e.button.y <= 455) {
                        playSound(clickButton);
                        SDL_SetWindowSize(window, 1920, 1080);
                        SetWindowSize1920x1080 = true;
                        SetWindowSize800x600 = false;
                        SetWindowSize1280x720 = false;
                    }
                    if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 510 && e.button.x <= 645 && e.button.y >= 540 && e.button.y <= 595) {
                        playSound(clickButton);
                    }
                    if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 695 && e.button.x <= 830 && e.button.y >= 540 && e.button.y <= 595) {
                        playSound(clickButton);
                    }
                }
                if (!SetWindowSize1920x1080 && !SetWindowSize1280x720 && SetWindowSize800x600) {
                    if (!inSettingsPage && !inAuthorsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 60 && e.button.x <= 370 && e.button.y >= 100 && e.button.y <= 190) {
                        playSound(clickButton);
                    }
                    if (!inSettingsPage && !inAuthorsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 60 && e.button.x <= 370 && e.button.y >= 210 && e.button.y <= 300) {
                        playSound(clickButton);
                        inSettingsPage = true;
                        /////////////////// здесь кнопка играть 800/600, сюда код игры
                    }
                    if (!inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 60 && e.button.x <= 370 && e.button.y >= 320 && e.button.y <= 410) {
                        playSound(clickButton);
                        inAuthorsPage = true;
                    }
                    if (!inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 60 && e.button.x <= 370 && e.button.y >= 430 && e.button.y <= 520)
                        quit = true;
                    if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 190 && e.button.x <= 310 && e.button.y >= 315 && e.button.y <= 380) {
                        playSound(clickButton);
                        SDL_SetWindowSize(window, 800, 600);
                        SetWindowSize1920x1080 = false;
                        SetWindowSize800x600 = true;
                        SetWindowSize1280x720 = false;
                    }
                    if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 340 && e.button.x <= 460 && e.button.y >= 315 && e.button.y <= 380) {
                        playSound(clickButton);
                        SDL_SetWindowSize(window, 1280, 720);
                        SetWindowSize1920x1080 = false;
                        SetWindowSize800x600 = false;
                        SetWindowSize1280x720 = true;
                    }
                    if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 490 && e.button.x <= 510 && e.button.y >= 315 && e.button.y <= 380) {
                        playSound(clickButton);
                        SDL_SetWindowSize(window, 1920, 1080);
                        SetWindowSize1920x1080 = true;
                        SetWindowSize800x600 = false;
                        SetWindowSize1280x720 = false;
                    }
                    if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 300 && e.button.x <= 390 && e.button.y >= 455 && e.button.y <= 495) {
                        playSound(clickButton);
                    }
                    if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 450 && e.button.x <= 540 && e.button.y >= 455 && e.button.y <= 495) {
                        playSound(clickButton);
                    }
                }
            }
             else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_ESCAPE) {
                    if (inSettingsPage) {
                        playSound(clickButton);
                        inSettingsPage = false;
                    }
                    if (e.key.keysym.sym == SDLK_ESCAPE) {
                        if (inAuthorsPage) {
                            playSound(clickButton);
                            inAuthorsPage = false;
                        }
                    }
                }
            }
            if (SetWindowSize1920x1080) {
                if (!inSettingsPage && !inAuthorsPage) {
                    SDL_RenderCopy(renderer, backgroundTexture[0], NULL, NULL);
                    SDL_RenderCopy(renderer, backgroundTexture[2], NULL, NULL);
                    int buttonWidth = 700;
                    int buttonHeight = 160;
                    int buttonSpacing = 20;
                    int startY = 210;

                    for (int i = 0; i < 4; ++i) {
                        int startX = 100;
                        drawButton(renderer, buttonTextures[i], startX, startY + i * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight);
                    }
                    SDL_RenderCopy(renderer, backgroundTexture[1], NULL, NULL);
                }
                else if (inSettingsPage) {
                    SDL_RenderCopy(renderer, backgroundTexture[3], NULL, NULL);

                    int buttonWidth = 430;
                    int buttonHeight = 110;
                    int buttonSpacing = 60;
                    int startY = 310;
                    int startX = 500;

                    for (int i = 0; i < 2; ++i)
                        drawButton(renderer, settingsButtonTextures[i], startX + i * (buttonWidth + buttonSpacing), startY, buttonWidth, buttonHeight);

                    if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 500 && e.button.x <= 930 && e.button.y >= 310 && e.button.y <= 420) {
                        playSound(clickButton);
                        SDL_SetWindowFullscreen(window, 0);
                    }
                    else if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 990 && e.button.x <= 1420 && e.button.y >= 310 && e.button.y <= 420) {
                        playSound(clickButton);
                        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
                    }
                    buttonWidth = 300;
                    buttonHeight = 111;
                    buttonSpacing = 50;
                    startY = 570;
                    startX = 460;
                    for (int i = 2; i < 5; ++i)
                        drawButton(renderer, settingsButtonTextures[i], startX + (i - 2) * (buttonWidth + buttonSpacing), startY, buttonWidth, buttonHeight);

                    buttonWidth = 200;
                    buttonHeight = 75;
                    buttonSpacing = 100;
                    startY = 815;
                    startX = 720;
                    for (int i = 5; i < 7; ++i)
                        drawButton(renderer, settingsButtonTextures[i], startX + (i - 5) * (buttonWidth + buttonSpacing), startY, buttonWidth, buttonHeight);
                }
                else if (inAuthorsPage)
                    SDL_RenderCopy(renderer, authorsBackgroundTexture, NULL, NULL);
                SDL_RenderPresent(renderer);
            }
            else if (SetWindowSize1280x720) {
                if (!inSettingsPage && !inAuthorsPage) {
                    SDL_RenderCopy(renderer, backgroundTexture[0], NULL, NULL);
                    SDL_RenderCopy(renderer, backgroundTexture[2], NULL, NULL);
                    int buttonWidth = 450;
                    int buttonHeight = 110;
                    int buttonSpacing = 20;
                    int startY = 140;

                    for (int i = 0; i < 4; ++i) {
                        int startX = 50;
                        drawButton(renderer, buttonTextures[i], startX, startY + i * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight);
                    }
                    SDL_RenderCopy(renderer, backgroundTexture[1], NULL, NULL);
                }
                else if (inSettingsPage) {
                    SDL_RenderCopy(renderer, backgroundTexture[3], NULL, NULL);

                    int buttonWidth = 300;
                    int buttonHeight = 75;
                    int buttonSpacing = 10;
                    int startY = 210;
                    int startX = 340;

                    for (int i = 0; i < 2; ++i)
                        drawButton(renderer, settingsButtonTextures[i], startX + i * (buttonWidth + buttonSpacing), startY, buttonWidth, buttonHeight);

                    if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 340 && e.button.x <= 640 && e.button.y >= 210 && e.button.y <= 285) {
                        playSound(clickButton);
                        SDL_SetWindowFullscreen(window, 0);
                    }
                    else if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 650 && e.button.x <= 950 && e.button.y >= 210 && e.button.y <= 285) {
                        playSound(clickButton);
                        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
                    }
                    buttonWidth = 200;
                    buttonHeight = 75;
                    buttonSpacing = 50;
                    startY = 380;
                    startX = 290;
                    for (int i = 2; i < 5; ++i)
                        drawButton(renderer, settingsButtonTextures[i], startX + (i - 2) * (buttonWidth + buttonSpacing), startY, buttonWidth, buttonHeight);
                    buttonWidth = 135;
                    buttonHeight = 55;
                    buttonSpacing = 50;
                    startY = 540;
                    startX = 510;
                    for (int i = 5; i < 7; ++i)
                        drawButton(renderer, settingsButtonTextures[i], startX + (i - 5) * (buttonWidth + buttonSpacing), startY, buttonWidth, buttonHeight);
                }
                else if (inAuthorsPage)
                    SDL_RenderCopy(renderer, authorsBackgroundTexture, NULL, NULL);
                SDL_RenderPresent(renderer);

            }
            else if (SetWindowSize800x600) {
                if (!inSettingsPage && !inAuthorsPage) {
                    SDL_RenderCopy(renderer, backgroundTexture[0], NULL, NULL);
                    SDL_RenderCopy(renderer, backgroundTexture[2], NULL, NULL);
                    int buttonWidth = 310;
                    int buttonHeight = 90;
                    int buttonSpacing = 20;
                    int startY = 100;

                    for (int i = 0; i < 4; ++i) {
                        int startX = 60;
                        drawButton(renderer, buttonTextures[i], startX, startY + i * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight);
                    }
                    SDL_RenderCopy(renderer, backgroundTexture[1], NULL, NULL);
                }
                else if (inSettingsPage) {
                    SDL_RenderCopy(renderer, backgroundTexture[3], NULL, NULL);

                    int buttonWidth = 170;
                    int buttonHeight = 70;
                    int buttonSpacing = 60;
                    int startY = 165;
                    int startX = 200;

                    for (int i = 0; i < 2; ++i)
                        drawButton(renderer, settingsButtonTextures[i], startX + i * (buttonWidth + buttonSpacing), startY, buttonWidth, buttonHeight);

                    if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 200 && e.button.x <= 370 && e.button.y >= 165 && e.button.y <= 235) {
                        playSound(clickButton);
                        SDL_SetWindowFullscreen(window, 0);
                    }
                    else if (inSettingsPage && e.button.button == SDL_BUTTON_LEFT && e.button.x >= 430 && e.button.x <= 600 && e.button.y >= 165 && e.button.y <= 235) {
                        playSound(clickButton);
                        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
                    }
                    buttonWidth = 120;
                    buttonHeight = 65;
                    buttonSpacing = 30;
                    startY = 315;
                    startX = 190;
                    for (int i = 2; i < 5; ++i)
                        drawButton(renderer, settingsButtonTextures[i], startX + (i - 2) * (buttonWidth + buttonSpacing), startY, buttonWidth, buttonHeight);
                    buttonWidth = 90;
                    buttonHeight = 40;
                    buttonSpacing = 50;
                    startY = 455;
                    startX = 300;
                    for (int i = 5; i < 7; ++i)
                        drawButton(renderer, settingsButtonTextures[i], startX + (i - 5) * (buttonWidth + buttonSpacing), startY, buttonWidth, buttonHeight);
                }
                else if (inAuthorsPage)
                    SDL_RenderCopy(renderer, authorsBackgroundTexture, NULL, NULL);
                SDL_RenderPresent(renderer);
            }
        }
    }
        for (int i = 0; i < 4; ++i)
            SDL_DestroyTexture(backgroundTexture);
        for (int i = 0; i < 7; ++i)
            SDL_DestroyTexture(settingsButtonTextures[i]);
        for (int i = 0; i < 4; ++i)
            SDL_DestroyTexture(buttonTextures[i]);
        SDL_DestroyTexture(authorsBackgroundTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

        return 0;
    }