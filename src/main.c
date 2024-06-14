#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>

struct Bird {
    SDL_Rect rect;
    float vel_x, vel_y;
};

SDL_Rect init_bird(int h);
void update_bird(SDL_Renderer *rend,struct Bird bird, double delta);
void draw_bird(SDL_Renderer *rend, SDL_Rect bird_rect);

int main() {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Init(SDL_INIT_VIDEO);

    int width = 420;
    int height = 520;

    Uint32 prevTicks = 0;
    Uint32 currentTicks = 0;
    float delta = 0.0f;
    
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Simple SDL2 Window");

    struct Bird bird;

    bird.rect =  init_bird(height);
    
    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        prevTicks = currentTicks;
        currentTicks = SDL_GetTicks();
        delta = (currentTicks - prevTicks) / 1000.0f;

        SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
        SDL_RenderClear(renderer);
        update_bird(renderer, bird, delta);

        draw_bird(renderer, bird.rect);
        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void draw_bird(SDL_Renderer *rend, SDL_Rect bird_rect) {
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
    SDL_RenderDrawRect(rend, &bird_rect); 
}

SDL_Rect init_bird(int h) {
    SDL_Rect bird;
    bird.h = 40;
    bird.w = 40;
    bird.x = 80;
    bird.y = (h / 2) - 20;
    return bird;
}

void update_bird(SDL_Renderer *rend, struct Bird bird, double delta) {
    
}
