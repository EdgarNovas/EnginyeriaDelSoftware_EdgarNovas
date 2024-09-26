#include <string>
#include <vector>
#include <fstream>
#include<iostream>

int main()
{
	std::string sentence = "Hola em dic Jordi Radev";
	//1
	std::ofstream saveFile;
	saveFile.open("jordi.radev", std::ios::out | std::ios::binary);

	//2
	if (!saveFile.is_open())
		return -1;

	/*
	//3
	int size = sentence.size();
	saveFile.write(reinterpret_cast<char*>(&size), sizeof(int));
	saveFile.write(sentence.c_str(),sentence.size());
	*/

	std::vector<float> data;

	// fill the vector with 10 random numbers between [0.00, 100,00f]

	for (int i = 0; i < 10; i++)
	{
		float value = (float)(100 + rand() % 9901) / 100.00f;
		data.push_back(value);
	}

	int size = data.size();

	saveFile.write(reinterpret_cast<char*>(&size), sizeof(int));
	saveFile.write(reinterpret_cast<char*>(data.data()), sizeof(data[0]) * size);

	//4
	saveFile.close();

	//READ

	//1
	std::ifstream loadFile;
	loadFile.open("jordi.radev", std::ios::in | std::ios::binary);
	//2

	if (!loadFile.is_open())
		return -2;

	//3
	/*
	int readSize;
	loadFile.read(reinterpret_cast<char*>(&readSize), sizeof(int));

	char* buff = new char[readSize +1];
	loadFile.read(buff, readSize);
	buff[readSize] = '\0';

	std::string readString(buff);
	delete[] buff;

	std::cout << readString << std::endl;
	*/
	std::vector<float> readVector;
	int readSize;
	loadFile.read(reinterpret_cast<char*>(&readSize), sizeof(int));
	readVector.resize(readSize);
	loadFile.read(reinterpret_cast<char*>(readVector.data()), sizeof(float) * readSize);


	//4
	loadFile.close();


}
