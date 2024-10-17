#include "SRP_Configuration.h"
namespace SRP
{
	SRP_Configuration::SRP_Configuration(int numberOfEnemies) : _numberOfEnemies(numberOfEnemies)
	{
	}

	int SRP_Configuration::GetNumberOfEnemies()
	{
		return _numberOfEnemies;
	}

	void SRP_Configuration::SaveOnDisk(const SRP_Configuration& configuration)
	{
		// ...
	}
}