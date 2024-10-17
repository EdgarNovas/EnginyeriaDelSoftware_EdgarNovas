#pragma once
#include <vector>
#include "Enemy.h"
#include "Boss.h"
#include "Minion.h"

namespace LSP
{
	class LSPMain
	{
	public:
		void Main();
	private:
		void PrintEnemiesHealth(const std::vector<LSP_Enemy*>& enemies);
		int BossHealth(Boss* boss);
		int MinionHealth(Minion* boss);
	};
}