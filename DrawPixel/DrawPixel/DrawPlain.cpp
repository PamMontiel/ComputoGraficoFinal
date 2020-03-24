#include "DrawPlain.h"
DrawPlain::DrawPlain(int SCREEN_WIDTH, int SCREEN_HEIGHT, SDL_Renderer* gRenderer, int tam) {
	SDL_SetRenderDrawColor(gRenderer, 255, 170, 250, 0xFF);

	//Dibujamos en y desde la mitad
	SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT, SCREEN_WIDTH / 2, 0);
	SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT / 2, 0, SCREEN_HEIGHT / 2);

	SDL_SetRenderDrawColor(gRenderer, 255, 170, 250, 0xFF);
	for (int i = SCREEN_HEIGHT / 2; i < SCREEN_HEIGHT;)
	{
		i += tam;
		SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT - i);
		SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);

	}

	//Dibujamos en x desde la mitad
	for (int i = SCREEN_WIDTH / 2; i < SCREEN_WIDTH;)
	{
		i += tam;
		SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH - i, SCREEN_HEIGHT / 2);
		SDL_RenderDrawPoint(gRenderer, i, SCREEN_HEIGHT / 2);
	}

	SDL_SetRenderDrawColor(gRenderer, 225, 255, 255, 0xFF);
	for (int i = (SCREEN_WIDTH / 2) + tam; i < SCREEN_WIDTH; i += tam)
	{
		for (int j = (SCREEN_HEIGHT / 2) + tam; j < SCREEN_HEIGHT; j += tam)
		{
			SDL_RenderDrawPoint(gRenderer, i, j);
			SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH - i, j);
			SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH - i, SCREEN_HEIGHT - j);
			SDL_RenderDrawPoint(gRenderer, i, SCREEN_HEIGHT - j);
		}
	}
}
