#pragma once
#include "Scene.h"

#include <unordered_map>
#include <string>




class GameEngine {
private:
	std::unordered_map<std::string, Scene*> scenes;
	
	Scene* currentScene;
public:
	void Start();
	void Update();
	void Finish();

};
