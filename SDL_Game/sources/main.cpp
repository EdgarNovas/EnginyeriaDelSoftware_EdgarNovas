#include "Game.h"
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

	while (game.IsRunning())
	{
		game.HandleEvents();
		game.Update();
		game.Render();
	}

	game.Release();
	return 0;
}