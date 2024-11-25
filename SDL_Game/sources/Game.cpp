#include "Game.h"
#include "RenderManager.h"
#include "TimeManager.h"

void Game::Init()
{
	RM->Init();

	_objects.push_back(Object("resources/cat.jpg",Vector2(0.f,0.f),Vector2(1200.f,675.f)));

	_objects[0].GetRigidBody()->AddForce(Vector2(100, 100));
}

void Game::Update()
{
	for (Object o : _objects)
		o.Update(TIME.GetDeltaTime());
	
}

void Game::Render()
{
	RM->ClearScreen();
	//Render elements
	for (Object o : _objects)
		o.Render();

	RM->RenderScreen();
}

void Game::Release()
{
	RM->Release();
}
