#pragma once
#include "ISP_Enemy.h"
namespace ISP
{
	class ISP_Boss : public ISP_Enemy
	{
	public:
		ISP_Boss();

		virtual void Attack(IHurt* enemy)const override;
		virtual void ReceiveDamage(int damageToAdd) override;
	};
}