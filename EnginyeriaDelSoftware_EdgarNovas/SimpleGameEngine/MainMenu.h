#pragma once

#include "Scene.h"
#include <iostream>
#include <cstdio>

class MainMenu : public Scene
{
	// Inherited via Scene
	
	void Update() override {
		char c;
		scanf_s(" %c", &c);
		if (c == '1')
		{
			nextScene = "Gameplay";
			finished = true;
			
		}
		else if (c == '2') {
			//CLOSE
			finished = true;
		}
	}
	void Render() override
	{
		std::cout << "This is the main menu" << std::endl;
		std::cout << " -> Enter 1 to play" << std::endl;
		std::cout << " -> Enter 2 to exit" << std::endl;
		std::cout << " ->";
	}
	void Finish() override {

	}
};