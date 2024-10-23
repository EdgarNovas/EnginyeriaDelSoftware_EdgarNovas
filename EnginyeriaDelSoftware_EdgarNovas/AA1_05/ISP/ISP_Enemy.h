#pragma once
#include "IAttack.h"
#include "IHurt.h"
namespace ISP
{
	class ISP_Enemy : public IAttack, public IHurt
	{
	public:
		ISP_Enemy() = default;
		
		virtual ~ISP_Enemy() = default;

		virtual void Attack(IHurt* enemy)const = 0 ;
		virtual void ReceiveDamage(int damageToAdd) = 0;
	};
}
