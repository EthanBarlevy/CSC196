#include "renderer.h"
#include <SDL.h>

namespace vl
{
	SDL_Renderer* renderer{ nullptr };
	SDL_Window* window{ nullptr };

	void CreateWindow(int width, int height)
	{
		SDL_Init(SDL_INIT_VIDEO);

		window = SDL_CreateWindow("Game", 100, 100, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	}
}
