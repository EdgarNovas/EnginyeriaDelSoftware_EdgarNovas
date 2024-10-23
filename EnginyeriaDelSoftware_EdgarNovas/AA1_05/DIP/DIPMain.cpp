#include "DIPMain.h"

#include <cstdio>
namespace DIP
{
	//
	//Aquesto codi dependia de LoadXMLConfigurationService y no deuria
	// per arreglar aixo he fet una abstracció on ara els 2 loads poden usarse a la vegada
	// o escollir sense cambiar el codi amb un IConfigurationService
	//
	//
	void DIPMain::Main()
	{
		DIPMain mainApp;
		LoadXMLConfigurationService xmlService;
		mainApp.LoadConfiguration(&xmlService);

		// Load from Binary
		LoadBinaryConfigurationService binaryService;
		mainApp.LoadConfiguration(&binaryService);
	}
	void DIPMain::LoadConfiguration(IConfigurationService* configurationService)
	{
		configurationService->LoadConfiguration();
		
	}
}