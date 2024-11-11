#include "Game.h"
#include "InputManager.h"
#include<exception>
#include <iostream>

int main(int argc, char* args[])
{
	Game game;
	
	try
	{
		game.Init();


	}
	catch ( std::exception& exception)
	{
		std::cout << "Error " << exception.what();
		game.Release();
		return -1;
	}
	
	while (!Input.Listen())
	{
		
		game.Update();
		game.Render();
		if (Input.GetEvent(SDLK_SPACE, DOWN))
		{
			printf("Tecla ESPACIO presionada (DOWN)\n");
		}
		else if (Input.GetEvent(SDLK_w, DOWN))
		{
			printf("Working w \n");
		}
	}

	game.Release();
	return 0;
}