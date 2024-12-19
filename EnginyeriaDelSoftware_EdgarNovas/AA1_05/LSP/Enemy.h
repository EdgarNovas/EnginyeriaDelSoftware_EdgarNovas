#pragma once
namespace LSP {
	class LSP_Enemy
	{
		//El health ha de estar en enemy porque tanto boss como enemy tienen vida y duplicarlo no tiene sentido
	protected:
		int health =60;
	public:
		LSP_Enemy() = default;
		virtual ~LSP_Enemy() = default;
		virtual int GetHealth() = 0;
	};
}