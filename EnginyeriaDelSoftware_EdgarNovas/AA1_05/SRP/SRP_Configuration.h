#pragma once
namespace SRP
{
	//Aquesta clase s'incomplia perique la configuracio feia moltes coses a la vegada en comptes de una sola
	//El que he fet es ficar un enemy handler y ell s'encarrega de la altre part
	class SRP_Configuration
	{
	public:
		SRP_Configuration(int numberOfEnemies);
		

		void SaveOnDisk(const SRP_Configuration& configuration);

	private:
		int _numberOfEnemies;
	};
}