#include <cmath>
#include <iostream>
#include "methods.hpp"

using namespace std;

// Exception Handling

void error (string s)
{
    throw runtime_error (s);
}

// Selection of the numerical base and input of number in that base

string inputnumber(char opt)
{
    string number;

    switch (opt)
    {
    case 'd':
        cout << "Type the number in decimal:" << endl;
        cin >> number;

        for (auto i : number)
        {
            bool condit = (i != '0' && i != '1' && i != '2' && i != '3' && i != '4' && i != '5' && i != '6' && i != '7' && i != '8' && i != '9');
            if (condit)
                error ("Error - number is not on decimal base\n");
        }

        break;

    case 'b':
        cout << "Type the number in binary:" << endl;
        cin >> number;

        for (auto i : number)
        {
            bool condit = (i != '0' && i != '1');
            if (condit)
                error ("Error - number is not on binary base\n");
        }

        break;

    case 'h':
        cout << "Type the number in hexadecimal:" << endl;
        cin >> number;

        for (auto i : number)
        {
            bool condit = (i != '0' && i != '1' && i != '2' && i != '3' && i != '4' && i != '5' && i != '6' && i != '7' && i != '8' && i != '9' && i != 'A' && i != 'B' && i != 'C' && i != 'D' && i != 'E' && i != 'F');
            if (condit)
                error ("Error - number is not on hexadecimal base\n");
        }


        break;

    case 'o':
        cout << "Type the number in octal:" << endl;
        cin >> number;

        for (auto i : number)
        {
            bool condit = (i != '0' && i != '1' && i != '2' && i != '3' && i != '4' && i != '5' && i != '6' && i != '7');
            if (condit)
                error ("Error - number is not on octal base\n");
        }

        break;

    default:
        error("Error - invalid numerical system\n");
        break;
    }

    return number;
}

// Conversion of string (containing numbers as char) to number on decimal base

int strtointdec (string numb)
{
    int sum = 0;
    int j = 0;

    for (int i : numb)
    {
        sum += (i - '0') * pow(10, numb.size() - 1 - j);
        ++j;
    }

    return sum;
}

// Binary to Decimal

void btod(string numb)
{
    long int sum = 0;
    int j = 0;

    for (int i : numb)
    {
        sum += (i - '0') * (pow(2, numb.size() - 1 - j));
        ++j;
    }

    cout << sum << endl;
}

// Octal to Decimal

void otod(string numb)
{
    long int sum = 0;
    int j = 0;

    for (int i : numb)
    {
        sum += (i - '0') * (pow(8, numb.size() - 1 - j));
        ++j;
    }

    cout << sum << endl;
}

// Hexadecimal to Decimal

void htod(string numb)
{
    long int sum = 0;
    int j = 0;

    for (int i : numb)
    {
        if (i >= 65 && i <= 70)
        {
            i -= 55;
            sum += (i) * (pow(16, numb.size() - 1 - j));
            ++j;
        }
        else
        {
            sum += (i - '0') * (pow(16, numb.size() - 1 - j));
            ++j;
        }
    }

    cout << sum << endl;
}

// Decimal to Binary

void dtob(string numb)
{
    long int source = strtointdec(numb);
    vector<int> result;

    while (source != 0)
    {
        result.insert(result.begin(), source % 2);
        source = source / 2;
    }

    for (auto i : result)
    {
        cout << i;
    }
        
    cout << endl;
}

// Decimal to Octal

void dtoo(string numb)
{
    long int source = strtointdec(numb);
    vector<int> result;

    while (source != 0)
    {
        result.insert(result.begin(), source % 8);
        source = source / 8;
    }

    for (auto i : result)
    {
        cout << i;
    }
        
    cout << endl;
}

// Decimal to Hexadecimal

void dtoh(string numb)
{
    long int source = strtointdec(numb);
    vector<char> result;

    while (source != 0)
    {
        int rest = source % 16;

        switch (rest)
        {
        case 10:
            result.insert(result.begin(), 'A');
            source = source / 16;
            break;
        
        case 11:
            result.insert(result.begin(), 'B');
            source = source / 16;
            break;

        case 12:
            result.insert(result.begin(), 'C');
            source = source / 16;
            break;

        case 13:
            result.insert(result.begin(), 'D');
            source = source / 16;
            break;

        case 14:
            result.insert(result.begin(), 'E');
            source = source / 16;
            break;

        case 15:
            result.insert(result.begin(), 'F');
            source = source / 16;
            break;

        default:
            char numberchar[sizeof(char) + 1];
            sprintf(numberchar, "%d", rest);
            result.insert(result.begin(), *numberchar);
            source = source / 16;
            break;
        }
    }

    for (auto i : result)
    {
        cout << i;
    }
        
    cout << endl;
}

// Binary to Hexadecimal

void btoh(string numb)
{
        vector<int> vec;

        for (int i = numb.size() - 1; i >= 0; --i)
        {
            int value = (numb.at(i) - '0');
            vec.push_back(value);
        }

        int k = 0;
        for (auto &i : vec)
        {
            if (k == 4)
                k -= 4;

            i = (i * pow(2, k));
            ++k;
        }

        int totalsize = vec.size();
        int parts = totalsize / 4;
        vector<int> result;
        int j = 0;
        
        while (parts > 0)
        {
            int sum = 0;
            for (int i = j; i < j + 4; ++i)
            {
                sum += vec.at(i);
            }
            result.push_back(sum);
            j += 4;
            --parts;
        }

        int sum = 0;
        for (int i = j; i < totalsize; ++i)
        {
            sum += vec.at(i);
        }
        result.push_back(sum);

        for (int i = result.size() - 1; i >= 0; --i)
        {
            switch (result.at(i))
            {
            case 10:
                cout << "A";
                break;
            
            case 11:
                cout << "B";
                break;

            case 12:
                cout << "C";
                break;

            case 13:
                cout << "D";
                break;

            case 14:
                cout << "E";
                break;

            case 15:
                cout << "F";
                break;
            
            default:
                cout << result.at(i);
                break;
            }
        }

        cout << endl;
}

// Binary to Octal

void btoo(string numb)
{
        vector<int> vec;

        for (int i = numb.size() - 1; i >= 0; --i)
        {
            int value = (numb.at(i) - '0');
            vec.push_back(value);
        }

        int k = 0;
        for (auto &i : vec)
        {
            if (k == 3)
                k -= 3;

            i = (i * pow(2, k));
            ++k;
        }

        int totalsize = vec.size();
        int parts = totalsize / 3;
        vector<int> result;
        int j = 0;
        
        while (parts > 0)
        {
            int sum = 0;
            for (int i = j; i < j + 3; ++i)
            {
                sum += vec.at(i);
            }
            result.push_back(sum);
            j += 3;
            --parts;
        }

        int sum = 0;
        for (int i = j; i < totalsize; ++i)
        {
            sum += vec.at(i);
        }
        result.push_back(sum);

        for (int i = result.size() - 1; i >= 0; --i)
        {
            cout << result.at(i);
        }
        cout << endl;
}

// Hexadecimal to Binary

vector<int> htob(string numb)
{
        vector <int> base;

        for (int i = numb.size() - 1; i >= 0; --i)
        {
            switch (numb.at(i))
            {
            case 'A':
                base.push_back(10);
                break;
            
            case 'B':
                base.push_back(11);
                break;

            case 'C':
                base.push_back(12);
                break;

            case 'D':
                base.push_back(13);
                break;

            case 'E':
                base.push_back(14);
                break;

            case 'F':
                base.push_back(15);
                break;

            default:
                base.push_back(numb.at(i) - '0');
                break;
            }
        }

        vector<int> result;

        for (auto i : base)
        {
            int source = i;
            int cont = 0;
            while (source != 0 || cont < 4)
            {
                result.insert(result.begin(), source % 2);
                source = source / 2;
                ++cont;
            }
        }

        return result;
}

// Octal to Binary

vector<int> otob(string numb)
{
        vector <int> base;

        for (int i = numb.size() - 1; i >= 0; --i)
        {
            base.push_back(numb.at(i) - '0');
        }

        vector<int> result;

        for (auto i : base)
        {
            int source = i;
            int cont = 0;
            while (source != 0 || cont < 3)
            {
                result.insert(result.begin(), source % 2);
                source = source / 2;
                ++cont;
            }
        }

        return result;
}

// Hexadecimal to Octal

void htoo(string numb)
{
        vector<int> result = htob(numb);

        vector<int> vec;

        for (int i = result.size() - 1; i >= 0; --i)
        {
            int value = (result.at(i));
            vec.push_back(value);
        }

        int k = 0;
        for (auto &i : vec)
        {
            if (k == 3)
                k -= 3;

            i = (i * pow(2, k));
            ++k;
        }

        int totalsize = vec.size();
        int parts = totalsize / 3;
        vector<int> newresult;
        int j = 0;
        
        while (parts > 0)
        {
            int sum = 0;
            for (int i = j; i < j + 3; ++i)
            {
                sum += vec.at(i);
            }
            newresult.push_back(sum);
            j += 3;
            --parts;
        }

        int sum = 0;
        for (int i = j; i < totalsize; ++i)
        {
            sum += vec.at(i);
        }
        newresult.push_back(sum);

        for (int i = newresult.size() - 1; i >= 0; --i)
        {
            cout << newresult.at(i);
        }
        cout << endl;    
}

// Octal to Hexadecimal

void otoh(string numb)
{
        vector<int> result = otob(numb);

        vector<int> vec;

        for (int i = result.size() - 1; i >= 0; --i)
        {
            int value = (result.at(i));
            vec.push_back(value);
        }

        int k = 0;
        for (auto &i : vec)
        {
            if (k == 4)
                k -= 4;

            i = (i * pow(2, k));
            ++k;
        }

        int totalsize = vec.size();
        int parts = totalsize / 4;
        vector<int> result1;
        int j = 0;
        
        while (parts > 0)
        {
            int sum = 0;
            for (int i = j; i < j + 4; ++i)
            {
                sum += vec.at(i);
            }
            result1.push_back(sum);
            j += 4;
            --parts;
        }

        int sum = 0;
        for (int i = j; i < totalsize; ++i)
        {
            sum += vec.at(i);
        }
        result1.push_back(sum);

        for (int i = result1.size() - 1; i >= 0; --i)
        {
            switch (result1.at(i))
            {
            case 10:
                cout << "A";
                break;
            
            case 11:
                cout << "B";
                break;

            case 12:
                cout << "C";
                break;

            case 13:
                cout << "D";
                break;

            case 14:
                cout << "E";
                break;

            case 15:
                cout << "F";
                break;
            
            default:
                cout << result1.at(i);
                break;
            }
        }

        cout << endl;
}

// Choice between the conversions, using opt1 as the source base and opt2 as the destiny base
// Numb is a string representing the number on the source base (each char on the string is a digit of the source base)

void baseconversion(char opt1, char opt2, string numb)
{
    if (opt1 == opt2)
    {
        cout << "There is no conversion!" << endl;
        cout << numb << endl;
    }

    if (opt1 == 'b' && opt2 == 'd')
    {
        btod(numb);
    }

    if (opt1 == 'o' && opt2 == 'd')
    {
        otod(numb);
    }

    if (opt1 == 'h' && opt2 == 'd')
    {
        htod(numb);
    }

    if (opt1 == 'd' && opt2 == 'b')
    {
        dtob(numb);
    }

    if (opt1 == 'd' && opt2 == 'o')
    {
        dtoo(numb);
    }

    if (opt1 == 'd' && opt2 == 'h') 
    {
        dtoh(numb);
    }

    if (opt1 == 'b' && opt2 == 'h')
    {
        btoh(numb);
    }

    if (opt1 == 'b' && opt2 == 'o')
    {
        btoo(numb);
    }

    if (opt1 == 'h' && opt2 == 'b')
    {
        vector<int> result = htob(numb);

        for (auto i : result)
            cout << i;

        cout << endl;
    }

    if (opt1 == 'h' && opt2 == 'o')
    {
        htoo(numb);
    }

    if (opt1 == 'o' && opt2 == 'b')
    {
        vector<int> result = otob(numb);

        for (auto i : result)
            cout << i;

        cout << endl;
    }

    if (opt1 == 'o' && opt2 == 'h')
    {
       otoh(numb);
    }
}