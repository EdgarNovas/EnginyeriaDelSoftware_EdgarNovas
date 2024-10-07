#include "GameEngine.h"
#include "MainMenu.h"
#include "Gameplay.h"
#include "GameOver.h"

void GameEngine::Start()
{
	//TODO: Create Scenes
	scenes["MainMenu"] = new MainMenu;
	scenes["Gameplay"] = new Gameplay;
	scenes["GameOver"] = new GameOver;
	//Set Initial Scene
	currentScene = scenes["MainMenu"];
	currentScene->Start();
}

void GameEngine::Update()
{
	//TODO: Update Scenes and change them 
	do{
		currentScene->Render();
		currentScene->Update();
		//Change Scenes
		if (currentScene->IsFinished())
		{
			currentScene->Finish();
			//Determine the next scene
			if (currentScene->GetNextScene() == "")
				return;
			currentScene = scenes[currentScene->GetNextScene()];
			currentScene->Start();
		}
	} while (true);
}

void GameEngine::Finish()
{
	//TODO: Clear Scenes
}
