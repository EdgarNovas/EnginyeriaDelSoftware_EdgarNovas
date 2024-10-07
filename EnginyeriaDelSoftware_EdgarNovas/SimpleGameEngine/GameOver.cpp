#include "GameOver.h"
#include <iostream>

void GameOver::Update()
{
	nextScene = "MainMenu";
	finished = true;
}

void GameOver::Render()
{
	std::cout << " YOU LOSE THE GAME" << std::endl;
	std::cout << " Radev Laughs: aahahahhaah" << std::endl;
}

void GameOver::Finish()
{
}
