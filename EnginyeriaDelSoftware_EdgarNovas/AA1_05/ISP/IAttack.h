#pragma once
#include "IHurt.h"
namespace ISP {

	class IAttack
	{
	public:
		IAttack() = default;
		virtual void Attack(IHurt* enemy)const = 0;
	};
}
