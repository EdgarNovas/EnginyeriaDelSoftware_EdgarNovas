#pragma once
#include <vector>
#include "Vector2.h"
#include "AABB.h"
#include "Transform.h"
class Rigidbody
{
private:
	std::vector<AABB*> colliders;
	Transform* transform;

	Vector2 velocity;
	float angularVelocity;

	Vector2 acceleration;
	float angularAcceleration;

	float linearDrag;
	float angularDrag;

public:

	Rigidbody(Transform* _transform)
		:transform(_transform),
		velocity(Vector2()), angularVelocity(0.0f),
		acceleration(Vector2()), angularAcceleration(0.0f),
		linearDrag(0.0f), angularDrag(0.0f){}

	inline void AddCollider(AABB* collider) { colliders.push_back(collider); }
	bool CheckCollision(const Rigidbody* other) {
		for (AABB* myCol : colliders)
		{
			for (AABB* otherCol : other->colliders)
			{
				if (myCol->CheckOverLappingAABB(otherCol))
					return true;
			}
		}
		return false;
	}
	bool CheckOverlappingPoint(Vector2 point)
	{
		for (AABB* myCol : colliders)
		{
			if(myCol->CheckOverLappingPoint(point))
				return true;
		}
			

		return false;
	}
	void Update(float dt)
	{
		//1-> Update de la velocity
		velocity = velocity + acceleration * dt;
		angularVelocity = angularVelocity + angularAcceleration * dt;
		//2 -> Update the DRAG
		velocity = velocity * (1.0f / (1.0f + dt * linearDrag));
		angularVelocity = angularVelocity * (1.0f / (1.0f + dt * angularDrag));
		//3-> Update position
		transform->position = transform->position + velocity * dt;
		transform->rotation = transform->rotation + angularVelocity * dt;

		//4 -> Reset Acceleration
		acceleration = Vector2();
		angularAcceleration = 0.0f;

		//5 -> Update Colliders Position
		for (AABB* col : colliders) {
			col->SetTopLeft(transform->position);
		}

	}
	inline void AddForce(Vector2 force) { acceleration = acceleration + force; }
	inline void AddTorque(float amount) { angularAcceleration += amount; }
	inline Vector2 const GetVelocity() { return velocity; }
	inline void SetVelocity(Vector2 velocity) { this->velocity = velocity; }
	inline void SetLinearDrag(float linearDrag) { this->linearDrag = linearDrag; }
	inline void SetAngularDrag(float angularDrag) { this->angularDrag = angularDrag;}

};

