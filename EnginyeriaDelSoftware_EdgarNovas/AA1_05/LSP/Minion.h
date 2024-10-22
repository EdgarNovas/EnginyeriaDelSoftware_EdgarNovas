#pragma once
#include "Enemy.h"
namespace LSP {
	class Minion : public LSP_Enemy
	{
		int health = 50;
	public:
		Minion();

		// Heredado vía LSP_Enemy
		int GetHealth() override;
	};
}