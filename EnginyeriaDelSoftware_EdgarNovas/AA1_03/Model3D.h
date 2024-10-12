#pragma once
#include "Renderer.h"

class Model3D : public Renderer
{
public:
	// Heredado vía Renderer
	void Draw() override;
};