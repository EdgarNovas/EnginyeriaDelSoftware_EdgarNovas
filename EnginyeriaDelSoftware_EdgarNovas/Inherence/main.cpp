#include <iostream>
class Vehicle {
public:
	int horsePower;
	Vehicle(int _horsePower):horsePower(_horsePower) {}
	void Accelerate();
	void Break();
	void Steer();

};

class Car : public Vehicle
{
public:
	Car()
		: Vehicle(100){}
	//Si Vehicle que es el pare y no te constructor default 
	//Car ha de fer la mateixa construccio que vehicle 
	//Ja que per construir un car has de construir un vehicle
	Car(int _horsePower)
		: Vehicle(_horsePower) {}

};


class Figure {
public:

	virtual void Draw() { std::cout << "Figure"; };
};

class Triangle: public Figure {
public:
	int b;

	int h;
	void Draw() override { std::cout << "Triangle"; }
};

class Square : public Figure {
public:
	void Draw() override { std::cout << "Square"; }
};

/*
int main() {

	
	Figure* fig = new Triangle();
	fig->Draw();

	Figure* val = new Square();
	val->Draw();

	if (Triangle* temp = dynamic_cast< Triangle*>(fig))
	{
		std::cout << temp->b;
	}


	return 0;
}
*/