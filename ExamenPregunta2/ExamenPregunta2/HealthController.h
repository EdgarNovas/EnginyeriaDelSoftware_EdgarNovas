#pragma once
class HealthController
{
private:
	float health;
public:
	HealthController(float health);
	void ReceiveDamage(float amount);
	inline bool const IsDead();
};