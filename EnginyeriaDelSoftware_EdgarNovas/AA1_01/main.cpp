
#include "main.h"


void main()
{
    EnemyManager enemyManager;
    enemyManager.loadFromXML("enemies.xml");

    // Show enemy info
    for (const auto& enemy : enemyManager.enemies) {
        std::cout << "Enemy Name: " << enemy.name
            << ", HP: " << enemy.hp
            << ", Attack: " << enemy.attack
            << ", Defense: " << enemy.defense
            << ", Experience: " << enemy.experience
            << ", AttackFrequency: " << enemy.attackFrequency << "\n";

        std::cout << "Weapons: ";
        for (int weaponID : enemy.weapons) {
            std::cout << weaponID << " ";
        }
        std::cout << "\n";
    }


}