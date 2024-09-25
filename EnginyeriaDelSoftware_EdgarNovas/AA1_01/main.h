#include "dep/inc/xml/rapidxml.hpp"
#include "dep/inc/xml/rapidxml_print.hpp"
#include "dep/inc/xml/rapidxml_utils.hpp"
#include "dep/inc/xml/rapidxml_iterators.hpp"

#include <sstream>

#include <iostream>
#include <string>
#include <vector>


#pragma once

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
    std::vector<int> weapons;  
};



class EnemyManager {
public:
    std::vector<Enemy> enemies;
    std::vector<Weapon> weapons;

    // Method to read xml file and fill the data
    void loadFromXML(const std::string& filename) {
        rapidxml::file<> xmlFile(filename.c_str());
        rapidxml::xml_document<> doc;
        doc.parse<0>(xmlFile.data());

        // Read Enemies
        for (rapidxml::xml_node<>* enemyNode = doc.first_node("game")->first_node("enemies")->first_node("enemy");
            enemyNode; enemyNode = enemyNode->next_sibling()) {
            Enemy enemy;
            // I Use stoi to convert strings into ints
            enemy.name = enemyNode->first_node("name")->value();
            enemy.hp = std::stoi(enemyNode->first_node("hp")->value());
            enemy.attack = std::stoi(enemyNode->first_node("attack")->value());
            enemy.defense = std::stoi(enemyNode->first_node("defense")->value());
            enemy.experience = std::stoi(enemyNode->first_node("experience")->value());
            enemy.attackFrequency = std::stof(enemyNode->first_node("attackFrequency")->value());

            // Read weapons
            for (rapidxml::xml_node<>* weaponIDNode = enemyNode->first_node("weapons")->first_node("weapon");
                weaponIDNode; weaponIDNode = weaponIDNode->next_sibling()) {
                enemy.weapons.push_back(std::stoi(weaponIDNode->value()));
            }

            enemies.push_back(enemy);
        }

    }
};