#pragma once
#include <SDL.h>
#include <vector>
#include "GameObject.h"

class Game
{
public:
	Game() = default;
	void Init();
	void HandleEvents();
	void Update();
	void Render();
	void Release();

	bool IsRunning() const;

private:
	void InitSDL();
	void CreateWindowAndRenderer();


	bool _isRunning;
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	std::vector<GameObject> _gameObjects;
};