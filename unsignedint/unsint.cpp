#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// class representing the number in the binary format.

class binaryint
{
    private:
        int ml;             // memory allocated to represent the unsigned int
        long int value;     // value that will be stored

    public:

    // constructors

        binaryint(int m, long int v): ml(m), value(v) {};
        binaryint(): ml(0), value(0) {};

    // mutator methods

        void setml(int m)
        {
            ml = m;
        }

        void setvalue(long int v)
        {
            value = v;
        }

    // accessor methods

        int getml()
        {
            return ml;
        }

        long int getvalue()
        {
            return value;
        }

    // transformation to binary pattern

        friend vector<int> decimaltobinary(long int source);

    // transformation to decimal pattern

        friend int binarytodecimal(vector<int> source);

    // result in binary pattern

        void result();

    // overflow test

        bool overflowtest();
};

int binarytodecimal(vector<int> source)
{
    long int sum = 0;
    
    for (int i = 0; i < source.size(); ++i)
    {
        sum += source.at(i) * pow(2, source.size() - i - 1);
    }

    return sum;
}

vector<int> decimaltobinary(long int source)
{
    vector<int> result;

    while (source != 0)
    {
        result.insert(result.begin(), source % 2);
        source = source / 2;
    }

    return result;
}

bool binaryint::overflowtest()
{
    if (value > (pow(2,ml) - 1))
        return true;
    else
        return false;
}

void binaryint::result()
{
    if (this->overflowtest())
    {
        cout << "\n!! OVERFLOW ALERT !!" << endl;
        cout << "The value stored here is: ";
        
        vector<int> result = decimaltobinary(value);

        while (result.size() != ml)
        {
            result.erase(result.begin());
        } 

        for (int i : result)
            cout << i;

        cout << endl;

        cout << "Transforming this into decimal, we have: ";

        int resultindecimal = binarytodecimal(result);

        cout << resultindecimal;

        cout << "\nThus, the value stored in the computer is " << resultindecimal << ", not " << value << endl;
    }

    else
    {
        vector<int> result = decimaltobinary(value);

        while (result.size() != ml)
        {
            result.insert(result.begin(), 0);
        } 

        for (int i : result)
            cout << i;

        cout << endl;
    }
}

int main()
{
    binaryint number;
    int memory;
    long int valueondec;

    cout << "\n*** UNSIGNED INT: STORAGE AND REPRESENTATION ***\n" << endl;

    cout <<  "Type the memory allocated (in bits) to the storage: ";
    cin >> memory;
    number.setml(memory);

    cout << "\nType a number on the decimal base: ";
    cin >> valueondec;
    number.setvalue(valueondec);
    
    cout << "\nThen, the representation of " << valueondec << " in a memory location of " << memory << " bits is: ";
    number.result();

    return 0;
}