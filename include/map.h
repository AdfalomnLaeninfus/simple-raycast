#ifndef _MAP_H_
#define _MAP_H_

    #include "utils.h"

    extern const uint8_t map_collision( const uint8_t *map, int x, int y );
    extern void map_draw_walls( SDL_Renderer *renderer, Color_t wallColor );

#endif