#ifndef RAYCAST_H_
#define RAYCAST_H_

#include "utils.h"

#define MAX_STEPS 20

float Raycast( SDL_FPoint position, float rotate, const uint8_t *map );

#endif
