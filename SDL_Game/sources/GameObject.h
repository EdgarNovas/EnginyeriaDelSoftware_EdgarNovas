#pragma once
#include "Vector2.h"
#include <SDL.h>
#include <string>
class GameObject
{
protected:
	Vector2 position;
	SDL_Texture* texture;
	SDL_Rect sourceRect;
	SDL_Rect destinationRect;

public:
	GameObject(std::string path, SDL_Renderer* renderer);
	void SetPosition(Vector2 pos);
	inline Vector2 GetPosition() const { return position; }
	void Update();
	void Render(SDL_Renderer* renderer);



};