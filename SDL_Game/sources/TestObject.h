#pragma once
#include "Object.h"
#include "RenderManager.h"

class TestObject : public Object
{
public:
	TestObject()
		: Object("resources/cat.jpg", Vector2(0.f, 0.f), Vector2(1200.f, 675.f)) 
	{
		Vector2 randomPos = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);

		transform->position = randomPos;
		transform->scale = Vector2(0.2f, 0.2f);

		Vector2 randomForce = Vector2(-5000 + rand() % 10001, -5000 + rand() % 10001);
		physics->AddForce(randomForce);
	}

	void OnCollisionEnter(Object* other) override
	{
		Destroy();
		other->Destroy();
	}
};