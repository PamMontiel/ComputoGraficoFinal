#include "DrawBezier.h"
DrawBezier::DrawBezier() {

}

DrawBezier::DrawBezier(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4, SDL_Renderer* gRenderer) {

	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
	float P0x, P0y;
	float P1x, P1y;
	float P2x, P2y;
	float P3x, P3y;

	P0x = 20;
	P0y = 20;
	P1x = 20;
	P1y = 200;
	P2x = 200;
	P2y = 200;
	P3x = 200;
	P3y = 20;

	float x, y;

	for (float t = 0; t <= 1; t += 0.001) {
		x = ((1 - t) * (1 - t) * (1 - t)) * v1.a + 3 * t * ((1 - t) * (1 - t)) * v2.a + 3 * (t * t) * (1 - t) * v3.a + (t * t * t) * v4.a;
		y = ((1 - t) * (1 - t) * (1 - t)) * v1.b + 3 * t * ((1 - t) * (1 - t)) * v2.b + 3 * (t * t) * (1 - t) * v3.b + (t * t * t) * v4.b;
		SDL_RenderDrawPoint(gRenderer, x, y);
	}
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x97, 0xB4, 0xFF);

}
