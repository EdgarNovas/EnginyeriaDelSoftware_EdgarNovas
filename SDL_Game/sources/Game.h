#pragma once
#include <SDL.h>
#include <vector>
#include "GameObject.h"

class Game
{
public:
	Game() = default;
	void Init();
	
	void Update();
	void Render();
	void Release();

	

private:
	void InitSDL();
	void CreateWindowAndRenderer();


	
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	std::vector<GameObject> _gameObjects;
};

//1) Test It Works
//2) Implement State Machine