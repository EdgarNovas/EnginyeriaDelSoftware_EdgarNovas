#pragma once
#include "Menu.h"
class MainMenu: public Menu {
private:

public:
	MainMenu() {

	}


	void Draw() override {
		std::cout << "Imatge joc" << std::endl;
		std::cout << "Boto clicable per començar el joc" << std::endl;
		std::cout << "Boto clicable per mostrar les millors puntuacions" << std::endl;
		std::cout << "Boto clicable per tancar el joc" << std::endl;
	}

};