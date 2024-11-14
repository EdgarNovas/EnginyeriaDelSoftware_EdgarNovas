#include "Game.h"

void Game::Init()
{
	//1) Init SDL
	InitSDL();
	//2)Create window and renderer
	CreateWindowAndRenderer();
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);//cambiar el 0x por 255 a ver que pasa
	
	//3) Set render draw color

	_objects.push_back(Object("resources/cat.jpg", _renderer));
	
	_objects[0].GetRigidBody()->AddForce(Vector2(100, 100));
}



void Game::Update()
{
	for (Object o : _objects)
		o.Update(0.01f);
	
}

void Game::Render()
{
	SDL_RenderClear(_renderer);

	//Render elements
	for (Object o : _objects)
		o.Render(_renderer);
	SDL_RenderPresent(_renderer);
}

void Game::Release()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
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
