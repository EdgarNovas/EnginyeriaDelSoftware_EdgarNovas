#pragma once
#include "Object.h"
#include <vector>

class Scene
{
protected:
	std::vector<Object*> ui;
	std::vector<Object*>objects;

public:
	Scene() = default;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;
	virtual void Update() = 0;
	virtual void Renderer() = 0;
};