#pragma once
#include "Character.h"

class CharacterFactory
{
public:
	CharacterFactory();
	Character* CreateCharacter(int id);
};