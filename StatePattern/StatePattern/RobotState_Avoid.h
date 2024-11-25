#pragma once
#include "RobotState.h"
#include <iostream>
class RobotState_Avoid : public RobotState
{
public:

	void Enter() override {
		std::cout << "Enter SEEK state " << std::endl;
	}
	StateType Update() override {
		char letra = 'a';
		std::cin >> letra;

		return StateType::PLACE;
	}
	void Exit() {
		std::cout << "Exit SEEK state " << std::endl;
	}
};