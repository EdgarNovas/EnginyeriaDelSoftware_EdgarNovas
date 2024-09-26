#include <string>
#include <vector>
#include <fstream>
#include <iostream>

int main()
{
	//1) Declare data

	int a[10];

	//2) Init data
	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
	}


	//3) Open file
	std::ofstream myFile;

	myFile.open("save.dat",std::ios::out | std::ios::binary | std::ios::app);
	
	//4) Check if file is open

	if (!myFile.is_open())
		return -1;

	//5)Write to file

	myFile.write(reinterpret_cast<char*>(&a), sizeof(int) * 10);

	//6) Close the file
	myFile.close();


	//READ

	//1)
	std::ifstream myFileIn;

	myFileIn.open("save.dat", std::ios::in | std::ios::binary);

	//2) Check if file is open

	if (!myFileIn.is_open())
		return -2;

	//3) Change array values

	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 100;
		std::cout << a[i] << ", ";
	}

	//4)Read from file

	myFileIn.read(reinterpret_cast<char*>(&a), sizeof(int) * 10);


	//5) Check Value
	for (int i = 0; i < 10; i++)
	{
		std::cout << a[i];
	}

	//6)Close File
	myFileIn.close();

	return 0;
}

