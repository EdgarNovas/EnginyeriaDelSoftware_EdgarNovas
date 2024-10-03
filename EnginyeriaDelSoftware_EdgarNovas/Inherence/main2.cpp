#include <iostream>
#include <vector>

class Character {
public:
	int health;
	int damage;

	Character(int _health, int _damage)
		: health(_health), damage(_damage) {}

	virtual void Attack(Character* other) {
		ReceiveDamage(this->damage);
	}


	virtual void ReceiveDamage(int amount) {
		this->health -= amount;
	}

	//Una classe abstracta es una classe que te 
	// una o mes funcions abstractes
	virtual void SaySomething() = 0;



};

class Radev : public Character {
public:
	Radev()
		: Character(20,7) {};

	void Attack(Character* other) override {
		int value = rand() % 100;
		if (value >= 30)
			other->ReceiveDamage(this->damage * 2);
		else
			Character::Attack(other);
	}


	void SaySomething() override {
		std::cout << "LMAO" << std::endl;
	}
};

class Richard : public Character {
public:
	int shield;
	Richard()
		: Character(25, 8), shield(10) {}

	void ReceiveDamage(int amount) override {
		if (shield > 0) {
			shield = std::max(0, shield - amount);
		}
		else
			Character::ReceiveDamage(amount);
	}

	void SaySomething() override {
		std::cout << "LOL" << std::endl;
	}

};

void main() {
	std::vector<Character*> chars;
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		chars.push_back(new Radev());
		chars.push_back(new Richard());
		

	}


	for (int i = 0; i < chars.size(); i++)
	{
		int target;
		do {
			target = rand() % chars.size();
		} while (target == i);
		
		chars[i]->Attack(chars[target]);

		chars[i]->SaySomething();

	}
	
}