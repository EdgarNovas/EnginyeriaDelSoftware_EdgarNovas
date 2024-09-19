#include <fstream>
#include <iostream>
#include <string>
void main() {
	std::string line;
		
	int value = 10;
	
	//1 Open the file (write or read)

	std::ofstream outputFile;

	outputFile.open("jordi.radev");

	//2 Check if file IS open

	if (!outputFile.is_open()) {
		//Error Message
		std::cout << "Cannot open the file" << std::endl;
		return;
	}


	//3 - Do stuff
	outputFile << value;

	//4 -Close the file

	outputFile.close();

	//Escriure borra les dades es diu TRUNCADE y que segueixi esc ribint es diu APPEND


	std::ifstream inputFile;

	inputFile.open("jordi.radev");

	if (!inputFile.is_open())
	{
		//Error
		return;
	}

	//Cualsevol d'aquestes 2 solucions fa el mateix
	
	char line[250];

	//inputFile.getline(line, 50);
	/*
	while (getline(inputFile, line))
	{
		std::cout << line << '\n';
	}
	*/
	
	
	
	//OR 

	inputFile >> value;
	inputFile.close();
	std::cout << value;

}

//Els archius diferents tenen una ESTRUCTURA diferent

	//les operacions principals son llegir y escriure

	//Cuan faig el enter a un app llegeixo y nomes escric cuan guardo