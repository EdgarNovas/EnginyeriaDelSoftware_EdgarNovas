#include <iostream>
#include "InputHandler.h"
#include "Keyboard.h"
#include "Joystick.h"
int main()
{
	InputHandler handler;

	Keyboard keyboard;

	Joystick joystick;


	handler.AddController(&keyboard);
	handler.AddController(&joystick);

	Event event1(1);
	Event event2(2);

	std::cout << "Event 1" << std::endl;

	handler.HandleEvent(&event1);

	std::cout << "Event 2" << std::endl;
	handler.HandleEvent(&event2);
}