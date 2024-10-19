#pragma once
#include "Event.h"

class Controller
{

public:
	virtual void HandleEvent(const Event*) = 0;
	virtual const bool GetButtonDown(int actionid) = 0;
	virtual const bool GetButtonUp(int actionid) = 0;
};