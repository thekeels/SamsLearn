#include <iostream>
using namespace std;

int main()
{
	int age = 20;
	int* pointertoint = &age;

	cout << "Age is located at: 0x" << hex << pointertoint << endl;
	cout << "Age is located at: 0x" << pointertoint << endl;
	cout << "size of pointer to int: " << sizeof(int*) << endl;

	int &ref = age;
	cout << "&ref = " << &ref << endl;
	cout << "ref = " << dec << ref << endl;
	
	int * pointToAnInt = new int;
	int * pNumberCopy = pointToAnInt;
	*pNumberCopy = 30;
	cout << *pointToAnInt << endl;
	delete pointToAnInt;

	return 0;
}