#include <SDL2/SDL.h>
#include <stdio.h>
#include "../include/defs.h"
#include "raycaster.h"

int main(void) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    Player player = {
        .posX = 22,
        .posY = 12,
        .dirX = -1,
        .dirY = 0,
        .planeX = 0,
        .planeY = 0.66
    };

    // To change the camera angle, modify dirX, dirY, planeX, and planeY
    // For example, to rotate 90 degrees clockwise:
    // player.dirX = 0;
    // player.dirY = 1;
    // player.planeX = 0.66;
    // player.planeY = 0;

    int quit = 0;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            // Add keyboard event handling here for player movement
        }

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Render the walls
        castRays(renderer, &player);

        // Update the screen
        SDL_RenderPresent(renderer);

        // Add a small delay to control frame rate
        SDL_Delay(16);  // Approximately 60 FPS
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
