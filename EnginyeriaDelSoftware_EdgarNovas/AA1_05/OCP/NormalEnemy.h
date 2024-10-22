#pragma once
#include "Enemy.h"
namespace OCP
{
	class NormalEnemy : public Enemy
	{
		
	public:

		NormalEnemy(int attackDamage, int hp) : Enemy(attackDamage, hp){}

		int GetHealth() override
		{
			return hp;
		}
		
	};
}