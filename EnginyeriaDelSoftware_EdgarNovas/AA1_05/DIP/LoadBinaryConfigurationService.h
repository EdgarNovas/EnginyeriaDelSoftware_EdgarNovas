#pragma once
#include "IConfigurationService.h"
#include <iostream>
class LoadBinaryConfigurationService : public IConfigurationService
{
public:
    void LoadConfiguration() override;
};