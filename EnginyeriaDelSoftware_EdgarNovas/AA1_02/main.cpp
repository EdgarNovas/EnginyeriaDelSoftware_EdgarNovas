#include "main.h"

int main()
{
	// EXERCISE 1
	/*
	std::vector<GameObject> objects;

	for (int i = 0; i < 10; i++)
	{
		GameObject object;

		object.type = rand() % 20 + 97;
		object.x = rand() % 15 ;
		object.y = rand() % 15 ;

		objects.push_back(object);
	}

	//WRITE TO FILE
	std::ofstream filenameOut;
	filenameOut.open("GameObjects.edgar", std::ios::out | std::ios::binary);

	if (!filenameOut.is_open())
		return -1;

	SaveObjects(objects, "GameObjects.edgar");
	
	
	//READ FROM FILE
	std::vector<GameObject> readVector;
	std::ifstream filenameIn;
	filenameIn.open("GameObjects.edgar", std::ios::in | std::ios::binary);
	if (!filenameIn.is_open())
		return -2;

	RecoverObjects(readVector, "GameObjects.edgar");
	*/
	





	//EXERCISE 2
	/*
	std::list<Enemy> enemies;

	for (int i = 0; i < 10; i++) {
		Enemy enemy;
		enemy.id = rand() % 20 + 97;
		enemy.x = rand() % 15;
		enemy.y = (float)(15 + rand() % 9901) / 100.00f;
		
		int j = rand() % 3 + 1;
		for (int k = 0; k < j; k++) {
			Weapon weapon;
			GenerateRandomName(weapon.name);
			
			weapon.power = rand() % 20+1;

			enemy.weapons.push_back(weapon);
		}

		enemies.push_back(enemy);
		
	}

	//Create and write
	std::ofstream fileName;
	fileName.open("fileWeapons", std::ios::out | std::ios::binary);

	if (!fileName.is_open())
		return -1;

	SaveEnemies(enemies, "fileWeapons");
	fileName.close();

	//READ
	std::list<Enemy> recoverEnemies;
	std::ifstream fileNameIn;
	fileNameIn.open("fileWeapons", std::ios::in | std::ios::binary);

	if (!fileNameIn.is_open())
		return -2;

	RecoverEnemies(recoverEnemies, "fileWeapons");

	fileNameIn.close();

	*/






	//EXERCISE 3
	//WRITE
	std::map<std::string, int> myMap;
	
	std::string nameOfFile = "mapData.tucan";

	FillMapWithRandomData(myMap, 10);

	std::ofstream fileName;
	fileName.open(nameOfFile, std::ios::out | std::ios::binary);

	if (!fileName.is_open())
		return -1;

	SaveMap(myMap,nameOfFile);

	fileName.close();


	//READ

	std::map<std::string, int> myrecoverMap;

	std::ifstream fileNameIn;
	fileNameIn.open(nameOfFile, std::ios::in | std::ios::binary);

	if (!fileNameIn.is_open())
		return-2;

	RecoverMap(myrecoverMap, nameOfFile);

	fileNameIn.close();


	for (auto& pair : myrecoverMap) {

		std::cout << pair.first << " " << pair.second << "\n";

	}


	return 0;
}


