#pragma once
#include "Menu.h"
#include "PauseMenu.h"
#include "MainMenu.h"
#include "LeaderBoardMenu.h"
class MenuManager
{
private:
	std::vector<Menu*> menus;
	Menu* currentMenu = nullptr;
public:
	void Draw() {
		if (currentMenu == nullptr)
			return;

		currentMenu->Draw();
	}

	void AddMenu(Menu* menu)
	{
		menus.push_back(menu);
		if (currentMenu == nullptr)
		{
			currentMenu = menu;
		}
	}

	int ChangeCurrentMenu(int num)
	{
		if ((num < 0) || (num >= menus.size()))
		{
			
			std::cout << menus.size();
			return -1;
		}

		currentMenu = menus[num];

		return num;
	}

	//Sigo pensando que es medio necesario

	~MenuManager() {
		for (Menu* menu : menus) {
			delete menu;
		}
	}

};