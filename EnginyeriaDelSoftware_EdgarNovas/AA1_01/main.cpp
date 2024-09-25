#include "dep/inc/xml/rapidxml.hpp"
#include "dep/inc/xml/rapidxml_print.hpp"
#include "dep/inc/xml/rapidxml_utils.hpp"
#include "dep/inc/xml/rapidxml_iterators.hpp"

#include <sstream>

#include <iostream>
#include <string>
#include <vector>




// Define Weapon Class
struct Weapon {
    int id;
    std::string type;
    float range;
};

// Define Enemy Class
struct Enemy {
    std::string name;
    int hp;
    int attack;
    int defense;
    int experience;
    float attackFrequency;
    std::vector<int> weapons;  // IDs de les armes
};


class EnemyManager {
public:
    std::vector<Enemy> enemies;          // Llista d'enemics
    std::vector<Weapon> weapons;         // Llista d'armes

    // Mètode per llegir l'arxiu XML i omplir les estructures de dades
    void loadFromXML(const std::string& filename) {
        rapidxml::file<> xmlFile(filename.c_str()); // Crea un objecte per llegir el fitxer XML
        rapidxml::xml_document<> doc;
        doc.parse<0>(xmlFile.data()); // Analitza el contingut del fitxer

        // Llegir armes
        rapidxml::xml_node<>* weaponsNode = doc.first_node("game")->first_node("weapons");
        for (rapidxml::xml_node<>* weaponNode = weaponsNode->first_node("weapon"); weaponNode; weaponNode = weaponNode->next_sibling()) {
            Weapon weapon;
            weapon.id = std::stoi(weaponNode->first_node("id")->value());
            weapon.type = weaponNode->first_node("type")->value();
            weapon.range = std::stof(weaponNode->first_node("range")->value());

            weapons.push_back(weapon); // Afegir arma a la llista
        }

        // Llegir enemics
        rapidxml::xml_node<>* enemiesNode = doc.first_node("game")->first_node("enemies");
        for (rapidxml::xml_node<>* enemyNode = enemiesNode->first_node("enemy"); enemyNode; enemyNode = enemyNode->next_sibling()) {
            Enemy enemy;
            enemy.name = enemyNode->first_node("name")->value();
            enemy.hp = std::stoi(enemyNode->first_node("hp")->value());
            enemy.attack = std::stoi(enemyNode->first_node("attack")->value());
            enemy.defense = std::stoi(enemyNode->first_node("defense")->value());
            enemy.experience = std::stoi(enemyNode->first_node("experience")->value());
            enemy.attackFrequency = std::stof(enemyNode->first_node("attackFrequency")->value());

            // Llegir les armes que pot usar
            rapidxml::xml_node<>* weaponsListNode = enemyNode->first_node("weapons");
            for (rapidxml::xml_node<>* weaponIDNode = weaponsListNode->first_node("weapon"); weaponIDNode; weaponIDNode = weaponIDNode->next_sibling()) {
                int weaponID = std::stoi(weaponIDNode->value());
                enemy.weapons.push_back(weaponID); // Afegir ID d'arma a la llista
            }

            enemies.push_back(enemy); // Afegir enemic a la llista
        }
    }
};

void main()
{
    EnemyManager enemyManager;
    enemyManager.loadFromXML("enemies.xml");

    // Exemple d'ús: mostrar informació dels enemics
    for (const auto& enemy : enemyManager.enemies) {
        std::cout << "Enemic: " << enemy.name
            << ", HP: " << enemy.hp
            << ", Atac: " << enemy.attack
            << ", Defensa: " << enemy.defense
            << ", Experiència: " << enemy.experience
            << ", Freqüència d'Atac: " << enemy.attackFrequency << "\n";

        std::cout << "Armes: ";
        for (int weaponID : enemy.weapons) {
            std::cout << weaponID << " ";
        }
        std::cout << "\n";
    }


}