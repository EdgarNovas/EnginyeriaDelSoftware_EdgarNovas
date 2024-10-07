#pragma once
#include "Scene.h"
class Gameplay : public Scene {

	// Inherited via Scene
	
	void Update() override;
	void Render() override;
	void Finish() override;
};
