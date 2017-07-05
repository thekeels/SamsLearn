#include <iostream>

using namespace std;

class Human {
	int age;
private:

public:
	explicit Human(int humansAge) : age(humansAge) {};

};

void DoSomething(Human person)
{
	cout << "Human did something" << endl;
	return;
}

int main()
{
	Human kid(10);
	Human anotherKid = Human(11);
	DoSomething(kid);

	// Human anotherKid2 = 11; //implicit conversion failed --> cannot convert int to Human (explicit constructor defined)
	// DoSomething(11); //implicit conversion failed --> cannot convert int to Human (explicit constructor defined)

	return 0;
}