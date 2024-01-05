#include <utils.h>

Player::Player(SDL_FPoint position, float rotate) : position( position ), rotate( rotate )
{
    rays.resize(RAYS);
}

SDL_FPoint Player::getPosition() const { return position; }

int Player::getRayLength() { return rays.size(); }
int Player::getRay( const int index ) { return rays[index]; }

bool canMove( const uint8_t *map, float dirX, float dirY )
{
    auto checkCollision = [&] ( float offsetX, float offsetY )
    {
        return map_collision( map, dirX, dirY );
    };

    return (
        checkCollision( -1, -1 ) && checkCollision( 1, -1 ) &&
        checkCollision( -1, 1 ) && checkCollision( 1, 1 )
    );
}

void Player::updateRays( const uint8_t *map )
{
    for (int i = 0; i <= RAYS; i++)
    {
        int id = i - RAYS / 2;
        float r = rotate + DEG2RAD(id / 4);
        rays[i] = Raycast( position, r, map );
    }
}

void Player::updatePosition( const float dt, const uint8_t *map, const Uint8 *keys )
{
    int verticalInput = keys[SDL_SCANCODE_UP] - keys[SDL_SCANCODE_DOWN];
    int horizontalInput = keys[SDL_SCANCODE_UP] - keys[SDL_SCANCODE_DOWN];

    SDL_FPoint speed = {
        (verticalInput) * cos(rotate) * vel * dt,
        (horizontalInput) * sin(rotate) * vel * dt
    };

    if ( canMove( map, speed.x, -1 ) && canMove( map, speed.x, 1 ) ) position.x += speed.x;
    if ( canMove( map, speed.y, -1 ) && canMove( map, speed.y, 1 ) ) position.y += speed.y;
}

void Player::updateRotation( const float dt, const Uint8 *keys )
{
    rotate += (keys[SDL_SCANCODE_RIGHT] - keys[SDL_SCANCODE_LEFT]) * DEG2RAD(rotate_vel) * dt;
}

void Player::update( const float dt, const Uint8* keys, const uint8_t *map )
{

    updateRotation( dt, keys );
    updatePosition( dt, map, keys );
    updateRays( map );
}

void Player::renderPlayer( SDL_Renderer *renderer )
{
    SDL_FRect playerRect = {
        position.x * SCALE - SCALE / 2,
        position.y * SCALE - SCALE / 2,
        SCALE, SCALE
    };

    SDL_RenderFillRectF(renderer, &playerRect);
}

void Player::renderRays( SDL_Renderer *renderer )
{
    renderPlayer( renderer );

    for (int i = 0; i <= rays.size(); i++)
    {
        int id = i - RAYS / 2;
        float r = rotate + DEG2RAD(id / 4);
        float dist = rays[i];

        SDL_RenderDrawLineF(
            renderer,
            position.x * SCALE,
            position.y * SCALE,
            (position.x + cos(r) * dist) * SCALE,
            (position.y + sin(r) * dist) * SCALE
        );
    }
}

void Player::render( SDL_Renderer *renderer )
{
    renderPlayer( renderer );
    renderRays( renderer );
}