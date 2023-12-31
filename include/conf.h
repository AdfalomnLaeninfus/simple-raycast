#ifndef CONF_H_
#define CONF_H_

#include <SDL2/SDL.h>

#define WIDTH 320
#define HEIGHT 240

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

#define SCALE 2
#define RAYS 320

#define DEG2RAD(r) r * M_PI / 180

extern const Uint8* keys;
extern const uint8_t map[MAP_WIDTH * MAP_HEIGHT];
extern const uint8_t map_collision(int x, int y);

#endif