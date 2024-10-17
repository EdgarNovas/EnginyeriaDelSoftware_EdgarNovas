#include "LSPMain.h"

#include <cstdio>

namespace LSP
{
	void LSPMain::Main()
	{
		auto enemy = Minion();
		auto boss = Boss();
		auto enemies = std::vector<LSP_Enemy*>{ &enemy, &boss };

		PrintEnemiesHealth(enemies);
	}

	void LSPMain::PrintEnemiesHealth(const std::vector<LSP_Enemy*>& enemies)
	{
		for (LSP_Enemy* enemy : enemies) {
			if (Boss* boss = dynamic_cast<Boss*>(enemy))
			{
				std::printf("Boss, tiene %d de vida\n", BossHealth(boss));
			} 
			else if (Minion* minion = dynamic_cast<Minion*>(enemy))
			{
				std::printf("Minion, tiene %d de vida\n", MinionHealth(minion));
			}
		}
	}

	int LSPMain::BossHealth(Boss* boss)
	{
		return 200;
	}

	int LSPMain::MinionHealth(Minion* minion)
	{
		return 100;
	}
}