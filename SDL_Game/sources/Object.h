#pragma once
#include "Transform.h"
#include "Rigidbody.h"
#include "Renderer.h"
#include "TimeManager.h"

class Object
{
protected:

	Transform* transform;
	Rigidbody* physics;
	Renderer* renderer = nullptr;
private:
	bool isPendingDestroy = false;


	
public:


	Object()
	{
		transform = new Transform();
		physics = new Rigidbody(transform);
	}

	~Object() {
		delete transform;
		delete physics;
		delete renderer;
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
	inline bool IsPendingDestroy() const { return isPendingDestroy; }
	virtual void Destroy(){
		isPendingDestroy = true;
	}

	virtual void OnCollisionEnter(Object* other){}
};