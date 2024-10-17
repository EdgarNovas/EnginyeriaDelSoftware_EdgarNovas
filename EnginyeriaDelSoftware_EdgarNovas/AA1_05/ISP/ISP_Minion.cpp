#include "ISP_Minion.h"

namespace ISP
{
	ISP_Minion::ISP_Minion()
	{
	}
	void ISP_Minion::Attack(ISP_Enemy* enemy) const
	{
		enemy->ReceiveDamage(10);
	}
	void ISP_Minion::ReceiveDamage(int damageToAdd)
	{
	}
}