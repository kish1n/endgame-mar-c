#include "../../resource/header.h"

void game_cutscene2(SDL_Renderer* renderer, SDL_Window* window)
{
    const char* morphing[] = {"1", "2", "3", "4", "5"};
    sdl_init();
    SDL_RenderClear(renderer);

    for (int i = 0; i < sizeof(morphing) / sizeof(morphing[0]); i++)
    {
        char* path = (char*)malloc(strlen("../resource/static/morph/") + strlen(morphing[i]) + strlen(".png") + 1);
        strcpy(path, "../resource/static/morph/");
        strcat(path, morphing[i]);
        strcat(path, ".png");

        // Load and render the image
        render_bg(renderer, load_texture(path, renderer));

        // Update the screen
        SDL_RenderPresent(renderer);

        // Pause for 2000 milliseconds
        SDL_Delay(2000);
    }

    const char* text = "Finally she fixed everything and became herself...\n"
                       "forever...\n";
    int delay = 100; // Set the delay between characters
    render_cutscene(renderer, text, window, delay);
}