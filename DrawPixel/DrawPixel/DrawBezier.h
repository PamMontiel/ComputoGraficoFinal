#pragma once
#include "Vector2.h"
#include "SDL.h"
class DrawBezier
{
private:
	float x, y;

public:
	DrawBezier();
	DrawBezier(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4, SDL_Renderer* gRenderer);

};

