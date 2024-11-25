#pragma once

enum class StateType
{
	NONE = 0,
	SEEK = 1,
	AVOID = 2,
	PLACE = 3
};

class RobotState
{
public:
	virtual void Enter() = 0;
	virtual StateType Update() = 0;
	virtual void Exit() = 0;


};