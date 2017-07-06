#include <iostream>
#include <string>

using namespace std;

class Human
{

	

private:
	
	//string defaultName = "Jeff";
	int age;
public:
	//string name;
	const char* name;
	constexpr Human(const char* input)
		:name(input), age(2)// name("Jeff")
	{
//		name = input;
	};
	//const string name;
	/*Human() // default constructor
	{
		age = 20;
		cout << "Constructed an instance of class Human, age and name not set" << endl;

	} 
	Human(string humansName, int humansAge = 5) // overloaded constructor with default parameter
		:name(humansName), age(humansAge) // List initialization
	{
		cout << "Overloaded constructor creates " << name << " of " << age << " years" << endl;
		//Human::age = age; 
		//Human::name = name;
	}*/
	void IntroduceSelf()
	{

		cout << "I am ";
		int i = 0;
		while (*(name + i) != '\0') {
			cout << *(name + i);
			i++;
		}
		cout << " and am ";
		cout << age << " years old" << endl;
	}
	int GetAge()
	{
		if (age >= 30)
		{
			return (age - 2);
		}
		else 
			return age;
	}
	void SetAge(int humanAge)
	{
		if (humanAge > 0)
			age = humanAge;
	}
};


int main()
{
	
	//Human firstMan("Adam",25);
	const char * input = "Test";

	Human firstMan(input);
	//firstMan.name = "Adam";
	//firstMan.SetAge(25);
	//int adamAge = firstMan.GetAge();
	firstMan.IntroduceSelf();
	//Human firstWoman;
	Human firstWoman(input);
	firstWoman.name = "Eve";
	firstWoman.SetAge(32);
	//int eveAge = firstWoman.GetAge();
	firstWoman.IntroduceSelf();

	cout << firstMan.GetAge() << endl;
	cout << firstWoman.GetAge() << endl;

	return 0;

}