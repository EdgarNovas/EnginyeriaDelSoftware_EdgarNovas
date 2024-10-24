#include "Game.h"

void Game::Init()
{
	//1) Init SDL
	InitSDL();
	//2)Create window and renderer
	CreateWindowAndRenderer();
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);//cambiar el 0x por 255 a ver que pasa
	_isRunning = true;
	//3) Set render draw color

	_gameObjects.push_back(GameObject("resources/cat.jpg", _renderer));
}

void Game::HandleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			_isRunning = false;
	}
}

void Game::Update()
{

}

void Game::Render()
{
	SDL_RenderClear(_renderer);

	//Render elements
	for (GameObject go : _gameObjects)
		go.Render(_renderer);
	SDL_RenderPresent(_renderer);
}

void Game::Release()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool Game::IsRunning() const
{
	return _isRunning;
}

void Game::InitSDL()
{
	int result = SDL_Init(SDL_INIT_VIDEO);
	bool isInitialized = result >= 0;

	if (!isInitialized)
		throw SDL_GetError();
}

void Game::CreateWindowAndRenderer()
{
	int result = SDL_CreateWindowAndRenderer(
	512,512,
		SDL_WINDOW_SHOWN,
		&_window,
		&_renderer
	);

	bool isInitialized = result >= 0;

	if (!isInitialized)
		throw SDL_GetError();
}
