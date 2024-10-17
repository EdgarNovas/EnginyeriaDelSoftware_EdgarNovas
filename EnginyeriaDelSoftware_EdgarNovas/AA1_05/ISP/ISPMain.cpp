#include "ISPMain.h"

#include <cstdio>

namespace ISP
{
	void ISPMain::Main()
	{
		auto enemy = ISP_Minion();
		auto boss = ISP_Boss();

		AttackTurn(enemy, boss);
		AttackTurn(boss, enemy);
	}

	void ISPMain::AttackTurn(const ISP_Enemy& enemy1, ISP_Enemy& enemy2)
	{
		enemy1.Attack(&enemy2);
		// enemy2.ReceiveDamage(200000);
	}

	void ISPMain::ForceReceiveDamage(ISP_Enemy& enemy)
	{
		enemy.ReceiveDamage(200000);
	}
}