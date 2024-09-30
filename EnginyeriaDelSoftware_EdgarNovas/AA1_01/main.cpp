
#include "main.h"

class Teacher {
public:
    std::string name;
    inline void SayHi(){std::cout << "Hi"; }
};

void main()
{
    /*
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
    */


    //CLASE EXCEPTIONS

    std::ifstream inFile("BookStor.xml");
    
        try
        {
            //Error
            if (!inFile.is_open())
            {
                throw std::exception("Unable to open file");

            }

            //assert(inFile.is_open());
            rapidxml::xml_document<> doc;
            std::stringstream buffer;

            buffer << inFile.rdbuf();

            std::string content(buffer.str());
            doc.parse<0>(&content[0]);
            inFile.close();

            std::cout << doc.first_node()->name() << std::endl;
        }
        catch (std::exception c)
        {
            std::cout << "Error " << c.what() << std::endl;
            bool canGetOut = false;
            while (!canGetOut)
            {

                std::cout << "Prueba a escribir un nuevo archivo \n";
                std::string archivo = " ";
                std::cin >> archivo;

                inFile.open(archivo);
                try
                {
                    if (!inFile.is_open())
                    {
                        throw std::exception("Unable to open NEW file");
                    }
                    
                    canGetOut = true;
                    inFile.close();
                    
                }
                catch (std::exception c)
                {
                    std::cout << c.what() << std::endl;
                }
                
            }
            
        }
    
   

}