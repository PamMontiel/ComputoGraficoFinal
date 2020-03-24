#include "DrawPoly.h"

DrawPoly::DrawPoly() {

}

void DrawPoly::DrawVector(Vector2 v1, Vector2 v2, SDL_Renderer* gRenderer) {
	DrawLine(v1, v2, gRenderer);
}

DrawPoly::DrawPoly(const std::vector<Vector2>& vertex, SDL_Renderer* gRenderer) {
	for (auto it = vertex.begin(); it != vertex.end(); it++)
	{
		if (it + 1 != vertex.end())
		{
			DrawVector(*it, *(it + 1), gRenderer);
		}
		else if (it + 1 == vertex.end())
		{
			DrawVector(*it, vertex.front(), gRenderer);
		}
	}
}
