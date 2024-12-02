#include "Gameplay.h"
#include "TimeManager.h"
#include "Spawner.h"
#include "TestObject.h"
void Gameplay::OnEnter()
{
	for (int i = 0; i < 50; i++)
		SpawnObjectRandomly();

	
}

void Gameplay::SpawnObjectRandomly()
{
	

	SPAWN.SpawnObject(new TestObject());
}

void Gameplay::Update()
{
	Scene::Update();
}

void Gameplay::OnExit()
{
	Scene::OnExit();
}

void Gameplay::Renderer()
{
	Scene::Renderer();
}
