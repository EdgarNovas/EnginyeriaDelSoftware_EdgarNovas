#pragma once
#include "Enemy.h"
namespace LSP {
	class Boss : public LSP_Enemy
	{
	private:
		health = 700;
	public:
		Boss();

		// Heredado vía LSP_Enemy
		int GetHealth() override;
	};
}