#include <utils.h>
#include <raycast.h>

float Raycast( SDL_FPoint position, float rotate, const uint8_t *map )
{
    SDL_FPoint positionOffset = position;
    float rotateCosAngle = cos(rotate);
    float rotateSinAngle = sin(rotate);

    for (int i = 0; i < MAX_STEPS; i++)
    {
        positionOffset.x += rotateCosAngle;
        positionOffset.y += rotateSinAngle;

        if ( map_collision( map, positionOffset.x, positionOffset.y ) )
        {
            while ( map_collision( map, positionOffset.x, positionOffset.y ) )
            {
                positionOffset.x -= rotateCosAngle * 0.01;
                positionOffset.y -= rotateSinAngle * 0.01;
            }

            break;
        }
    }

    float directionX = position.x - positionOffset.x;
    float directionY = position.y - positionOffset.y;
    float directionXPowTwo = directionX * directionX;
    float directionYPowTwo = directionY * directionY;

    return sqrt( directionXPowTwo + directionYPowTwo );
}

void raycast_draw_rays( Player *player, SDL_Renderer *renderer ) {
    for ( int i = 0; i <= player->getRayLength(); i++ )
    {
        int colorIntensity = 128 / player->getRay( i ) + 25;
        int rayIndex = i - MAX_RAYS / 2;

        float halfHeight = HEIGHT * 0.5f;
        float halfColorIntensity = colorIntensity * 0.5f;

        Color_t color = {
            static_cast<int>( colorIntensity + 25 ),
            static_cast<int>( colorIntensity + 25 ),
            static_cast<int>( colorIntensity + 25 ),
            255
        };

        SDL_SetRenderDrawColor( renderer,
            color.r, color.g, color.b, color.a );

        SDL_RenderDrawLine(
            renderer,
            i, halfHeight - halfColorIntensity,
            i, halfHeight + halfColorIntensity
        );
    }
}
