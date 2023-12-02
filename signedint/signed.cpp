#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// class representing the number in the binary format.

class binaryint
{
    private:
        int ml;             // memory allocated to represent the signed int
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

    // two's complement

        friend vector<int> twos_complement(vector<int> sourcebin);

    // transformation to decimal pattern

        friend long int binarytodecimal(vector<int> source);

    // result in binary pattern

        void result();

    // overflow test

        bool overflowtest();
};

vector<int> twos_complement(vector<int> sourcebin)
{
    int index = sourcebin.size() - 1;

    while (sourcebin[index] != 1)
    {
        index -= 1;
    }

    for (int i = index - 1; i > -1; --i)
    {
        if (sourcebin[i] == 1)
        {
            sourcebin[i] = 0;
        }
        else
        {
            sourcebin[i] = 1;
        }
    }

    return sourcebin;
}

vector<int> decimaltobinary(long int source)
{
    vector<int> result;

    long int abssource = abs(source);

    while (abssource != 0)
    {
        result.insert(result.begin(), abssource % 2);
        abssource = abssource / 2;
    }

    if (source < 0)
        result = twos_complement(result);
        
    return result;
}

long int binarytodecimal(vector<int> source)
{
    long int sum = 0;
    
    for (int i = 1; i < source.size(); ++i)
    {
        sum += source.at(i) * pow(2, source.size() - i - 1);
    }

    sum -= source.at(0) * pow(2, source.size() - 1);

    return sum;
}

bool binaryint::overflowtest()
{
    if (value > (pow(2,ml - 1) - 1) || value < (-pow(2,ml - 1)))
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

        int sizebefore = result.size();

        while (result.size() != ml)
        {
            result.insert(result.begin(), 0);
        } 

        if (binarytodecimal(result) != value)
        {
            replace(result.begin() + (result.size() - sizebefore - 1), result.begin() + (result.size() - sizebefore), 0, 1);
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

    cout << "\n*** SIGNED INT: STORAGE AND REPRESENTATION ***\n" << endl;

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