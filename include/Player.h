#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <Raycast.h>

class Player
{
    public:
        Player( SDL_FPoint position, float rotate );

        void update( const float dt, const Uint8 *keys, const uint8_t *map );
        void render( SDL_Renderer* renderer );

        std::vector<float> rays;
    private:
        SDL_FPoint position;

        float rotate;
        float vel = 6;
        float rotate_vel = 180;
};

#endif
