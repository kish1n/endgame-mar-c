#include "../../resource/header.h"

void game_cutscene1(SDL_Renderer* renderer, SDL_Window* window)
{
    const char* text = "I felt that something had changed, \nbut I couldn't figure out what exactly.\n"
                       "The mysterious incident enveloped me \nin an unknown excitement, creating tension in the air.\n"
                       "Fate seems to give us signs, \nbut unraveling their meaning is not an easy task.\n"
                       "I didn't understand what was happening, but I hope \nthat there is still a chance to fix everything...\n";
    int delay = 100; // Set the delay between characters
    render_cutscene(renderer, text, window, delay);
}