#pragma once
#include <SDL.h>
#include <queue>
#include <unordered_map>
#define IM InputManager::Instance()

enum KeyState {EMPTY, DOWN, UP, HOLD, RELEASED};

class InputManager 
{
private:
	int mouseX, mouseY;
	bool leftClick;

	//SDLK_SPACE Aixo es un Sint32
	
	std::unordered_map<Sint32, KeyState> keyReference;

	InputManager()
	{
		SDL_GetMouseState(&mouseX, &mouseY);
		leftClick = false;
	}

	InputManager(const InputManager& im) = delete;
	InputManager& operator= (const InputManager& val) = delete;

public:
	static InputManager& Instance() 
	{
		static InputManager instance;
		return instance;
	}

	bool Listen()
	{
		SDL_GetMouseState(&mouseX, &mouseY);

		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				return true;
			else if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON_LEFT)
					leftClick = true;
			}
			else if (event.type == SDL_MOUSEBUTTONUP)
			{
				if (event.button.button == SDL_BUTTON_LEFT)
					leftClick = false;
			}
		}
	}

	inline int GetMouseX() const { return mouseX; }
	inline int GetMouseY() const { return mouseY; }

	inline bool GetLeftClick() const { return leftClick; }

};