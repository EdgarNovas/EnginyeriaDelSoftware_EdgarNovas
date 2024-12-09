#pragma once
#include "Object.h"
#include "ImageRenderer.h"

class ImageObject : public Object
{
public:
	ImageObject(std::string texturePath, Vector2 sourceOffset, Vector2 sourceSize)
		: Object() {
		physics->AddCollider(new AABB(sourceOffset, sourceSize * 0.2f));//Arreglar esto
		//El 0.2 es de la escala y hay que arreglarlo ya que cada objeto tiene su escala
		//Y la escala puede multiplicar por diferentes numeros X e Y
		renderer = new ImageRenderer(transform, texturePath, sourceOffset, sourceSize);

	}
};