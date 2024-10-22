#pragma once

class EnemyHandler {

	int numberOfEnemies;
public:
	int GetNumberOfEnemies()
	{
		return numberOfEnemies;
	}
		
	void AddEnemy()
	{
		numberOfEnemies++;
	}

	void RemoveEnemy()
	{
		numberOfEnemies--;
	}
	

};