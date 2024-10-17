#pragma once
namespace SRP
{
	class SRP_Configuration
	{
	public:
		SRP_Configuration(int numberOfEnemies);
		int GetNumberOfEnemies();

		void SaveOnDisk(const SRP_Configuration& configuration);

	private:
		int _numberOfEnemies;
	};
}