#pragma once
#include "LoadBinaryConfigurationService.h"
#include "LoadXMLConfigurationService.h"
namespace DIP
{
	class DIPMain
	{
	public:
		void Main();
		void LoadConfiguration(IConfigurationService* configurationService);
	};
}