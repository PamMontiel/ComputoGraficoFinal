#pragma once
#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include "DrawBezier.h"
#include "DrawCircle.h"
#include "DrawLine.h"
#include "DrawPoly.h"
#include "Image.h"

//The mouse button
class LButton
{
public:
	//Initializes internal variables
	LButton() {};

	SDL_Point getPosition(int x, int y);

	//Sets top left position
	void setPosition(int x, int y);

	//Handles mouse event
	bool handleEvent(SDL_Event* e);

private:
	//Top left position
	SDL_Point mPosition;

	bool line = false;
	bool curve = false;
	bool circle = false;
	bool poly = false;
	bool xx = false;
	bool square = false;

	const int BUTTON_WIDTH = 60;
	const int BUTTON_HEIGHT = 60;

};

