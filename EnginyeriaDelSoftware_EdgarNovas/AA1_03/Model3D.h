#pragma once
#include "Renderer.h"

class Model3D : public Renderer
{
public:
	// Heredado v�a Renderer
	void Draw() override;
};