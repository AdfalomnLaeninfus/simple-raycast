#include <map.h>

const uint8_t map_collision(int x, int y)
{
    if ( x < 0 || y < 0 || x >= MAP_WIDTH || y >= MAP_HEIGHT )
        return 1;

    return map[y * MAP_WIDTH + x];
}