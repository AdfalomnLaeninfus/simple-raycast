#include <utils.h>

Player::Player(SDL_FPoint position, float rotate) : position( position ), rotate( rotate )
{
    rays.resize(MAX_RAYS);
}

SDL_FPoint Player::getPosition() const { return position; }

int Player::getRayLength() { return rays.size(); }
int Player::getRay( const int index ) { return rays[index]; }

bool Player::canMove( const uint8_t *map, float dirX, float dirY )
{
    auto checkCollision = [&] ( float offsetX, float offsetY )
    {
        return map_collision( map, dirX, dirY );
    };

    return (
        checkCollision( -1, -1 ) && checkCollision( 1, -1 ) &&
        checkCollision( -1, 1 )  && checkCollision( 1, 1 )
    );
}

void Player::updateRays( const uint8_t *map )
{
    for (int i = 0; i <= MAX_RAYS; i++)
    {
        int rayIndex = i - MAX_RAYS * 0.5f;
        float rayAngle = rotate + DEG2RAD(rayIndex / 4);
        rays[i] = Raycast( position, rayAngle, map );
    }
}

void Player::updatePosition( const float deltaTime, const uint8_t *map, const Uint8 *keys )
{
    int verticalInput = keys[SDL_SCANCODE_UP] - keys[SDL_SCANCODE_DOWN];
    int horizontalInput = keys[SDL_SCANCODE_UP] - keys[SDL_SCANCODE_DOWN];

    SDL_FPoint speed = {
        (verticalInput) * cos(rotate) * velocity * deltaTime,
        (horizontalInput) * sin(rotate) * velocity * deltaTime
    };

    if ( canMove( map, speed.x, -1 ) && canMove( map, speed.x, 1 ) ) position.x += speed.x;
    if ( canMove( map, speed.y, -1 ) && canMove( map, speed.y, 1 ) ) position.y += speed.y;
}

void Player::updateRotation( const float deltaTime, const Uint8 *keys )
{
    rotate += (keys[SDL_SCANCODE_RIGHT] - keys[SDL_SCANCODE_LEFT]) * DEG2RAD(maxRotation) * deltaTime;
}

void Player::update( const float deltaTime, const Uint8* keys, const uint8_t *map )
{
    updateRotation( deltaTime, keys );
    updatePosition( deltaTime, map, keys );
    updateRays( map );
}

void Player::renderPlayer( SDL_Renderer *renderer )
{
    SDL_FRect playerRect = {
        (position.x * WALL_SCALE) - (WALL_SCALE * 0.5f),
        (position.y * WALL_SCALE) - (WALL_SCALE * 0.5f),
        WALL_SCALE, WALL_SCALE
    };

    SDL_RenderFillRectF(renderer, &playerRect);
}

void Player::renderRays( SDL_Renderer *renderer )
{
    renderPlayer( renderer );

    for (int i = 0; i <= rays.size(); i++)
    {
        int rayIndex = i - (MAX_RAYS * 0.5f);
        float rayAngle = rotate + DEG2RAD(rayIndex / 4);
        float rayDistance = rays[i] * 0.2f;

        float positionXDirection = position.x + cosf( rayAngle );
        float positionYDirection = position.y + sinf( rayAngle );

        SDL_RenderDrawLineF(
            renderer,
            position.x * WALL_SCALE,
            position.y * WALL_SCALE,
            ( positionXDirection * rayDistance ) * WALL_SCALE,
            ( positionYDirection * rayDistance ) * WALL_SCALE
        );
    }
}

void Player::render( SDL_Renderer *renderer )
{
    renderPlayer( renderer );
    renderRays( renderer );
}