#include "OCPMain.h"
#include "Enemy.h"

#include <cstdio>

namespace OCP
{
	void OCPMain::Main()
	{
		auto enemy = Enemy(false);
		auto boss = Enemy(true);
		auto enemies = std::vector<Enemy>{ enemy, boss };

		PrintEnemiesHealth(enemies);
	}

	void OCPMain::PrintEnemiesHealth(const std::vector< Enemy>& enemies)
	{
		for (auto enemy : enemies) {
			if (enemy.IsBoss()) {
				std::printf("Es un jefe, tiene %d de vida\n", 200);
			}
			else if (!enemy.IsBoss()) {
				std::printf("No es un jefe, tiene %d de vida\n", 100);
			}

		}
	}
}