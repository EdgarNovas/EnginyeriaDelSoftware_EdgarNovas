#include "ISPMain.h"

#include <cstdio>

namespace ISP
{
	//Esta incomplint el principi de SOLID perque pot fer mes de una cosa cada funcio
	//Pero aixo hem fet que cada Enemy tingui un IHurt i IAttack
	//Axins esta tot separat i no hi ha res que fagi varies coses
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
		//enemy2.ReceiveDamage(200000);
	}

	void ISPMain::ForceReceiveDamage(ISP_Enemy& enemy)
	{
		enemy.ReceiveDamage(200000);
		
	}
}