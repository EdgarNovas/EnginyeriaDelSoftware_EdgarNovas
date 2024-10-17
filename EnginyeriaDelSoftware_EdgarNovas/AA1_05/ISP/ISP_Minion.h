#pragma once
#include "ISP_Enemy.h"
namespace ISP
{
	class ISP_Minion : public ISP_Enemy
	{
	public:
		ISP_Minion();

		virtual void Attack(ISP_Enemy* enemy) const override;
		virtual void ReceiveDamage(int damageToAdd) override;
	};
}