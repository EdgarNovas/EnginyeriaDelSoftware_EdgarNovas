#pragma once
namespace OCP {
	class Enemy
	{
	public:
		Enemy(int attackDamage, int hp);
		virtual ~Enemy() = default;
		virtual int GetHealth() = 0;

	protected:
		int attackDamage;
		int hp;
	};
}