#ifndef RAYCAST_H_
#define RAYCAST_H_

#include "utils.h"

#define MAX_STEPS 20

extern float Raycast( SDL_FPoint position, float rotate, const uint8_t *map );
extern void raycast_draw_rays( Player *player, SDL_Renderer *renderer );

#endif
