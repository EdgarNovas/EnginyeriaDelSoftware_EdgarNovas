#pragma once
namespace OCP {
	class Enemy
	{
	public:
		Enemy(bool isBoss);
		bool IsBoss();

	private:
		bool _isBoss;
	};
}