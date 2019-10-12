#include <iostream>
// Macro for multiplying 2 numbers
#define MULTIPLYMACRO(x,y) ( (x)*(y) )

using namespace std;

template <typename T>
T MultiplyTemplate(const T input1, const T input2)
{
    T output = input1 * input2;
    return output;
}

template<typename T>
void SwapTemplate(T& input1, T& input2)
{
    T temp = input1;
    input1 = input2;
    input2 = temp;
    return;
}

template<typename T1, typename T2>
class ArrayHolder{
    private:
    T1 arrayA[10] = {0};
    T2 arrayB[10] = {0};
    public:
    T1 * GetArrayA()
    {
        return arrayA;
    }
    T2 * GetArrayB()
    {
        return arrayB;
    }
};

//Method1
template<typename... Ts>
void Display1(const Ts... args)
{
    const int size = sizeof...(args) + 2;
    int res[size] = {1,args...,2};
    // since initializer lists guarantee sequencing, this can be used to
    // call a function on each element of a pack, in order:
    int dummy[sizeof...(Ts)] = { (std::cout << args << " ", 0)... };
    return;
}
//Method2
void Display2(){};
template <typename T1, typename... Tlast>
void Display2(T1 first, Tlast... last)
{
  cout << first << " ";
  Display2(last...);
}

int main()
{
    int iA = 7,iB = 4;
    double dA = 3.0, dB = 5.0; 
    ArrayHolder<double,int> Array1;
    ArrayHolder<int,double> Array2;

    cout << "This is a demonstration of a simple macro: " << MULTIPLYMACRO(iA,iB) << endl;
    cout << "This is a demonstration of a simple Multiply template on ints: " << MultiplyTemplate(iA,iB) << endl;
    cout << "This is a demonstration of a simple Multiply template on doubles: " << MultiplyTemplate(dA,dB) << endl;

    cout << "This is a demonstration of a simple Swap template on ints." << endl;
    cout << "Before: input1=" << iA << " input2=" << iB << endl;
    SwapTemplate(iA,iB);
    cout << "After: input1=" << iA << " input2=" << iB << endl;

    cout << "This is a demonstration of a simple Swap template on doubles." << endl;
    cout << "Before: input1=" << dA << " input2=" << dB << endl;
    SwapTemplate(dA,dB);
    cout << "After: input1=" << dA << " input2=" << dB << endl;

    int * iTest = NULL;
    double * dTest = NULL;
    dTest = Array1.GetArrayA();
    dTest[5] = 3.14;
    iTest = Array1.GetArrayB();
    iTest[0] = 99;
    cout << "This is a demonstration of a template to access 2 arrays..." << endl;
    for (int i = 0; i<10; i++)
    {
        cout << iTest[i] << " ";
    }
    cout << endl;
    for (int i = 0; i<10; i++)
    {
        cout << dTest[i] << " ";
    }
    cout << endl;

    cout << "This is a demonstration of a variadic template..." << endl;
    Display1(iA,iB,dA,dB);
    cout << endl;
    Display2(iA,iB,dA,dB);
    cout << endl;
    return 0;
}