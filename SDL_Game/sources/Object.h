#pragma once
#include "Transform.h"
#include "Rigidbody.h"
#include "ImageRenderer.h"
#include "TimeManager.h"

class Object
{
protected:

	Transform* transform;
	Rigidbody* physics;
private:
	bool isPendingDestroy;

	ImageRenderer* renderer;
	
public:

	Object(std::string texturePath,Vector2 sourceOffset, Vector2 sourceSize)
	{
		transform = new Transform();
		physics = new Rigidbody(transform);
		renderer = new ImageRenderer(transform,texturePath,sourceOffset,sourceSize);

		isPendingDestroy = false;
	}

	virtual void Update() {
		if(physics != nullptr)
			physics->Update(TIME.GetDeltaTime());

		renderer->Update(TIME.GetDeltaTime());
	}
	virtual void Render()
	{
		renderer->Render();
	}
	Transform* GetTransform() { return transform; }
	Rigidbody* GetRigidBody() { return physics; }
	//void SetTransform(Transform t) { transform = t; }

	//De moment NO FAN RES
	bool IsPendingDestroy(){}
	virtual void Destroy(){}
	virtual void OnCollisionEnter(Object* other){}
};