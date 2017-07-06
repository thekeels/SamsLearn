#include <iostream>
#include <string>
using namespace std;

class Human {

	int age;
	string name;

public:
	Human() {};
	Human(const string humansName, int humansAge)
		: age(humansAge), name(humansName) { };
	int GetAge() {
		return age;
	}
	void SetAge(int humansAge)
	{
		age = humansAge;
	}
	string GetName() {
		return name;
	}
};

int main()
{
	Human myHuman("Kyle", 20);
	cout << myHuman.GetName() << " is " << myHuman.GetAge() << " years old." << endl;

	return 0;
}
