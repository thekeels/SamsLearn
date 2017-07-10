#include <iostream>

using namespace std;

class Shape
{
public:
	virtual void Area() = 0;
	virtual void Print() = 0;
};

class Cirle :public Shape
{
public:
	void Area() override final 
	{
		cout << "Circle Area" << endl;
	}
	void Print() override final
	{}
};

class Triangle :public Shape
{
public:
	void Area() override final
	{
		cout << "Triangle Area" << endl;
	}
	void Print() override final
	{}
};

int main()
{
	Cirle myCircle;
	Triangle myTriangle;
	myCircle.Area();
	myTriangle.Area();
	return 0;
}