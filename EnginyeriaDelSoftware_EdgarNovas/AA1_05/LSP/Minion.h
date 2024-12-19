#pragma once
#include "Enemy.h"
namespace LSP {
	class Minion : public LSP_Enemy
	{
		
	public:
		Minion() {
			health = 50;
		}

		// Heredado vía LSP_Enemy
		int GetHealth() override;
	};
}