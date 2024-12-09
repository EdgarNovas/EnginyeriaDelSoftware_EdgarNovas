#pragma once
#include "ImageObject.h"
#include "RenderManager.h"

class TestObject : public ImageObject
{
public:
	TestObject()
		: ImageObject("resources/cat.jpg", Vector2(0.f, 0.f), Vector2(1200.f, 675.f)) 
	{
		Vector2 randomPos = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);

		transform->position = randomPos;
		transform->scale = Vector2(0.2f, 0.2f);
		transform->rotation = 30.0f;
		Vector2 randomForce = Vector2(-5000 + rand() % 10001, -5000 + rand() % 10001);
		physics->AddForce(randomForce);
	}


	TestObject(Vector2 pos, Vector2 startVelocity)
		: ImageObject("resources/cat.jpg", Vector2(0.f, 0.f), Vector2(1200.f, 675.f))
	{
		transform->position = pos;
		//transform->scale = Vector2(0.2f, 0.2f);
		physics->AddTorque(4000.0f);
		transform->rotation = 30.0f;
		physics->AddForce(startVelocity);
	}

	void OnCollisionEnter(Object* other) override
	{
		if (TestObject* to = dynamic_cast<TestObject*>(other))
		{
			Destroy();
		}
		
	}
};