#include "RendererManager.h"
#include "Image.h"
#include "Animation2D.h"
#include "Model3D.h"

void Exercici1I2() {
	RendererManager manager;

	manager.AddRenderer(new Image);

	manager.AddRenderer(new Animation2D);

	manager.AddRenderer(new Model3D);

	manager.Draw();
}

int main() {

	Exercici1I2();
	

	return 0;
}