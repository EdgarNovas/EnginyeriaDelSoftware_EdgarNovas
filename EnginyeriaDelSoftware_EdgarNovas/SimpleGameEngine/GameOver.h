#pragma once
#include "Scene.h"

class GameOver : public Scene
{


public:
	
	// Inherited via Scene
	void Update() override;

	void Render() override;

	void Finish() override;

};
