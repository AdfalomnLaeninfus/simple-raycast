#include <raycast.h>

float Raycast(SDL_FPoint position, float rotate)
{
    SDL_FPoint pos = position;
    float c = cos(rotate);
    float s = sin(rotate);

    for (int i = 0; i < MAX_STEPS; i++)
    {
        pos.x += c;
        pos.y += s;

        if (map_collision(pos.x, pos.y))
        {
            while (map_collision(pos.x, pos.y))
            {
                pos.x -= c * 0.01;
                pos.y -= s * 0.01;
            }
            break;
        }
    }

    float dx = position.x - pos.x;
    float dy = position.y - pos.y;
    return sqrt(dx*dx + dy*dy);
}
