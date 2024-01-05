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
    #include "Player.h"
    #include "Raycast.h"

    #define WIDTH 320
    #define HEIGHT 240

    #define MAP_WIDTH 20
    #define MAP_HEIGHT 20

    #define SCALE 2
    #define RAYS 320

    #define DEG2RAD(r) r * M_PI / 180

#endif