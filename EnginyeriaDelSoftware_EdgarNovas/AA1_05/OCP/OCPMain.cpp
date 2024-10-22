#include "OCPMain.h"
//#include "Enemy.h"
#include "NormalEnemy.h"
#include "Boss.h"
#include <cstdio>

namespace OCP
{
	void OCPMain::Main()
	{
		Enemy* enemy =new NormalEnemy(24,56);
		Enemy* boss = new Boss(24,54);
		std::vector<Enemy*> enemies{ enemy, boss };

		PrintEnemiesHealth(enemies);

		delete enemy;
		delete boss;
	}

	void OCPMain::PrintEnemiesHealth(const std::vector< Enemy*>& enemies)
	{
		for (const auto& enemy : enemies) {
			if (auto* boss = dynamic_cast<const Boss*>(enemy)) {
				std::printf("Es un jefe, tiene %d de vida\n", enemy->GetHealth());
			}
			else if (auto* normalEnemy = dynamic_cast<const NormalEnemy*>(enemy)) {
				std::printf("No es un jefe, tiene %d de vida\n", enemy->GetHealth());
			}

		}
	}
}