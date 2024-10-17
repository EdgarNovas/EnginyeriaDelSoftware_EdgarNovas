#include "SRPMain.h"
#include "SRP_Configuration.h"

#include <cstdio>
namespace SRP
{
	void SRPMain::Main()
	{
		auto configuration = SRP_Configuration(2);
		std::printf("Número de enemigos %d\n", configuration.GetNumberOfEnemies());

		configuration.SaveOnDisk(configuration);
	}
}