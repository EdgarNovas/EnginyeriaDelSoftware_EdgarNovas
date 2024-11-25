#pragma once
#include "RobotState.h"
#include <iostream>
#include <thread>
class RobotState_Place : public RobotState
{
public:

	void Enter() override {
		std::cout << "Enter SEEK state " << std::endl;
	}
	StateType Update() override {
		std::cout << "I am placing" << std::endl;
		_sleep(1000);
		return StateType::SEEK;
	}
	void Exit()override
	{
		std::cout << "Exit SEEK state " << std::endl;
	}
};