#include "../../resource/header.h"

void render_cutscene(SDL_Renderer* renderer, const char* text, SDL_Window* window, int delay) {
    SDL_Color textColor = {255, 255, 255};
    sdl_ttf();
    TTF_Font* font = TTF_OpenFont("../resource/static/fonts/font.ttf", 64);
    if (!font) {
        printf("Failed to load font: %s\n", TTF_GetError());
        return;
    }

    bool cutsceneActive = true;

    // Render background outside of the loop

    // Calculate the total height of the text
    int totalTextHeight = 0;
    int lineCount = 1; // Initial line count

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '\n') {
            lineCount++;
        }
    }

    totalTextHeight = TTF_FontHeight(font) * lineCount;

    // Calculate the initial Y-coordinate for centering
    int y = (SCREEN_HEIGHT - totalTextHeight) / 2;

    // Use a string builder or snprintf for efficient string manipulation
    char line[256];
    line[0] = '\0';  // Initialize the line

    int lastDisplayedIndex = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && (event.key.keysym.sym == SDLK_ESCAPE || event.key.keysym.sym == SDLK_SPACE))) {
                cutsceneActive = false;
                break;
            }
        }

        // Check for newline character
        if (text[i] == '\n') {
            // Move to the next line
            y += TTF_FontHeight(font) + 10; // Add padding between lines
            line[0] = '\0';  // Clear the line for the next line
            continue;
        }

        // Check if the cutscene is still active
        if (!cutsceneActive) {
            break;
        }

        // Efficiently append character to the line
        snprintf(&line[strlen(line)], sizeof(line) - strlen(line), "%c", text[i]);
        SDL_RenderClear(renderer);
        render_bg(renderer, load_texture("../resource/static/cutscene_bg.PNG", renderer));

        // Render only when a new character is added
        if (i >= lastDisplayedIndex) {
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, line, textColor);
            if (!textSurface) {
                // Handle error creating text surface
                return;
            }

            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            if (!textTexture) {
                // Handle error creating texture
                SDL_FreeSurface(textSurface);
                return;
            }

            // Calculate the X-coordinate for centering
            int x = (SCREEN_WIDTH - textSurface->w) / 2;

            SDL_Rect destRect = {x, y, textSurface->w, textSurface->h};

            // Render the text
            SDL_RenderCopy(renderer, textTexture, NULL, &destRect);

            // Free resources
            SDL_FreeSurface(textSurface);
            SDL_DestroyTexture(textTexture);

            // Present the renderer
            SDL_RenderPresent(renderer);

            // Delay for a short time between characters
            SDL_Delay(delay);

            // Update the index of the last displayed character
            lastDisplayedIndex = i + 1;
        }
    }
    if(cutsceneActive) SDL_Delay(6000);

    // Cleanup
    TTF_CloseFont(font);
    TTF_Quit();
}