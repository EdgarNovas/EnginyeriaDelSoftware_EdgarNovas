#include "RendererManager.h"
#include "Image.h"
#include "Animation2D.h"
#include "Model3D.h"
#include "MenuManager.h"

void Exercici1I2() {
	RendererManager manager;

	manager.AddRenderer(new Image);

	manager.AddRenderer(new Animation2D);

	manager.AddRenderer(new Model3D);

	manager.Draw();
}

void Exercici3() {
	MenuManager menuManager;
	menuManager.AddMenu(new MainMenu);
	menuManager.AddMenu(new PauseMenu);
	menuManager.AddMenu(new LeaderBoardMenu);
	int numMenu = 0;
	do
	{
		std::cout << "Pick your Menu" << std::endl;
		std::cout << "0 = Main Menu" << std::endl;
		std::cout << "1 = Pause Menu" << std::endl;
		std::cout << "2 = LeaderBoard Menu" << std::endl;

		std::cin >> numMenu;
		numMenu = menuManager.ChangeCurrentMenu(numMenu);
		menuManager.Draw();

	} while (numMenu >= 0);
}

int main() {

	//Exercici1I2();
	
	Exercici3();

	

	return 0;
}