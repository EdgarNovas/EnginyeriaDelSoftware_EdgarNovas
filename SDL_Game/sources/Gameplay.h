#pragma once

#include "Scene.h"

class Gameplay : public Scene
{
public:
	Gameplay() = default;
	// Inherited via Scene
	void OnEnter() override;
	void OnExit() override;
	void Update() override;
	void Renderer() override;
	void SpawnObjectRandomly();
};
