#pragma once
#include <vector>
#include "Enemy.h"
namespace OCP
{
	class OCPMain
	{
	public:
		void Main();
	private:
		void PrintEnemiesHealth(const std::vector< Enemy*>& enemies);
	};
}