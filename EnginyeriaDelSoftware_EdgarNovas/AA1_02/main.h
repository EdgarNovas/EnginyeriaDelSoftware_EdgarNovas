#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#pragma once

struct GameObject {
	char type;
	int x;
	int y;

};




void SaveObjects(std::vector<GameObject> o, std::string fileName) {

	std::ofstream file(fileName);
	
	int size = o.size();
	file.write(reinterpret_cast<char*>(&size), sizeof(int));
	file.write(reinterpret_cast<char*>(o.data()), sizeof(o[0]) * size);
	file.close();



}


void RecoverObjects(std::vector<GameObject>& o, std::string fileName) {

	
	int readSize;
	std::ifstream file(fileName);
	file.read(reinterpret_cast<char*>(&readSize), sizeof(int));
	o.resize(readSize);
	file.read(reinterpret_cast<char*>(o.data()), sizeof(GameObject) * readSize);

	file.close();

	for (int i = 0; i < 10; i++)
	{
		std::cout << o[i].type << " ";
		std::cout << o[i].x << " ";
		std::cout << o[i].y << "\n";
	}

}



//Exercise2


struct Weapon
{
	char name[10];
	int power;
};


struct Enemy
{
	char id;
	int x;
	float y;
	std::vector<Weapon> weapons;
};




void SaveEnemies(std::list<Enemy> e, std::string fileName) {

	std::ofstream file(fileName, std::ios::out| std::ios::binary);

	int size = e.size();
	file.write(reinterpret_cast<char*>(&size), sizeof(int));

	for (Enemy& enemy : e)
	{
		file.write(reinterpret_cast<char*>(&enemy.id),sizeof(enemy.id));
		file.write(reinterpret_cast<char*>(&enemy.x),sizeof(enemy.x));
		file.write(reinterpret_cast<char*>(&enemy.y),sizeof(enemy.y));

		int weapons = enemy.weapons.size();

		file.write(reinterpret_cast<char*>(&weapons), sizeof(weapons));
		
		for (Weapon& weapon : enemy.weapons) {
			file.write(reinterpret_cast<char*>(weapon.name), sizeof(weapon.name));
			file.write(reinterpret_cast<char*>(&weapon.power), sizeof(weapon.power));

		}
	}

	file.close();
}

void RecoverEnemies(std::list<Enemy>& e, std::string fileName) {
	int readSize;

	std::ifstream file(fileName, std::ios::in | std::ios::binary);

	if (!file.is_open())
		return;

	file.read(reinterpret_cast<char*>(&readSize), sizeof(int));

	

	for (int i = 0; i < readSize; i++)
	{
		Enemy enemy;

		file.read(reinterpret_cast<char*>(&enemy.id), sizeof(enemy.id));
		file.read(reinterpret_cast<char*>(&enemy.x), sizeof(enemy.x));
		file.read(reinterpret_cast<char*>(&enemy.y), sizeof(enemy.y));

		int weapons;
		file.read(reinterpret_cast<char*>(&weapons), sizeof(weapons));
		for (int j = 0; j < weapons; j++)
		{
			Weapon weapon;
			file.read(reinterpret_cast<char*>(weapon.name), sizeof(weapon.name));
			file.read(reinterpret_cast<char*>(&weapon.power), sizeof(weapon.power));
			
			enemy.weapons.push_back(weapon);
		}

		e.push_back(enemy);
	}
	
	file.close();


	for (Enemy& enemy : e)
	{
		std::cout << enemy.id << " ";
		std::cout << enemy.x << " ";
		std::cout << enemy.y << " ";
		for (Weapon& weapon : enemy.weapons)
		{
			std::cout << weapon.name << " ";
			std::cout << weapon.power << '\n';
		}
			
	}


}

void GenerateRandomName(char (&name)[10]) {
	const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
	const size_t maxIndex = sizeof(charset) - 2;

	for (int i = 0; i < 9; ++i) {  
		name[i] = charset[rand() % maxIndex];
	}
	name[9] = '\0';
}