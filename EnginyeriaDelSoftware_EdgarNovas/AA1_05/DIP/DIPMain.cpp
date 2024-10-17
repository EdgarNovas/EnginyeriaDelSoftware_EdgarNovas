#include "DIPMain.h"
#include "DIP_Configuration.h"
#include "LoadXMLConfigurationService.h"

#include <cstdio>
namespace DIP
{
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