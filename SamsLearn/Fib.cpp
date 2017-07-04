#include <iostream>
using namespace std;

int main()
{
	int num;
	int result;
	int count;
	char restart = 'y';
	while (restart == 'y') {
		cout << "How many Fibonacci numbers do you want to compute?" << endl;
		cin >> num;
		int firstNum = 0;
		int secondNum = 1;

		if (num == 1)
		{
			cout << firstNum << endl;
		}
		else if (num == 2)
		{
			cout << firstNum << " " << secondNum << endl;
		}
		else
		{
			cout << firstNum << " ";
			cout << secondNum << " ";
			count = 2;
			while (count != num)
			{
				result = firstNum + secondNum;
				cout << result << " ";
				firstNum = secondNum;
				secondNum = result;
				++count;
			}
		}
		cout << "Wish to continue? (y/n) " << endl;
		cin >> restart;
	}
	return(0);

}