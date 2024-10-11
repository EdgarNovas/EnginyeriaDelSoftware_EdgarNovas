#pragma once


#include "Renderer.h"
class Animation2D: public Renderer {
private:
	float x = 7.9f;
	float y = 2.4f;
public:
	void Renderer::Draw() override {

		std::cout << "I drew the Animation2D at " << x << " " << y << std::endl;
	}

};