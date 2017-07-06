#include <iostream>

using namespace std;

class MonsterDB {
private:
	~MonsterDB() {};
public:
	static void DestroyInstance(MonsterDB * pInstance)
	{
		delete pInstance;
	}
	void DoSomething() {};

};

int main()
{
	MonsterDB * myDB = new MonsterDB();
	myDB->DoSomething();
	(*myDB).DoSomething(); // equivalent to previous line
	//delete myDB; // private destructor cannot be invoked

	//use static member to release memory
	MonsterDB::DestroyInstance(myDB);

	return 0;
}