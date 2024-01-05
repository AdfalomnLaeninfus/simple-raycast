#include <map.h>

const uint8_t map_collision(const uint8_t *map, int x, int y)
{
    if ( x < 0 || y < 0 || x >= MAP_WIDTH || y >= MAP_HEIGHT ) return 1;

    return map[y * MAP_WIDTH + x];
}

void map_draw_walls( SDL_Renderer *renderer, Color_t wallColor )
{
    SDL_SetRenderDrawColor( renderer, whiteColor.r, whiteColor.g, whiteColor.b, whiteColor.a );

    for (int y = 0; y < MAP_HEIGHT; y++)
        for (int x = 0; x < MAP_HEIGHT; x++)
        {
            SDL_Rect wallRect = { x * WALL_SCALE, y * WALL_SCALE, WALL_SCALE, WALL_SCALE };
            if (map[y * MAP_WIDTH + x]) SDL_RenderFillRect(renderer, &wallRect);
        }
}