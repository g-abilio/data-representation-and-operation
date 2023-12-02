# Storing real numbers

Real numbers are stored in the computer as a binary pattern, which will be bounded to the memory location used in the storage, just like integers.
However, to store real numbers, an unique system is used. The Binary Offset is a system that store real numbers using a memory location of n bits, which are divided between sign, power and mantissa (the fractional part of the real number written as a floating point binary number).
The Binary Offset utilizes the floating point notation:

> ### Floating point notation
> 
> * Number has just one digit on the left of the decimal point.
> * The digit on the left of the decimal point is normalized (different
> of zero).
>> Because of that, we have a number (base of the numerical system) elevated to some power that multiplies another number, similar to scientific notation.
>
> * OBS: The integral part of a floating point number is called the characteristic of the number, while the fractional part is called the mantissa of the number.
> 
> * Example: 42 in floating point notation is 4,2 x 10

A floating point number can have simple precision (32 bits), or double precision (64 bits):

* Simple precision distribution of bits:

Sign    |   Power   |   Mantissa
------  |   ------- |   --------
1 bit   |   8 bits  |   23 bits

* Double precision distribution of bits:

Sign    |   Power   |   Mantissa
------  |   ------- |   --------
1 bit   |   11 bits |   52 bits

So, if we want to store a real number with simple precision, we will have 1 bit to represent the sign, 8 to represent the power, and 23 to represent the mantissa. If we want to store a real number with double precision, we will have 1 bit to represent the sign, 11 to represent the power, and 52 to represent the mantissa.

In short, the computer stores real numbers using the Binary Offset system, that only cares about the sign, power and mantissa of that number written as a binary floating point. It is worth highlighting that this system uses a bias, whose value is 127 for simple precision, and 1023 for double precision. This bias is added to all the possible expoents of the system, so that we can work only with positive powers (in the final representation, the bias is added to the value of the power, e.g. a power of -6 is represented as 121 in simple precision).