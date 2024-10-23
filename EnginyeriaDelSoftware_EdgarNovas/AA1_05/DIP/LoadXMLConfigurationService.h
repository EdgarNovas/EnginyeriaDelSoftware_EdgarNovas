#pragma once
#include "IConfigurationService.h"
#include <iostream>
namespace DIP
{
	class LoadXMLConfigurationService : public IConfigurationService
	{
	public:
		void LoadConfiguration() override;
	};
};
