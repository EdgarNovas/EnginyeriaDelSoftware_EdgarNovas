#pragma once
#include "SDL.h"
#include <map>
#include <string>
#include <cassert>

#define Render RenderManager::GetInstance()

class RenderManager
{
public:
	static RenderManager* GetInstance()
	{
		if(instance == nullptr)
			instance = new RenderManager();

		return instance;
	}

	void Init();
	void ClearScreen();
	void RenderScreen();

	SDL_Renderer* GetRenderer() { return renderer; }

private:
	RenderManager() = default;
	RenderManager(RenderManager&) = delete;
	RenderManager& operator= (const RenderManager&) = delete;
	~RenderManager();

	static RenderManager* instance;

	SDL_Window* window;
	SDL_Renderer* renderer;

	void InitSDL();
	void CreateWindowAndRenderer();

};