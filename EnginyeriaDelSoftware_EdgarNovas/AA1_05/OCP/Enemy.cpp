#include "Enemy.h"

namespace OCP {
	Enemy::Enemy(bool isBoss) : _isBoss(isBoss)
	{
	}

	bool Enemy::IsBoss()
	{
		return _isBoss;
	}

}