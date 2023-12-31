#include <Player.h>

Player::Player(SDL_FPoint position, float rotate)
{
    this->position = position;
    this->rotate = rotate;
    rays.resize(RAYS);
}

void Player::update(float dt)
{
    rotate += (keys[SDL_SCANCODE_RIGHT] - keys[SDL_SCANCODE_LEFT]) * DEG2RAD(rotate_vel) * dt;

    SDL_FPoint spd = {0, 0};
    spd.x += (keys[SDL_SCANCODE_UP] - keys[SDL_SCANCODE_DOWN]) * cos(rotate) * vel * dt;
    spd.y += (keys[SDL_SCANCODE_UP] - keys[SDL_SCANCODE_DOWN]) * sin(rotate) * vel * dt;
    
    if (map_collision(position.x + spd.x, position.y) == 0)
        position.x += spd.x;
    if (map_collision(position.x, position.y + spd.y) == 0)
        position.y += spd.y;

    for (int i = 0; i <= RAYS; i++)
    {
        int id = i - RAYS / 2;
        float r = rotate + DEG2RAD(id / 4);
        rays[i] = Raycast(position, r);
    }
}

void Player::render(SDL_Renderer* renderer)
{
    SDL_FRect r = {position.x * SCALE - SCALE / 2, position.y * SCALE - SCALE/2, SCALE, SCALE};
    SDL_RenderFillRectF(renderer, &r);
    
    for (int i = 0; i <= rays.size(); i++)
    {
        int id = i - RAYS / 2;
        float r = rotate + DEG2RAD(id / 4);
        float dist = rays[i];

        SDL_RenderDrawLineF(renderer, position.x * SCALE, position.y * SCALE,
                                        (position.x + cos(r) * dist) * SCALE, (position.y + sin(r) * dist) * SCALE);
    }
}
