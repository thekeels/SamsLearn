#include <iostream>
using namespace std;

class Fish
{
private:
	bool isFreshWaterFish;
	
public:
	Fish(bool fishType) : isFreshWaterFish(fishType)// overloaded constructor
	{
	}
	void Swim()
	{
		cout << "Fish swims" << endl;
	}
	void Swim(bool fishType)
	{
		if (isFreshWaterFish)
			cout << "Swims in the lake" << endl;
		else
			cout << "Swims in the ocean" << endl;
	}
};

class Tuna : public Fish
{
public:
	Tuna() : Fish(false) { }
	using Fish::Swim;
	void Swim()
	{
		cout << "Tuna swims fast" << endl;
	}

};

class Carp : public Fish
{
public:
	
	Carp() : Fish(true) {}
	void Swim()
	{
		cout << "Carp swims slow" << endl;
	}
	void Swim(bool fishType)
	{
		Fish::Swim(fishType);
	}
};

int main()
{
	Tuna myDinner;
	Carp myLunch;
	cout << "My dinner: ";
	myDinner.Swim();
	myDinner.Swim(false);
	myDinner.Fish::Swim();
	cout << "My lunch: ";
	myLunch.Swim();
	myLunch.Swim(false);

	return 0;
}
