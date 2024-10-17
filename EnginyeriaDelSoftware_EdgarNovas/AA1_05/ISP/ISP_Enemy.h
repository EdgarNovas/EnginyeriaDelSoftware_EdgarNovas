#pragma once
namespace ISP
{
	class ISP_Enemy
	{
	public:
		ISP_Enemy() = default;
		virtual ~ISP_Enemy() = default;

		virtual void Attack(ISP_Enemy* enemy) const = 0 ;
		virtual void ReceiveDamage(int damageToAdd) = 0;
	};
}
