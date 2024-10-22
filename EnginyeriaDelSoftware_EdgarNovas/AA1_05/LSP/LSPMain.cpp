#include "LSPMain.h"

#include <cstdio>

namespace LSP
{
	//El cambio es para mostrar toda la vida de los enemigos y asi tambien se podria acceder a 
	//un enemigo en concreto con el vector
	//
	//Esta funcion estaba incumpliendo OCP porque tenia funciones virtuales que no usaba
	// y las he usado y el otro principio de SOLID que no cumplia era hacer que cada clase 
	// hiciera una cosa como el BossHealth o el minion health
	// que ahora esta en sus clases y solo conocen ellos mismos su vida
	//
	void LSPMain::Main()
	{
		auto enemy = Minion();
		auto boss = Boss();
		auto enemies = std::vector<LSP_Enemy*>{ &enemy, &boss };

		PrintEnemiesHealth(enemies);
	}

	void LSPMain::PrintEnemiesHealth(const std::vector<LSP_Enemy*>& enemies)
	{
		for (LSP_Enemy* enemy : enemies) {
			std::printf("Enemy, tiene %d de vida\n", enemy->GetHealth());
		}
	}
}