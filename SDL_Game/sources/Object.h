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
	bool isPendingDestroy = false;

	ImageRenderer* renderer;
	
public:


	Object(std::string texturePath,Vector2 sourceOffset, Vector2 sourceSize)
	{
		transform = new Transform();
		physics = new Rigidbody(transform);
		physics->AddCollider(new AABB(sourceOffset, sourceSize * 0.2f));//Arreglar esto
		//El 0.2 es de la escala y hay que arreglarlo ya que cada objeto tiene su escala
		//Y la escala puede multiplicar por diferentes numeros X e Y

		renderer = new ImageRenderer(transform,texturePath,sourceOffset,sourceSize);

		isPendingDestroy = false;
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