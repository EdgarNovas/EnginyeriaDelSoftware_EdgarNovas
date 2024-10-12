#pragma once
#include "Menu.h"
class LeaderBoardMenu : public Menu
{
public:
	LeaderBoardMenu() {

	}

	void Draw() override {
		std::cout << "Titol de leaderboard" << std::endl;
		std::cout << "120" << std::endl;
		std::cout << "80" << std::endl;
		std::cout << "76" << std::endl;
		std::cout << "74" << std::endl;
		std::cout << "71" << std::endl;
		std::cout << "42" << std::endl;
		std::cout << "30" << std::endl;
		std::cout << "26" << std::endl;
		std::cout << "24" << std::endl;
		std::cout << "16" << std::endl;
		std::cout << "Boto clicable per tornar al menu principal" << std::endl;
	}

};
