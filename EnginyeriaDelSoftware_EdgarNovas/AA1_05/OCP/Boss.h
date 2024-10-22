#pragma once
#include "Enemy.h"

namespace OCP
{
	class Boss : public Enemy
	{
	public:

		Boss(int attackDamage, int hp) : Enemy(attackDamage, hp) {}

		int GetHealth() override
		{
			return hp;
		}

	};


}
