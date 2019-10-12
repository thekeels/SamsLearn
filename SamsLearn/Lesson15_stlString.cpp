#include <iostream>
#include <string>
#include <initializer_list>
#include <algorithm>
#include <vector>


int main()
{
    using namespace std;

    string inputString;
    cout << "Enter a string: " << endl;
    cin >> inputString;
    //inputString = "testiuijdhflk";
    cout << "First we check if it's a palindrome..." << endl;
    string inputStringCpy = inputString;
    reverse(inputStringCpy.begin(),inputStringCpy.end());
    if(inputString == inputStringCpy)
    {
        cout << "Palindrome!" << endl;
    }
    else
    {
        cout << "Not a Palindrome!" << endl;
    }
    string::iterator strIterator = inputString.begin();
    int vowelCount = 0;
    string vowelsString = "aeiou";
    for (auto vowel : vowelsString)
    {
        while (strIterator != inputString.end())
        {
        if(*strIterator == vowel)
        {
            ++vowelCount;
        }
        ++strIterator;
        }
        strIterator = inputString.begin();
    }
    cout << "Found " << vowelCount << " vowels." << endl;

    string inputStringCpy2 = inputString;
    strIterator = inputStringCpy2.begin();
    for (size_t i = 0; i<inputStringCpy2.size(); i++)
    {
        if(i %2 == 0)
        {
            transform(strIterator,strIterator+1,strIterator,::toupper);
        }
        ++strIterator;
    }
    cout << "Every other character to upper..." << endl;
    cout << inputStringCpy2 << endl;
    vector<string> stringVector;
    stringVector.push_back("I");
    stringVector.push_back("Love");
    stringVector.push_back("STL");
    stringVector.push_back("String");
    string sentence;
    for(string x : stringVector)
    {
        sentence.append(x);
        sentence.append(" ");
    }
    cout << sentence << endl;
    string greeting = "Good day String! Today is beautiful!";
    strIterator = greeting.begin();
    cout << "Searching for \"a\" in greeting...(" << greeting << ")" << endl;
    cout << "Found \"a\" at position: " << endl;
    while(strIterator != greeting.end())
    {
        if(*strIterator == 'a')
        {
            cout << distance(greeting.begin(),strIterator) << endl;
        }
        ++strIterator;
    }


    return 0;
}