#pragma once
#include <SDL.h>
#include "Scene.h"

class Game
{
public:
	Game() = default;
	void Init();
	void Update();
	void Render();
	void Release();

	

};



//1) Test It Works
//2) Implement State Machine