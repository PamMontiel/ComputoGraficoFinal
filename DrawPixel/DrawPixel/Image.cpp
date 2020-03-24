#include "Image.h"
void Image::LoadImage(std::string name, SDL_Renderer* gRenderer)
{
	this->name = name;
	SDL_Surface* loadedSurface = IMG_Load(name.c_str());
	w = loadedSurface->w;
	h = loadedSurface->h;

	image = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
}

SDL_Texture* Image::GetTexture() {
	return image;
}
int Image::GetWidth()
{
	return w;
}

int Image::GetHeight()
{
	return h;
}