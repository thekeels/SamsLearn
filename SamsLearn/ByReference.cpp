#include <iostream>

using namespace std;

void Area(double radius, double* result);
void Area(double radius, double &result); // Pass by reference
void Area(double radiusArray[], double &result, int index);
int main()
{
	double radius;
	cout << "Enter a radius" << endl;
	cin >> radius;
	
	double AreaFetched = 0;
	Area(radius, &AreaFetched);
	cout << "Area = " << AreaFetched << endl;

	Area(radius*2, AreaFetched);
	cout << "Area = " << AreaFetched << endl;

	double radiusArray[4] = { 1,2,3,4 };
	Area(radiusArray, AreaFetched, 0);
	cout << "Area = " << AreaFetched << endl;

	return 0;

}

void Area(double radius, double* result)
{
	*result = 2 * 3.14 * radius;
}

void Area(double radius, double &result) // Pass by reference
{	
result = 2 * 3.14 * radius;
}

void Area(double radiusArray[], double &result, int index)
{
	result = 2 * 3.14 * radiusArray[index];
}