#pragma once
#include "Transform.h"
#include "Rigidbody.h"

//Temporal Includes
#include<SDL.h>
#include<string>
#include<SDL_image.h>
#include<cassert>
class Object
{
protected:

	Transform* transform;
	Rigidbody* physics;
private:
	bool isPendingDestroy;
	//Temporal variables to test
	//fix when testing is done
	SDL_Texture* texture;
	SDL_Rect sourceRect;
	SDL_Rect destinationRect;
public:

	//Object();
	Object(std::string path, SDL_Renderer* renderer)
	{
		transform = new Transform();
		physics = new Rigidbody(transform);
		SDL_Surface* surf = IMG_Load(path.c_str());

		assert(surf);
		texture = SDL_CreateTextureFromSurface(renderer, surf);
		assert(texture);

		
		//Set dest rect
		destinationRect = { (int)transform->position.x, (int)transform->position.y,100,100 };
		//Set source rect
		sourceRect = { 0,0, surf->w, surf->h };

		SDL_FreeSurface(surf);
	}




	virtual void Update(float dt) {
		if(physics != nullptr)
			physics->Update(dt);
	}
	virtual void Render(SDL_Renderer* renderer)
	{
		destinationRect.x = transform->position.x;
		destinationRect.y = transform->position.y;
		SDL_RenderCopy(renderer, texture, &sourceRect, &destinationRect);
	}
	Transform* GetTransform() { return transform; }
	Rigidbody* GetRigidBody() { return physics; }
	//void SetTransform(Transform t) { transform = t; }

	//De moment NO FAN RES
	bool IsPendingDestroy(){}
	virtual void Destroy(){}
	virtual void OnCollisionEnter(Object* other){}
};