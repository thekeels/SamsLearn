#include <iostream>

using namespace std;

class DynIntegers
{
private:
	int* _pIntegers;
	int size;
public:
	DynIntegers() : size(64), _pIntegers(new int[64])  // Default constructor
	{
		cout << "Default Constructor called" << endl;
	}
	DynIntegers(int n) : size(n), _pIntegers(new int[n]) // Overloaded constructor
	{
		cout << "Constructor called for array with size " << size << endl;
	}
	~DynIntegers() // Destructor
	{
		cout << "Destructor called" << endl;
		delete[] _pIntegers;
	}

	DynIntegers(const DynIntegers& copySource)  // Copy constructor
	{
		cout << "Copy Constructor called" << endl;
		_pIntegers = new int[copySource.size]; // Copies the
		for (int i = 0; i < copySource.size; i++)
		{
			_pIntegers[i] = copySource._pIntegers[i];
		}
		size = copySource.size;
	}

	DynIntegers(DynIntegers&& moveSource)  // Move constructor
	{
		cout << "Move Constructor called" << endl;
		if (moveSource._pIntegers != NULL)
		{
			_pIntegers = moveSource._pIntegers; // Transfers the pointer from moveSource to the destination
			moveSource._pIntegers = NULL; // Frees up the moveSource pointer
			size = moveSource.size;
		}
	}

	DynIntegers& operator= (const DynIntegers& copySource)  // Copy assignment operator
	{
		cout << "Copy Assignment Operator called" << endl;
		_pIntegers = new int[copySource.size]; // Copies the
		for (int i = 0; i < copySource.size; i++)
		{
			_pIntegers[i] = copySource._pIntegers[i];
		}
		size = copySource.size;
		return *this;

	}

	DynIntegers& operator= (DynIntegers&& moveSource) // Move assignment operator
	{
		cout << "Move Assignment Operator called" << endl;
		if ((this != &moveSource) && (moveSource._pIntegers != NULL))
		{
			delete[] _pIntegers; // Free up the destination pointer 
			_pIntegers = moveSource._pIntegers; // Transfers the pointer from moveSource to the destination
			moveSource._pIntegers = NULL; // Frees up the moveSource pointer
			size = moveSource.size;
		}
		return *this;
	}

	DynIntegers operator+ (DynIntegers& addSource)
	{
		int i;
		DynIntegers added(10);
		for (i = 0; i < addSource.size; i++)
		{
			*(added._pIntegers) = *(this->_pIntegers) + *(addSource._pIntegers); // "this" is the first argument, addSource is the second
			added._pIntegers++;
			addSource._pIntegers++;
			this->_pIntegers++;
		}
		added._pIntegers -= i;
		addSource._pIntegers -= i;
		this->_pIntegers -= i;
		cout << "Operator+ called" << endl;
		return added;
	}

	void fillArray()
	{
		int i;
		for (i = 0; i < size; i++)
		{
			*_pIntegers = i*3;
			_pIntegers += 1;
		}
		_pIntegers -= i;
	}

	void fillArray2()
	{
		int i;
		for (i = 0; i < size; i++)
		{
			*_pIntegers = i * 4;
			_pIntegers += 1;
		}
		_pIntegers -= i;
	}
	void printArray()
	{
		int i;
		for (i = 0; i < size; i++)
		{
			cout << "The value at index " << i << " is : " << *_pIntegers << endl;
			_pIntegers += 1;
		}
		_pIntegers -= i;
	}
};

int main()
{
	DynIntegers myDynamicArray(10);
	myDynamicArray.fillArray();
	myDynamicArray.printArray();
	DynIntegers myDynamicArray2(10);
	myDynamicArray2.fillArray2();
	myDynamicArray2.printArray();
	DynIntegers myDynamicArrayCopy2(10);
	myDynamicArrayCopy2 = myDynamicArray2 + myDynamicArray;
	myDynamicArrayCopy2.printArray();

	return 0;
}