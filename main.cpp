#include <iostream>

#include <utils.h>

const uint8_t map[MAP_WIDTH * MAP_HEIGHT] = 
{
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 
    1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 
    1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
    1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
    1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
};

int main(int argc, char* argv[])
{
    SDL_Event event;
    SDL_Window* window;
    SDL_Renderer* renderer;
    
    Player player( ( SDL_FPoint ) { 4, 4 }, 0.0 );

    Uint64 currentTime = 0;
    Uint64 startTime = 0;
    Uint64 lastTime = 0;
    Uint64 timeDifference = 0;
    float deltaTime = 0.0f;

    const Uint8 *keys = SDL_GetKeyboardState(NULL);

    Color_t darkColor = { 25, 25, 25, 255 };
    Color_t whiteColor = { 255, 255, 255, 255 };

    SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO);

    window = SDL_CreateWindow("raiox", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN );
    if( window == nullptr ) { printf("ERRO: %s\n", SDL_GetError()); return -1; }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if( renderer == nullptr ) { printf("ERRO: %s\n", SDL_GetError()); return -1; }

    bool is_running = true;
    while( is_running )
    {
        startTime = SDL_GetTicks64();
        while( SDL_PollEvent( &event ) )
        {
            switch ( event.type )
            {
                case SDL_QUIT:
                    is_running = false;
                    break;
            }
        }

        player.update( deltaTime, keys, map );

        SDL_SetRenderDrawColor( renderer, darkColor.r, darkColor.g, darkColor.b, darkColor.a );
        SDL_RenderClear( renderer );

        raycast_draw_rays( &player, renderer );
        map_draw_walls( renderer, whiteColor, map );

        player.render( renderer );

        currentTime = SDL_GetTicks64();
        
        SDL_RenderPresent( renderer );

        deltaTime = (currentTime - startTime) * 0.02f;
        startTime = currentTime;
    }

    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    SDL_Quit();

    return 0;
}
