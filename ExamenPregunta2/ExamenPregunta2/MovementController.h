#pragma once
#include "Vector2.h"

class MovementController
{
private:
	Vector2 position;
	Vector2 target;
public:
	MovementController();
	void SetTarget(Vector2 target);
	void Move(float dt);
	inline Vector2 const GetPosition();
};