#pragma once
#include "MovementController.h"
#include "HealthController.h"
#include "AttackComponent.h"
#include <vector>
class Character {

public:
	MovementController movement;
	AttackComponent attack;
	HealthController health;

	Character();
	virtual void Update(float dt, std::vector<Character*> enemies)
	{
		Character* closestCharacter = GetClosestCharacter(enemies);
		if (closestCharacter == nullptr) return;

		Vector2 distance = movement.GetPosition();
		float floatDistance = distance.CalculateDistance(closestCharacter->movement.GetPosition());

		if (floatDistance < attack.GetRange())
		{
			attack.Attack(&closestCharacter->health);
		}
		else
		{
			movement.Move(0.04f);
		}
	}
	Character* GetClosestCharacter(std::vector<Character*> characters);
	
};