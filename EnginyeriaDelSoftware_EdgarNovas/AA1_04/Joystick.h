#pragma once
#include "Controller.h"
class Joystick : public Controller
{
public:
	void HandleEvent(const Event* event) {
		std::cout << "Keyboard handling event with key: " << event->key << std::endl;

	}
	const bool GetButtonDown(int actionid)
	{
		return false;
	}
	const bool GetButtonUp(int actionid) {
		return false;
	}
};