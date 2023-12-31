#include <Raycast.h>

float Raycast(SDL_FPoint position, float rotate)
{
    SDL_FPoint pos = position;

    for (int i = 0; i < MAX_STEPS * 100; i++)
    {
        pos.x += cos(rotate) * 0.01;
        pos.y += sin(rotate) * 0.01;

        if (map_collision(pos.x, pos.y))
            break;
    }

    return sqrt(pow(position.x - pos.x, 2) + pow(position.y - pos.y, 2));
}
