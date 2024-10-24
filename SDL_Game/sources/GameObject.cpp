#include "GameObject.h"

#include <SDL_image.h>
#include <cassert>
GameObject::GameObject(std::string path, SDL_Renderer* renderer)
{
	SDL_Surface* surf = IMG_Load(path.c_str());

	assert(surf);
	texture = SDL_CreateTextureFromSurface(renderer, surf);
	assert(texture);

	position = Vector2();
	//Set dest rect
	destinationRect = { (int)position.x, (int)position.y,100,100 };
	//Set source rect
	sourceRect = { 0,0, surf->w, surf->h };

	SDL_FreeSurface(surf);
}

void GameObject::SetPosition(Vector2 pos)
{
	//Assign the position

	//Update the destination rect

}

void GameObject::Update()
{
	//Does nothing
}


void GameObject::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, &sourceRect, &destinationRect);
}
