#pragma once
namespace ISP {
	class IHurt {
	public:
		IHurt() = default;
		virtual void ReceiveDamage(int amount) = 0;
	};
}