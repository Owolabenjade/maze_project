#ifndef RAYCASTER_H
#define RAYCASTER_H

#include <SDL2/SDL.h>

typedef struct {
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
} Player;

void castRays(SDL_Renderer *renderer, Player *player);

#endif
