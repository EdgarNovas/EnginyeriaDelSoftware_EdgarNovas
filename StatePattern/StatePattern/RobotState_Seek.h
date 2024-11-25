#pragma once
#include "RobotState.h"
#include <iostream>

class RobotState_Seek : public RobotState
{
public:
	// Inherited via RobotState
	void Enter() override {
		std::cout << "Enter SEEK state " << std::endl;
	}

	StateType Update() override {

		//Move towards obstacle
		/*if(found  obstacle)*/
		int num = rand()%11;
		std::cout << num << std::endl;
		if(num >= 5)
			return StateType::AVOID;

		return StateType::NONE;
	}
	void Exit() override
	{
		std::cout << "Exit SEEK state " << std::endl;
	}
};