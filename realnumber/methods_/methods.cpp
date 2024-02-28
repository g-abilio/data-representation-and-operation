#include <cmath>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "methods.hpp"

void binary::setprecision(int m)
{
    precision = m;
};

void binary::setvalue(double v)
{
    value = v;
}

int binary::getprecision()
{
    return precision;
}

double binary::getvalue()
{
    return value;
}

bool binary::overflowtest32()
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

bool binary::underflowtest32()
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

bool binary::overflowtest64()
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

bool binary::underflowtest64()
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

void error (string s)
{
    throw runtime_error(s);
}