#pragma once
class IConfigurationService
{
public:
    virtual void LoadConfiguration() = 0;
    virtual ~IConfigurationService() = default;
};
