// DrawPixel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include "Vector2.h"
#include <vector>
#include <list>
#include "DrawBezier.h"
#include "DrawCircle.h"
#include "DrawLine.h"
#include "DrawPoly.h"
#include "Image.h"
#include "DrawPlain.h"
#include "MouseInput.h"
using namespace std;

//Screen dimension constants
int SCREEN_WIDTH = 720;
int SCREEN_HEIGHT = 480;
int tam = 30;

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Button constants

const int TOTAL_BUTTONS = 4;

//Current displayed texture
SDL_Texture* gTexture = NULL;

Image* line_button = new Image();
Image* line_buttonDown = new Image();
Image* curva_button = new Image();
Image* circle_button = new Image();
Image* poly_button = new Image();
Image* square_button = new Image();
Image* x_button = new Image();

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);

				line_button->LoadImage("Sprites/line_button.png", gRenderer);
				line_buttonDown->LoadImage("Sprites/line_buttonDown.png", gRenderer);
				curva_button->LoadImage("Sprites/curva_button.png", gRenderer);
				circle_button->LoadImage("Sprites/circle_button.png", gRenderer);
				poly_button->LoadImage("Sprites/poly_button.png", gRenderer);
				square_button->LoadImage("Sprites/square_button.png", gRenderer);
				x_button->LoadImage("Sprites/x_button.png", gRenderer);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}

			}
		}
	}

	return success;
}

void RenderTexture(Image* image, int x, int y, double a)
{
	SDL_Rect srcrect;
	srcrect.x = x;
	srcrect.y = y;
	srcrect.w = image->GetWidth();
	srcrect.h = image->GetHeight();
	SDL_RenderCopyEx(gRenderer, image->GetTexture()
		, NULL, &srcrect, a, NULL, SDL_FLIP_NONE);
}

void RenderImage(Image* image, int x, int y, float angle)
{
	RenderTexture(image, x, y, angle);

}

void close()
{
	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

void SetScreen(){
	if (SCREEN_WIDTH == 0 || SCREEN_HEIGHT == 0){
		SCREEN_WIDTH = 720;
		SCREEN_HEIGHT = 480;
	}
	if (tam == 0){
		tam = 32;
	}
}

int main(int argc, char* args[]){
	SetScreen();

	LButton* lineButton = new LButton();
	LButton* curveButton = new LButton();
	LButton* circleButton = new LButton();
	LButton* polyButton = new LButton();
	LButton* squareButton  = new LButton();
	LButton* xButton = new LButton();

	lineButton->getPosition(0, 0);
	curveButton->getPosition(0, 60);
	circleButton->getPosition(0, 120);
	polyButton->getPosition(0, 180);
	squareButton->getPosition(0, 240);
	xButton->getPosition(0, 300);

	bool lineBool = false;
	bool curve = false;
	bool circle = false;
	bool poly = false;
	bool xx = false;
	bool square = false;
	bool drawing=false;

	int x1 = 150;
	int y1 = 250;
	int x2 = 300;
	int y2 = 250;

	int xMouse, yMouse;

	//Start up SDL and create window
	if (!init()){
		printf("Failed to initialize!\n");
	}
	else{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		//While application is running
		while (!quit){
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0){
				//User requests quit
				if (e.type == SDL_QUIT){
					quit = true;
				}

				if (lineButton->handleEvent(&e)==true) 
					lineBool = true;
				if (curveButton->handleEvent(&e) == true) 
					curve = true;
				if (circleButton->handleEvent(&e) == true)
					circle = true;
				if (polyButton->handleEvent(&e) == true)
					poly = true;
				if (squareButton->handleEvent(&e) == true)
					square = true;
				if (xButton->handleEvent(&e) == true)
					xx = true;
				
			}	

			std::vector<Vector2> b = std::vector<Vector2>(4);
			b[0] = Vector2(100, 100);
			b[1] = Vector2(100, 400);
			b[2] = Vector2(400, 400);
			b[3] = Vector2(400, 100);

			std::vector<Vector2> c = std::vector<Vector2>(5);
			c[0] = Vector2(250, 150);
			c[1] = Vector2(250, 200);			
			c[2] = Vector2(320, 250);			
			c[3] = Vector2(200, 230);			
			c[4] = Vector2(350, 150);			
			
			std::vector<Vector2> d = std::vector<Vector2>(2);
			d[0] = Vector2(200, 200);
			d[1] = Vector2(250, 250);


			//Clear Screen
			SDL_RenderClear(gRenderer);
			SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);

			//DrawCircle(150, Vector2(250, 250), gRenderer);
			if (lineBool) { DrawLine(Vector2(200, 200), Vector2(300, 500), gRenderer); }
			if (curve) { DrawBezier(Vector2(20, 20), Vector2(50, 200), Vector2(200, 200), Vector2(200, 50), gRenderer); }
			if (poly) { DrawPoly(c, gRenderer);}
			if (square) { DrawPoly(b, gRenderer); }
			if (circle) { DrawCircle(100, Vector2(300,300),gRenderer); }
			if (xx) {
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x50, 0xFF, 0xFF);
				SDL_RenderPresent(gRenderer);
				lineBool = false;
				curve = false;
				poly = false;
				square = false;
				circle = false;
				xx = false;
			}

			RenderImage(line_button, 0, 0, 0);
			RenderImage(curva_button, 0, 60, 0);
			RenderImage(circle_button, 0, 120, 0);
			RenderImage(poly_button, 0, 180, 0);
			RenderImage(square_button, 0, 240, 0);
			RenderImage(x_button, 0, 300, 0);

			DrawPlain(SCREEN_WIDTH, SCREEN_HEIGHT, gRenderer, tam);
			//Update screen
			SDL_RenderPresent(gRenderer);
		}

	}

	//Free resources and close SDL
	close();

	return 0;
}
