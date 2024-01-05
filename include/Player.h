#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "utils.h"

class Player
{
    public:
        Player( SDL_FPoint position, float rotate );

        SDL_FPoint getPosition() const;

        void update( const float dt, const Uint8 *keys, uint8_t *map );
        void render( SDL_Renderer *renderer );

    private:
        SDL_FPoint position;

        float rotate;
        float vel = 6;
        float rotate_vel = 180;
        std::vector<float> rays;

        bool canMove( const uint8_t *map, float dirX, float dirY, int offset );

        void updatePosition( const float dt, const uint8_t *map );
        void updateRotation( const float dt, const Uint8 *keys );
        void updateRays();

        void renderPlayer( SDL_Renderer *renderer );
        void renderRays( SDL_Renderer *renderer );
};

#endif
