#pragma once
#include "RobotState.h"
#include <map>
class Robot
{
private:
	RobotState* _currentState;
	std::map<StateType, RobotState*> _availableStates;
public:
	Robot(RobotState* currentState, std::map<StateType, RobotState*> availableStates)
	{
		_currentState = currentState;
		_availableStates = availableStates;
		
		_currentState->Enter();
	}

	void Update()
	{
		StateType nextState = _currentState->Update();
		if (nextState == StateType::NONE)
			return;
			
		if (_availableStates.find(nextState) != _availableStates.end())
		{
			_currentState->Exit();
			_currentState = _availableStates[nextState];
			_currentState->Enter();
		}
		else
		{
			abort();
		}
		
	}


	~Robot()
	{
		_currentState->Exit();

		for (std::map<StateType, RobotState*>::iterator it = _availableStates.begin();
			it != _availableStates.end(); it++)
		{
			delete it->second;
		}
	}

};