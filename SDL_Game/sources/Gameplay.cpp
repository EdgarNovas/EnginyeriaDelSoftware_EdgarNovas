#include "Gameplay.h"
#include "TimeManager.h"
#include "Spawner.h"
#include "TestObject.h"
#include "TextObject.h"
void Gameplay::OnEnter()
{
	for (int i = 0; i < 50; i++)
	{
		//SpawnObjectRandomly();
	}
	
	SPAWN.SpawnObject(new TestObject(Vector2(100, 100), Vector2(2000, 0)));
	SPAWN.SpawnObject(new TestObject(Vector2(300, 100), Vector2(-2000, 0)));

	//Text amb hola a la pos (100,100)
	Object* textObject = new TextObject("Hola");
	textObject->GetTransform()->position = Vector2(100, 100);
	SPAWN.SpawnObject(textObject);

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
