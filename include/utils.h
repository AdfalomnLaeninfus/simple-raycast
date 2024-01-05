#ifndef _UTILS_H_
#define _UTILS_H_

    #if defined(win32) || defined(_WIN32)
        #define SDL_MAIN_HANDLED
    #endif
    
    #include <SDL2/SDL.h>
    #include <cmath>
    #include <vector>
    #include <stdint.h>
    #include <iostream>
    
    #include "map.h"
    #include "player.h"
    #include "raycast.h"
    #include "color.h"

    #define WIDTH 320
    #define HEIGHT 240

    #define MAP_WIDTH 20
    #define MAP_HEIGHT 20

    #define WALL_SCALE 2
    #define MAX_RAYS 320

    #define PI_DIV_180 0.01745329251994329576923690

    #define DEG2RAD(r) r * PI_DIV_180

#endif