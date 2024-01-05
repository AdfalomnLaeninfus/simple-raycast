#include <raycast.h>

float Raycast(SDL_FPoint position, float rotate, const uint8_t *map)
{
    SDL_FPoint pos = position;
    float c = cos(rotate);
    float s = sin(rotate);

    for (int i = 0; i < MAX_STEPS; i++)
    {
        pos.x += c;
        pos.y += s;

        if (map_collision(map, pos.x, pos.y))
        {
            while (map_collision(map, pos.x, pos.y))
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

void raycast_draw_rays( Player player, SDL_Renderer *renderer ) {
    for (int i = 0; i <= player.rays.size(); i++)
    {
        int s = 128 / player.rays[i] + 25;
        int id = i - RAYS / 2;

        SDL_SetRenderDrawColor(renderer, s + 25, s + 25, s + 25, 255);
        SDL_RenderDrawLine(renderer, i, HEIGHT / 2 - s / 2, i, HEIGHT / 2 + s / 2);
    }
}
