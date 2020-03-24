#include "MouseInput.h"
SDL_Point LButton::getPosition(int x, int y)
{

	mPosition.x = x;
	mPosition.y = y;

	return mPosition;

}

void LButton::setPosition(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
}

bool LButton::handleEvent(SDL_Event* e)
{
	//If mouse event happened
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if (x < mPosition.x)
		{
			inside = false;
		}
		//Mouse is right of the button
		else if (x > mPosition.x + BUTTON_WIDTH)
		{
			inside = false;
		}
		//Mouse above the button
		else if (y < mPosition.y)
		{
			inside = false;
		}
		//Mouse below the button
		else if (y > mPosition.y + BUTTON_HEIGHT)
		{
			inside = false;
		}

		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch (e->type)
			{
			case SDL_MOUSEMOTION:
				break;

			case SDL_MOUSEBUTTONDOWN:
				if (mPosition.y == 0) {
					std::cout << "Se dio click en linea";
					line = true;
					curve = false;
					circle = false;
					poly = false;
					xx = false;
					square = false;
					return line;
				}
				if (mPosition.y == 60) {
					std::cout << "Se dio click en curva ";
					curve = true;
					line = false;
					circle = false;
					poly = false;
					xx = false;
					square = false;
					return curve;

				}
				if (mPosition.y == 120) {
					std::cout << "Se dio click en el circulo ";
					curve = false;
					line = false;
					circle = true;
					poly = false;
					xx = false;
					square = false;
					return circle;
				}
				if (mPosition.y == 180) {
					std::cout << "Se dio click en el poligono ";
					curve = false;
					line = false;
					circle = false;
					poly = true;
					xx = false;
					square = false;
					return poly;
				}
				if (mPosition.y == 240) {
					std::cout << "Se dio click en el cuadrado ";
					curve = false;
					line = false;
					circle = false;
					poly = false;
					xx = false;
					square = true;
					return square;
				}
				if (mPosition.y == 300) {
					std::cout << "Se dio click en la X ";
					curve = false;
					line = false;
					circle = false;
					poly = false;
					xx = true;
					square = false;
					return xx;
				}
				break;

				return false;

			case SDL_MOUSEBUTTONUP:
				break;
			}
		}
	}
}