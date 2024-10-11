#pragma once

#include "Renderer.h"

class Image: public Renderer {
private:
	float x = 5.1f;
	float y = 12.5f;
public:
	void Renderer::Draw() override {
		
		std::cout << "I drew the image at " << x << " " << y << std::endl;
	}

};
