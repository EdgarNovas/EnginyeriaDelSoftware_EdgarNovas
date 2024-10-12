#pragma once
#include "Menu.h"

class PauseMenu : public Menu {
private:

public:
	PauseMenu() {
		
	}


	void Draw() override {
		std::cout << "Titol de pause" << std::endl;
		std::cout << "Boto clicable per tornar al joc" << std::endl;
		std::cout << "Boto clicable per tornar al menu principal" << std::endl;
	}

};