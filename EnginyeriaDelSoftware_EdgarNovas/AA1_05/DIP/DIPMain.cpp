#include "DIPMain.h"
#include "DIP_Configuration.h"
#include "LoadXMLConfigurationService.h"

#include <cstdio>
namespace DIP
{
	//Incumple solid porque esta basado en concreciones en que loadXML 
	// y no es un load a secas y ya buscaremos lo que queda
	void DIPMain::Main()
	{
		LoadConfiguration();
	}

	void DIPMain::LoadConfiguration()
	{
		auto loadConfigurationService = LoadXMLConfigurationService();
		loadConfigurationService.LoadConfiguration();
		
	}
}