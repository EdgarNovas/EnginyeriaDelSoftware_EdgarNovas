#pragma once
#include "Renderer.h"
#include <vector>

class Menu
{
private:
	std::vector<Renderer*> renderers;
public:
	virtual void Draw() = 0;

};