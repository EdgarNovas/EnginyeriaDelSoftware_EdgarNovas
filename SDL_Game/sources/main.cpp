#include "Game.h"
#include "InputManager.h"
#include "TimeManager.h"
#include<exception>
#include <iostream>

int main(int argc, char* args[])
{
	Game game;
	srand(time(NULL));
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
	bool playing = true;
	while (playing)
	{
		TIME.Update();
		if (TIME.ShouldUpdateGame())
		{
			std::cout << TIME.GetDeltaTime() << std::endl;
			playing = !Input.Listen();
			game.Update();
			game.Render();
			TIME.ResetDeltaTime();
		}
		
	}

	game.Release();
	return 0;
}