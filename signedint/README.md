# Storing signed integers

Signed integers, just like unsigned integers, are stored in the computer as a binary pattern, which will be bounded to the memory location used in the storage. However, one bit (the leftmost) is designed to the signal, and the Two's complement is the common method used to represent that.

> ### Two's complement
> 
> * First way:
>
> 1. Beginning on the left of the binary number, go through it until a 
> 1 bit is encountered.
> 2. After that, flip all the bits that are on the left.
> 
> * Second way:
>
> 1. Take the One's complement of the number (flip all the bits).
> 2. Add one (binary addition) to the resulting number.
>
>> * Example: Two's complement of 10110 is 01010.

Using the Two's complement we can represent signed integers using a n bits memory location ranging from $-2^(n-1)$ to $2^(n-1) - 1$. 

* Example: 

Using a 4 bits memory location, we have:

Negative    |   In decimal
---------   |   -----------
1000        |   -8
1001        |   -7
1010        |   -6
1011        |   -5
1100        |   -4
1101        |   -3
1110        |   -2
1111        |   -1

Non negative    |   In decimal
---------   |   -----------
0000        |   0
0001        |   1
0010        |   2
0011        |   3
0100        |   4
0101        |   5
0110        |   6
0111        |   7
