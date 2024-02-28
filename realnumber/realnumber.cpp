#include <iostream>
#include "methods_/methods.hpp"
#include <real_numberConfig.h>

using namespace std;

int main(int argc, char* argv[])
{
    binary number;
    int memory;
    double valueondec;

    cout << argv[0] << " Version " << real_number_VERSION_MAJOR << "." << real_number_VERSION_MINOR << endl;

    cout << "\n*** REAL NUMBER: STORAGE AND REPRESENTATION ***\n" << endl;

    cout <<  "Type the floating point precision: ";
    cin >> memory;

    if (memory != 32 && memory != 64)
    {
        error ("Error - precision should be simple or double\n");
    }

    number.setprecision(memory);

    if (memory == 32)
    {
        number.resultin32();
    }
    else if (memory == 64)
    {
        number.resultin64();
    }

    return 0;
}