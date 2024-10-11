#pragma once
#include<vector>
#include "Renderer.h"


class RendererManager 
{
private:
	std::vector<Renderer*> renderers;

public:
	void AddRenderer(Renderer* renderer)
	{
		renderers.push_back(renderer);
	}

	void Draw()
	{
		for (int i = 0; i < renderers.size(); i++)
		{
			renderers[i]->Draw();
		}
	}

	~RendererManager() {
		for (Renderer* renderer : renderers) {
			delete renderer;  
		}
	}
};