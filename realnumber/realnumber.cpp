#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>

using namespace std;

// exception handling

void error (string s)
{
    throw runtime_error(s);
}

// class to represent the number in binary floating point

class binary
{
    private:
        int precision;             // memory allocated to represent the number
        double value;              // value that will be stored

    public:

    // constructors

        binary(int m, double v): precision(m), value(v) {};
        binary(): precision(0), value(0) {};

    // mutator methods

        void setprecision(int m)
        {
            precision = m;
        }

        void setvalue(double v)
        {
            value = v;
        }

    // accessor methods

        int getprecision()
        {
            return precision;
        }

        double getvalue()
        {
            return value;
        }

    // normal transformation to binary

        friend vector<int> decimaltobinary(int source);

    // transformation to binary pattern (integral part)

        friend vector<int> decimaltobinary_integral(double source);

    // transformation to binary pattern (fractional part)

        friend vector<int> decimaltobinary_fractional(double source);

    // transforming into the binary offset

        friend vector<int> binaryoffset(vector<int> integral, vector<int> fractiona, double source);

    // result in binary pattern (32 bits)

        void resultin32();

    // result in binary pattern (64 bits)

        void resultin64();

    // overflow test (32 bits)

        bool overflowtest32()
        {
            if (value < ((- (1 - pow(2, -24))) * pow(2, 128)) || value > ((1 - pow(2, -24)) * pow(2, 128)))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    // underflow test (32 bits)

        bool underflowtest32()
        {
            if (value > ((-(1 - pow(2, -1))) * pow(2, -127)) && value < ((1 - pow(2, -1)) * pow(2, -127)))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    // overflow test (64 bits)

        bool overflowtest64()
        {
            if (value < ((- (1 - pow(2, -53))) * pow(2, 1024)) || value > ((1 - pow(2, -53)) * pow(2, 1024)))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    // underflow test (64 bits)

        bool underflowtest64()
        {
            if (value > ((-(1 - pow(2, -1))) * pow(2, -1023)) && value < ((1 - pow(2, -1)) * pow(2, -1023)))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

vector<int> decimaltobinary(int source)
{
    vector<int> result;

    while (source != 0)
    {
        result.insert(result.begin(), source % 2);
        source = source / 2;
    }

    return result;
}

vector<int> decimaltobinary_integral(double source)
{
    long int integral = abs(source) / 1;

    vector<int> characteristics;

    while (integral != 0)
    {
        characteristics.insert(characteristics.begin(), integral % 2);
        integral = integral / 2;
    }

    if (source < 0)
        characteristics.insert(characteristics.begin(), 1);
    else
        characteristics.insert(characteristics.begin(), 0);

    return characteristics;
}

vector<int> decimaltobinary_fractional(double source)
{
    long int integral = abs(source) / 1;
    double fractional = abs(source) - integral;

    vector<int> mantissa;

    while (fractional != 0)
    {
        fractional *= 2;
        if (fractional >= 1)
        {
            mantissa.push_back(1);
            fractional -= 1;
        }
        else
            mantissa.push_back(0);
    }

    return mantissa;
}

// RESULT : [SIGN, CHARACTERISTIC], [MANTISSA]

vector<int> binaryoffset(vector<int> integral, vector<int> fractional, double source)
{
    if (abs(source) >= 1)
    {
        int power = 0;

        for(auto i = integral.end() - 1; i > integral.begin() + 1; --i)
        {
            fractional.insert(fractional.begin(), *i);
            ++power;
        }

        vector<int> result(fractional);
        result.insert(result.begin(), power);
        result.insert(result.begin(), integral[0]);
    
        return result;
    }
    else
    {
        vector<int> result;
        int power = 0;

        for (int i = 0; i < fractional.size(); ++i)
        {
            if (fractional[i] == 1)
            {
                ++power;
                break;
            }
            else
                ++power;
        }
    
        if (power <= fractional.size())
        {
            for (int i = power; i < fractional.size(); ++i)
            {
                result.push_back(fractional[i]);
            }
            result.insert(result.begin(), - power);
            result.insert(result.begin(), integral[0]);
        }
        else
        {
            result.push_back(0);
            result.insert(result.begin(), - power);
            result.insert(result.begin(), integral[0]);
        }
        
        return result;
    }
}

// RESULT : [SIGN, POWER, MANTISSA]

void binary::resultin32()
{
    double valueondec;

    cout << "\nType a number on the decimal base: ";
    cin >> valueondec;
    this->setvalue(valueondec);

    cout << "\nThen, the representation of " << valueondec << " in simple precision is:\n";

    if (this->overflowtest32())
    {
        error ("!! OVERFLOW ALERT !!");
    }

    else if (this->underflowtest32())
    {
        error ("!! UNDERFLOW ALERT !!");
    }

    else
    {
        vector<int> result_i = decimaltobinary_integral(value);
        vector<int> result_f = decimaltobinary_fractional(value);
        vector<int> result = binaryoffset(result_i, result_f, value);

        int power = result[1] + 127;
        vector<int> powervec = decimaltobinary(power);

        while (powervec.size() != 8)
        {
            powervec.insert(powervec.begin(), 0);
        }

        cout << "Sign = " << result[0] << endl;
        cout << "Power = ";
    
        for (auto i : powervec)
            cout << i;

        cout << endl;

        cout << "Mantissa = ";

        vector<int> mantissavec(result);

        mantissavec.erase(mantissavec.begin());
        mantissavec.erase(mantissavec.begin());

        while (mantissavec.size() != 23)
        {
            mantissavec.push_back(0);
        }

        for (auto i : mantissavec)
            cout << i;

        cout << endl;
    }
}

void binary::resultin64()
{
    double valueondec;

    cout << "\nType a number on the decimal base: ";
    cin >> valueondec;
    this->setvalue(valueondec);

    cout << "\nThen, the representation of " << valueondec << " in double precision is:\n";

    if (this->overflowtest64())
    {
        error ("!! OVERFLOW ALERT !!");
    }

    else if (this->underflowtest64())
    {
        error ("!! UNDERFLOW ALERT !!");
    }

    else
    {
        vector<int> result_i = decimaltobinary_integral(value);
        vector<int> result_f = decimaltobinary_fractional(value);
        vector<int> result = binaryoffset(result_i, result_f, value);

        int power = result[1] + 1023;
        vector<int> powervec = decimaltobinary(power);

        while (powervec.size() != 11)
        {
            powervec.insert(powervec.begin(), 0);
        }

        cout << "Sign = " << result[0] << endl;
        cout << "Power = ";
    
        for (auto i : powervec)
            cout << i;

        cout << endl;

        cout << "Mantissa = ";

        vector<int> mantissavec(result);

        mantissavec.erase(mantissavec.begin());
        mantissavec.erase(mantissavec.begin());

        while (mantissavec.size() != 52)
        {
            mantissavec.push_back(0);
        }

        for (auto i : mantissavec)
            cout << i;

        cout << endl;
    }
}

int main()
{
    binary number;
    int memory;
    double valueondec;

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