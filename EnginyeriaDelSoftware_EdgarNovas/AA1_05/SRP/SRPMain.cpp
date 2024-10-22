#include "SRPMain.h"
#include "SRP_Configuration.h"
#include "EnemyHandler.h"


#include <cstdio>
namespace SRP
{
	void SRPMain::Main()
	{
		auto enemies = EnemyHandler();
		auto configuration = SRP_Configuration(enemies.GetNumberOfEnemies());
		
		std::printf("Número de enemigos %d\n", enemies.GetNumberOfEnemies());

		configuration.SaveOnDisk(configuration);
	}
}