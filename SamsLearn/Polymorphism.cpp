#include <iostream>
using namespace std;
class Animal
{
public:
	Animal()
	{
		cout << "Animal constructor" << endl;
	}

	// sample member
	int age;
};

class Mammal : public virtual Animal
{};

class Bird : public virtual Animal
{};

class Reptile : public virtual Animal
{};

class Platypus final :public Mammal, public Bird, public Reptile
{
public: 
	Platypus() 
	{
		cout << "Platypus constructor" << endl;
	}
};

int main()
{
	Platypus duckBilledP;

	//uncomment next line to see compile error
	//age is ambiguous as there are three instances of base Animal
	duckBilledP.age = 25;
	return 0;
}