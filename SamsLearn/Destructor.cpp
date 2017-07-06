#include <iostream>
#include <string.h>

using namespace std;

class MyString {
private:
	char* buffer;

public:
	MyString(const char * initString)
	{
		buffer = NULL;
		cout << "Invoking default constructor: creating new MyString" << endl;
		if (initString != NULL)
		{
			buffer = new char[strlen(initString) + 1];
			strcpy(buffer, initString);
			cout << "buffer points to: 0x" << hex;
			cout << (unsigned int*)buffer << endl;
		}
	}
	MyString(const MyString& copySource)
	{
		buffer = NULL;
		cout << "Invoking copy constructor: copying from MyString" << endl;
		if (copySource.buffer != NULL) {
			buffer = new char[strlen(copySource.buffer) + 1];
			strcpy(buffer, copySource.buffer);
			cout << "buffer points to: 0x" << hex;
			cout << (unsigned int*)buffer << endl;
		}
	}
	MyString(MyString&& moveSource)
	{
		cout << "Invoking the move constructor" << endl;
		if (moveSource.buffer != NULL)
		{
			buffer = moveSource.buffer;
			moveSource.buffer = NULL;
		}
	}
	~MyString()
	{
		cout << "Invoking the destructor, clearing up" << endl;
		delete[] buffer;
	}
	int GetLength()
	{
		return strlen(buffer);
	}
	const char* GetString()
	{
		return buffer;
	}
};

void UseMyString(MyString str)
{
	cout << "String buffer in MyString is " << str.GetLength();
	cout << " characters long " << endl;
	cout << "buffer contains: " << str.GetString() << endl;
	return;
}

MyString Copy(MyString& source)
{
	MyString copyForReturn(source);
	//MyString copyForReturn(source);
	return copyForReturn;
}

int main()
{
	MyString sayHello("Hello from String Class");
	//cout << "String buffer in sayHello is " << sayHello.GetLength();
	//cout << " characters long" << endl;
	//cout << "Buffer contains " << sayHello.GetString() << endl;
	//UseMyString(sayHello);

	MyString sayHelloAgain(Copy(sayHello));

	return 0;
}