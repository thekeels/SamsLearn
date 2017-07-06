#include <iostream>
using namespace std;

class Circle {
private:
	const double pi = 3.14;
	const double radius;


public:
	const double area;
	const double circumference;
	constexpr Circle(const double circleRadius = 1) : radius(circleRadius), area(pi*circleRadius*circleRadius), circumference(2*pi*circleRadius)
	{}

	const double GetRadius() const
	{
		return radius;
	}
};

int main()
{

	constexpr Circle circle1(2.7);
	cout << "Circle of radius " << circle1.GetRadius() << " has area " << circle1.area \
		<< " and circumference " << circle1.circumference << endl;
	return 0;
}