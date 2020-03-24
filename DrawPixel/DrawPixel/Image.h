#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>

class Image
{
private:
	SDL_Texture* image;
	std::string name;
	int w;
	int h;
public:
	void LoadImage(std::string name, SDL_Renderer* gRenderer);
	SDL_Texture* GetTexture();
	int GetWidth();
	int GetHeight();
};

