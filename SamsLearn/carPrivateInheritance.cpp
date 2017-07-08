#include <iostream>
using namespace std;

class Motor
{
public:
	void SwitchIginition()
	{
		cout << "Ignition on" << endl;
	}
	void PumpFuel()
	{
		cout << "Fuel in cylinders" << endl;
	}
	void FireCylinders()
	{
		cout << "Vroooom" << endl;
	}

};
//class Car : private Motor // if private, derived classes have zero access to public methods/attributes of motor
class Car : protected Motor // if protected, derived classes have full access to public methods/attributes of motor
{
public:
	void Move()
	{
		SwitchIginition();
		PumpFuel();
		FireCylinders();
	}
};

class RaceCar : protected Car
{
public:
	void Move()
	{
		SwitchIginition(); // With protected Motor, we have access to these protected Motor methods
		PumpFuel(); // With private Motor, these Motor methods are inaccessible
		FireCylinders();
		cout << "Let's go fast" << endl;
	}
	
};

int main()
{
	Car myCar;
	RaceCar myRaceCar;
	myCar.Move();
	myRaceCar.Move();
	return 0;
}

