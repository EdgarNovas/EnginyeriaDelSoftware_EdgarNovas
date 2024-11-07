#pragma once
#include "Character.h"
#include <vector>
class Tomahawky : public Character
{
public:
	Tomahawky();
	void Update(float dt,std::vector<Character*> enemies) override;
};