#include "Gameplay.h"
#include "TimeManager.h"
#include "Spawner.h"
void Gameplay::OnEnter()
{
	Object* o = new Object("resources/cat.jpg", Vector2(0.f, 0.f), Vector2(1200.f, 675.f));
	o->GetRigidBody()->AddForce(Vector2(100, 100));
	SPAWN.SpawnObject(o);

	
}

void Gameplay::Update()
{
	//Destruction

	//Spawning
	while (SPAWN.GetSpawnedObjectsCount() > 0) {
		objects.push_back(SPAWN.GetSpawnedObject());
	}
	//Updating

	for (Object* o : objects)
		o->Update();
}

void Gameplay::OnExit()
{
}

void Gameplay::Renderer()
{
	for (Object* o : objects)
		o->Render();
}
