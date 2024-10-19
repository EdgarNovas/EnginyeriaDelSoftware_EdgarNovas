#pragma once
#include <vector>
#include "Controller.h"
class InputHandler {
private:
	std::vector<Controller*> controllers;
public:

	void HandleEvent(const Event* event)
	{
		std::cout << "This is Event number " << event->key << std::endl;
	}

	void AddController(Controller* controller)
	{
		controllers.push_back(controller);
	}

};