#pragma once
#include "Vector2.h"
#include "SDL.h"
#include <math.h>
#include <cmath>
class DrawLine
{
private:
	float x, y;
	float dy, dx;
	float p, i;
	int signX, signY;
public:

	DrawLine();
	DrawLine(Vector2 v1,Vector2 v2, SDL_Renderer* gRenderer);
};

