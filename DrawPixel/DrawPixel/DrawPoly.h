#pragma once
#include "Vector2.h"
#include "DrawLine.h"
#include "SDL.h"
#include <vector>


class DrawPoly
{

public:
	DrawPoly();
	void DrawVector(Vector2 v1, Vector2 v2, SDL_Renderer* gRenderer);
	DrawPoly(const std::vector<Vector2>& vertex, SDL_Renderer* gRenderer);

};

