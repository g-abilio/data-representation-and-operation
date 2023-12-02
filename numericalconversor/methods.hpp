#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

void error(string s);           // exception handling

string inputnumber(char opt);   // input of the number on the specific numerical base

int strtointdec (string numb);  // conversion of string to int (decimal base)

void btod(string numb);         // binary to decimal

void otod(string numb);         // octal to decimal

void htod(string numb);         // hexadecimal to decimal
    
void dtob(string numb);         // decimal to binary

void dtoo(string numb);         // decimal to octal

void dtoh(string numb);         // decimal to hexadecimal

void btoh(string numb);         // binary to hexadecimal

void btoo(string numb);         // binary to octal

vector<int> htob(string numb);  // hexadecimal to binary

vector<int> otob(string numb);  // octal to binary

void htoo(string numb);         // hexadecimal to octal

void otoh(string numb);         // octal to hexadecimal

void baseconversion(char opt1, char opt2, string numb);     // function that calls the different conversions


