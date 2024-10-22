#pragma once
namespace SRP
{
	class SRP_Configuration
	{
	public:
		SRP_Configuration(int numberOfEnemies);
		

		void SaveOnDisk(const SRP_Configuration& configuration);

	private:
		int _numberOfEnemies;
	};
}