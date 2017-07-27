#include <iostream>
#include <sstream>
#include <string>
#include <memory>

using namespace std;

class Date
{
private:
	int day, month, year;
	string dateInString;
public:
	Date(int inMonth, int inDay, int inYear) : month(inMonth), day(inDay), year(inYear) {};
	Date operator ++ (int)
	{
		Date copy(month,day,year);
		++day;
		return copy;
	}
	Date& operator ++ ()
	{
		++day;
		return *this;
	}
	Date& operator -- ()
	{
		--day;
		return *this;
	}
	Date operator -- (int)
	{
		Date copy(month, day, year);
		--day;
		return copy;
	}
	Date operator + (int daysToAdd)
	{
		Date addedDate(month, day + daysToAdd, year);
		return addedDate;
	}
	Date operator - (int daysToSub)
	{
		Date subbedDate(month, day - daysToSub, year);
		return subbedDate;
	}
	operator const char*()
	{
		ostringstream formattedDate;
		formattedDate << month << "/" << day << "/" << year << endl;
		dateInString = formattedDate.str();
		return dateInString.c_str();
	}
	bool operator < (const Date& compareTo)
	{
		if (year < compareTo.year)
			return true;
		else if (year == compareTo.year && month < compareTo.month)
			return true;
		else if (year == compareTo.year && month == compareTo.month && day < compareTo.day)
			return true;
		else return false;
	}

	void DisplayDate()
	{
		cout << month << "/" << day << "/" << year << endl;
	}
};

int main()
{

	Date holiday (12, 25, 2016);
	cout << "The date object is initialized to: ";
	
	holiday.DisplayDate();
	cout << "Holiday is on: " << holiday;
	string strHoliday(holiday);
	cout << "Holiday is on: " << strHoliday;
	string strHoliday2 = Date(11, 11, 2015);
	cout << "Holiday is on: " << strHoliday2;
	Date post_test = holiday++;
	post_test.DisplayDate();
	Date pre_test = ++holiday;
	pre_test.DisplayDate();
	cout << "Date after prefix-increment is: ";
	Date post_test2 = holiday--;
	post_test2.DisplayDate();
	Date pre_test2 = --holiday;
	pre_test2.DisplayDate();
	cout << "Date after a prefix-decrement is: ";
	holiday.DisplayDate();

	Date dayAfterXmas = holiday + 1;
	dayAfterXmas.DisplayDate();
	Date holiday2(11, 31, 2015);
	if (holiday < holiday2)
		int x = 1;
	else
		int x = 0;


	unique_ptr<int> smartPtrInt(new int);
	*smartPtrInt = 42;
	int * dumbPointerInt = new int;
	*dumbPointerInt = 42;
	cout << *dumbPointerInt << endl;

	unique_ptr<Date> smartPtrDate(new Date(2, 14, 2011));
	smartPtrDate->DisplayDate();
	Date * dumbPointerDate = new Date(11,2,2017);
	dumbPointerDate->DisplayDate();
	string dumbPtrDateStr(*dumbPointerDate);
	cout << dumbPtrDateStr;

	delete dumbPointerDate;
	delete dumbPointerInt;
	return 0;
}