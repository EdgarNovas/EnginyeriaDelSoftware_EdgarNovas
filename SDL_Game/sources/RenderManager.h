#pragma once
#include "SDL.h"
#include <map>
#include <string>
#include <cassert>
#include "SDL.h"
#include "SDL_ttf.h"

#define RM RenderManager::GetInstance()

class RenderManager
{
public:
	static RenderManager* GetInstance()
	{
		static RenderManager instance;

		return &instance;
	}

	const unsigned int WINDOW_WIDTH = 1360;
	const unsigned int WINDOW_HEIGHT = 768;

	void Init();
	void Release();
	void ClearScreen();
	void RenderScreen();

	SDL_Renderer* GetRenderer() { return renderer; }
	
	void LoadTexture(std::string path);

	SDL_Texture* GetTexture(std::string path);

	void LoadFont(std::string path);

	TTF_Font* GetFont(std::string path);
private:
	RenderManager() = default;
	RenderManager(RenderManager&) = delete;
	RenderManager& operator= (const RenderManager&) = delete;
	~RenderManager();

	

	SDL_Window* window;
	SDL_Renderer* renderer;

	std::map<std::string, SDL_Texture*> textures;
	std::map<std::string, TTF_Font*> fonts;

	void InitSDL();
	void CreateWindowAndRenderer();

};