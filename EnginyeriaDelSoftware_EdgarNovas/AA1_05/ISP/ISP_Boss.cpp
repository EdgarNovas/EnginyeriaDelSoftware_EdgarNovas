#include "ISP_Boss.h"

namespace ISP {
	ISP_Boss::ISP_Boss()
	{
	}

	void ISP_Boss::Attack(IHurt* enemy) const
	{
		enemy->ReceiveDamage(20);
	}
	void ISP_Boss::ReceiveDamage(int damageToAdd)
	{
	}
}