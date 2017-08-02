#include <iostream>
#include <string.h>

using namespace std;

class MyString {
private:
	char* buffer;

public:
	MyString() {}
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
	MyString operator + (const MyString& addThis)  
	{
		MyString newString;
		if (addThis.buffer != NULL)
		{
			int x = GetLength();
			newString.buffer = new char[GetLength() + strlen(addThis.buffer) + 1];
			strcpy(newString.buffer, buffer);
			strcat(newString.buffer, addThis.buffer);
		}
		return  newString;
	}

	MyString& operator= (const MyString& copySource) 
	{
		if ((this != &copySource) && (copySource.buffer != NULL)) // Make sure the source and destination objects are not the same.
		{
			if (buffer != NULL)
			{
				delete[] buffer; // Clear out the existing buffer
			}
			buffer = new char[strlen(copySource.buffer) + 1]; // Create space for the new buffer based on what's in copySource
			strcpy(buffer, copySource.buffer); // Load the contents of the copySource buffer into the new buffer
		}
		return *this;
	}

	MyString& operator= (MyString&& moveSource)
	{
		cout << "Invoking the move assignment operator" << endl;
		if ((moveSource.buffer != NULL) && (this != &moveSource))
		{
			delete[] buffer;
			buffer = moveSource.buffer;
			moveSource.buffer = NULL;
		}
		return *this;
	}

	~MyString() 
	{
		cout << "Invoking the destructor, clearing up" << endl;
		delete[] buffer;
	}
	operator const char* ()  // Allows conversion of the MyString type to const char* type
	{
		return buffer;
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
	MyString sayWhat("What");
	MyString sayWho("Who");
	MyString sayWhen("When");
	sayWhen = sayWhat + sayWho; // Invokes the copy assignment operator
	MyString sayIt(sayWhat + sayWho); // Invokes the + operator
	MyString sayHelloAgain(Copy(sayHello)); // Links to Copy function
	cout << sayWhat << endl;
	return 0;
}