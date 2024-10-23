#pragma once
#include "ISP_Enemy.h"
namespace ISP
{
	class ISP_Minion : public ISP_Enemy
	{
	public:
		ISP_Minion() = default;

		virtual void Attack(IHurt* enemy)const override;
		virtual void ReceiveDamage(int damageToAdd);
	};
}