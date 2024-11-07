#include <iostream>
#define MY_SING MySingleton::Instance() //NO PONER UN PUNTO Y COMA AQUI PORFAVOR
class MySingleton
{
private:

	MySingleton() = default;
	MySingleton(const MySingleton& s) = delete;
	MySingleton& operator= (const MySingleton& val) = delete;

public:

	static MySingleton& Instance()
	{
		static MySingleton instance;
		return instance;
	}

	void SayHi() {
		std::cout << "hi";
	}

};


int main()
{
	//MySingleton::Instance().SayHi();
	MY_SING.SayHi();
	
}