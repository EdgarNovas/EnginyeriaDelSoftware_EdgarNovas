#include "Gameplay.h"
#include <iostream>
#include <ctime>


void Gameplay::Update()
{
	int c = 0;
	srand(time(NULL));
	std::cout << "You roll a dice" << std::endl;
	//scanf_s(" %c", &c);
	c = rand() % 6 + 1;


	if (c <= 4) {
		nextScene = "GameOver";
		finished = true;
	}
	else
	{
		nextScene = "MainMenu";
		finished = true;
	}

		
}

void Gameplay::Render()
{
	std::cout << " Enter t to go to Game Over";
}

void Gameplay::Finish()
{
}
