#pragma once
#include "HealthController.h"
class AttackComponent
{
private:
	float attack;
	float range;
public:
	AttackComponent(float attack, float range);
	void Attack(HealthController* hc)
	{
		hc->ReceiveDamage(attack);
	}
	inline float const GetRange();

};