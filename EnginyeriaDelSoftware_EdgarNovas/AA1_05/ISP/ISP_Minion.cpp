#include "ISP_Minion.h"

namespace ISP
{
	ISP_Minion::ISP_Minion()
	{
	}
	
	
	void ISP_Minion::Attack(IHurt* enemy)const
	{
		enemy->ReceiveDamage(200);
	}
	void ISP_Minion::ReceiveDamage(int damageToAdd)
	{
	}
}