#pragma once
#include "Scene.h"

class MainMenu : public Scene
{
public:
	MainMenu() = default;
	// Inherited via Scene
	void OnEnter() override;
	void OnExit() override;
	void Update() override;
	void Renderer() override;
};