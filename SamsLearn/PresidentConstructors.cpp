#include <iostream>
#include <string>

using namespace std;

class President
{
private:
	President() {};
	President(const President&);
	President& operator= (const President&) {};
	
	string name;

public:
	static President& GetInstance() {
		static President onlyInstance;
		return onlyInstance;
	}
	string GetName()
	{
		return name;
	}
	void SetName(string InputName)
	{
		name = InputName;
	}

};

void DoSomething(const President&) {
	cout << "I am president" << endl;
}

int main()
{
	President& onlyPresident = President::GetInstance();
	onlyPresident.SetName("Abe");
	
	//uncomment line to see how compile failures prohibit duplicates
	// President second; //inaccessible default constructor
	// President * third = new President(); // inaccessible default constructor
	// President fourth = onlyPresident; // copy constructor not accessible
	// onlyPresident = President::GetInstance(); // access operator= not accessible

	cout << "The name of the President is: ";
	cout << President::GetInstance().GetName() << endl;

	return 0;
}