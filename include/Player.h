#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "utils.h"

class Player
{
    public:
        Player( SDL_FPoint position, float rotate );

        SDL_FPoint getPosition() const;

        int getRayLength();
        int getRay( const int index );

        void update( const float dt, const Uint8 *keys, const uint8_t *map );
        void render( SDL_Renderer *renderer );

    private:
        SDL_FPoint position;

        float rotate = 0;
        float velocity = 6;
        float maxRotation = 180;
        std::vector<float> rays;

        bool canMove( const uint8_t *map, float dirX, float dirY );

        void updatePosition( const float deltaTime, const uint8_t *map, const Uint8 *keys );
        void updateRotation( const float deltaTime, const Uint8 *keys );
        void updateRays( const uint8_t *map );

        void renderPlayer( SDL_Renderer *renderer );
        void renderRays( SDL_Renderer *renderer );
};

#endif
