#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <iostream>
#include <vector>
#include <cmath>
#include <conf.h>

#include <Raycast.h>

class Player
{
    public:
        Player(SDL_FPoint position, float rotate);

        void update(float dt);
        void render(SDL_Renderer* renderer);

        std::vector<float> rays;
    private:
        SDL_FPoint position;
        float rotate;

        float rotate_vel = 180;
        float vel = 6;
};

#endif
