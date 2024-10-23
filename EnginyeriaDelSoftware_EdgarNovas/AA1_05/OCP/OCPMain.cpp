#include "OCPMain.h"
//#include "Enemy.h"
#include "NormalEnemy.h"
#include "Boss.h"
#include <cstdio>

namespace OCP
{
	//Aqui tenim un problema on no es pot extendre el codi ja que hauriem de estar tocant el print health
	//Llavors he fet que Enemy sigui una clase abstracta i que el enemy i el boss apliquin les seves funcions
	//Llavors tots els enemics nomes son enemics y no fa falta buscar quin tipus es
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

			//OR
			std::printf("El enemigo, tiene %d de vida\n", enemy->GetHealth());


		}
	}
}