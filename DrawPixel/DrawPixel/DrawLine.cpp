#include "DrawLine.h"
DrawLine::DrawLine() {

}

DrawLine::DrawLine(Vector2 v1,Vector2 v2, SDL_Renderer* gRenderer) {

	dx = v2.a - v1.a;
	dy = v2.b - v1.b ;
	x = v1.a;
	y = v1.b;

	if (dx >= 0)
	{
		signX = +1;
	}
	else
	{
		signX = -1;
	}
	if (dy >= 0)
	{
		signY = 1;
	}
	else
	{
		signY = -1;
	}

	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
	if (x == v2.a)
	{
		SDL_RenderDrawLine(gRenderer, x, y, v2.a, v2.b);
	}
	if (abs(dy) <= abs(dx))
	{
		p = 2 * dy * signY - dx * signX;
		for (int i = 0; i <= dx * signX; i++)
		{
			SDL_RenderDrawPoint(gRenderer, x, y);
			if (p < 0)
			{
				x = x + signX;
				y = y;
				p = p + 2 * dy * signY;
			}
			else
			{
				x = x + signX;
				y = y + signY;
				p = p + 2 * dy * signY - 2 * dx * signX;
			}
		}
	}
	else if (abs(dy) > abs(dx))
	{
		p = 2 * dx * signX - dy * signY;
		i = 0;
		for (i = 0; i <= dy * signY; i++)
		{
			SDL_RenderDrawPoint(gRenderer, x, y);

			if (p < 0)
			{
				x = x;
				y = y + signY;
				p = p + 2 * dx * signX;
			}
			else if (p >= 0)
			{
				x = x + signX;
				y = y + signY;
				p = p + 2 * dx * signX - 2 * dy * signY;
			}
		}
	}
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x97, 0xB4, 0xFF);
}