#pragma once
#include"Vector2.h"
#include"SDL.h"
class DrawCircle
{
private:
	int p, x, y;

public:
	DrawCircle() {};
	DrawCircle(int radius, Vector2 v, SDL_Renderer* gRenderer);

};

