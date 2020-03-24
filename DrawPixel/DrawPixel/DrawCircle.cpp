#include "DrawCircle.h"
DrawCircle::DrawCircle(int radius, Vector2 v, SDL_Renderer* gRenderer) {

	p = 1 - radius;
	x = 0;
	y = radius;

	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);

	for (; x <= y;) {
		if (p <= 0) {
			x = x + 1;
			y = y;
			p = p + (2 * x) + 3;
		}
		else {
			x = x + 1;
			y = y - 1;
			p = p + (2 * x) - (2 * y) + 5;
		}

		SDL_RenderDrawPoint(gRenderer, x + v.a, y + v.b);
		SDL_RenderDrawPoint(gRenderer, -x +v.a, y + v.b);
		SDL_RenderDrawPoint(gRenderer, -x +v.a, -y +v.b);
		SDL_RenderDrawPoint(gRenderer, x + v.a,-y + v.b);
		SDL_RenderDrawPoint(gRenderer, y + v.a, x + v.b);
		SDL_RenderDrawPoint(gRenderer, -y +v.a, x + v.b);
		SDL_RenderDrawPoint(gRenderer, -y +v.a, -x +v.b); 
		SDL_RenderDrawPoint(gRenderer, y + v.a,-x + v.b);
	}

	SDL_SetRenderDrawColor(gRenderer, 0x50, 0xF0, 0xFF, 0xFF);
}
