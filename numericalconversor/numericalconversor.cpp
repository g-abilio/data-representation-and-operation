#include "methods_/methods.hpp"
#include <iostream>

using namespace std;

int main()
{
    char opt1;
    char opt2;
    string test;

    cout << "\n*** NUMERICAL CONVERSOR ***\n" << endl;

    cout << "Type the numerical system wanted:\n" << "d for decimal\n" << "b for binary\n" << "h for hexadecimal\n" << "o for octal" << endl;
    cin >> opt1;

    test = inputnumber(opt1);

    cout << "Type the numerical system wanted for conversion:\n"  << "d for decimal\n" << "b for binary\n" << "h for hexadecimal\n" << "o for octal" << endl;
    cin >> opt2;

    baseconversion(opt1, opt2, test); 

    return 0;
}