#pragma once
#include "CharacterFactory.h"
#include <vector>
class CombatManager
{
private:

	std::vector<Character*> friendlyArmy;
	std::vector<Character*> enemyArmy;

	void SpawnFriendlyArmy(CharacterFactory* factory)
	{
		for (int i = 0; i < 5; i++)
		{
			friendlyArmy.push_back( factory->CreateCharacter(0));
			friendlyArmy.push_back( factory->CreateCharacter(1));
		}
		
	}
	void SpawnEnemyArmy(CharacterFactory* factory);
public:
	CombatManager();
	~CombatManager();
	void Update(float dt);

};