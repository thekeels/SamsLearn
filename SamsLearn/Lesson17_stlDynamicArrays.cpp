#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <deque>

using namespace std;

template<typename T>
void Display(deque<T> & toDisplay)
{
    auto element = toDisplay.begin();
    for(toDisplay.begin();element != toDisplay.end();++element)
    {
        cout << *element << endl;
    } 
}

int main(){
    string loopCheck;
    int userInput, loopInt;
    vector<int> integers;
    do{
        cout << "Enter an integer (press i), query (press q), search (press s), or continue (c): ";
        cin >> loopCheck;
        if(loopCheck == "i"){
            cout << "Enter an integer value: ";
            cin >> userInput;
            if (cin.fail())
                {
                        cout << "Please enter an integer!" << endl;
                        // clear error state
                        cin.clear();
                        // discard 'bad' character(s)
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            else{
                integers.push_back(userInput);
            }
            
        }
        else if (loopCheck == "q")
        {
            cout << "Which element would you like to query? ";
            cin >> userInput;
            if (cin.fail())
            {
                    cout << "Please enter an integer!" << endl;
                    // clear error state
                    cin.clear();
                    // discard 'bad' character(s)
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                if(userInput < integers.size())
                    {
                        cout << "Element[" << userInput << "] = " << integers[userInput] << endl;
                    }
                    else
                    {
                        cout << "That element is outside the bounds of the array!" << endl;
                    }
            }
        }
        else if(loopCheck == "s"){
            cout << "Enter an integer to search for: ";
            cin >> userInput;
            if (cin.fail())
                {
                        cout << "Please enter an integer!" << endl;
                        // clear error state
                        cin.clear();
                        // discard 'bad' character(s)
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            else{
                auto found = find(integers.begin(), integers.end(),userInput);
                if (found != integers.end())
                {
                    auto location = distance(integers.begin(),found);
                    cout << userInput << " found at offset " << location << endl;
                }
                else
                {
                    cout << userInput << " not found..." << endl;
                }
                
            }
        }
    } while (loopCheck != "c");

    double userInputL, userInputH, userInputW;
    vector<double> packageL;
    vector<double> packageW;
    vector<double> packageH;
    bool inputOk = true;
    cout << "Welcome to Jack's warehouse..." << endl;
    cout << "Enter package dimensions..." << endl;
    cout << "Length: ";
    string inputString;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, inputString);
    int decimalCount = 0;
    for (char c : inputString)
    {
        if(c == '.')
        {
            ++decimalCount;
        }
    }
    if (decimalCount>1) {
        cout << "Unrecognized number..." << endl;
        inputOk = false;
    }
    stringstream s(inputString);
    if(!((s >> userInputL) && inputOk)) inputOk = false;
    cout << "Width: ";
    getline(cin, inputString);
    s.str(inputString);
    s.clear();
    decimalCount = 0;
    for (char c : inputString)
    {
        if(c == '.')
        {
            ++decimalCount;
        }
    }
    if (decimalCount>1) {
        cout << "Unrecognized number..." << endl;
        inputOk = false;
    }
    s << inputString;
    if(!((s >> userInputW) && inputOk))inputOk = false;
    cout << "Height: ";
    getline(cin, inputString);
    decimalCount = 0;
    for (char c : inputString)
    {
        if(c == '.')
        {
            ++decimalCount;
        }
    }
    if (decimalCount>1) {
        cout << "Unrecognized number..." << endl;
        inputOk = false;
    }
    s.str(inputString);
    s.clear();
    if(!((s >> userInputH) && inputOk))inputOk = false;

    if(inputOk)
    {
        packageL.push_back(userInputL);
        packageW.push_back(userInputW);
        packageH.push_back(userInputH);
        cout << "Package is " << packageL[0] << " by " << packageW[0] << " by " << packageH[0] << endl;
    }
    else
    {
        cout << "No package entered, please come again." << endl;
    }
    
    cout << "Entering deque check!" << endl;
    deque<string> strDq { "Hello"s, "Containers are cool"s, "C++ is evolving!"s };
    Display(strDq);

    return 0;
}