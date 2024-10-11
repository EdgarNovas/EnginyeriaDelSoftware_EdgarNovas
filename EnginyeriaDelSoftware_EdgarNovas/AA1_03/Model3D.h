#pragma once
#include "Renderer.h"

class Model3D : public Renderer
{
	// Heredado vía Renderer
	void Draw() override;
};