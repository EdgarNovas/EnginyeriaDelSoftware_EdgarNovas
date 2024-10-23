#pragma once
#include "ISP_Enemy.h"
#include "ISP_Boss.h"
#include "ISP_Minion.h"
#include "IAttack.h"
#include "IHurt.h"

namespace ISP
{
	class ISPMain
	{
	public:
		void Main();
	private:
		void AttackTurn(const ISP_Enemy& enemy1, ISP_Enemy& enemy2);
		void ForceReceiveDamage(ISP_Enemy& enemy);//
	};
}