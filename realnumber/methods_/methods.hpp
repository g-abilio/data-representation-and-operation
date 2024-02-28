#include <cmath>
#include <vector>

using namespace std;

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

        void setprecision(int m);

        void setvalue(double v);

    // accessor methods

        int getprecision();

        double getvalue();

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

        bool overflowtest32();

    // underflow test (32 bits)

        bool underflowtest32();

    // overflow test (64 bits)

        bool overflowtest64();

    // underflow test (64 bits)

        bool underflowtest64();
};

vector<int> decimaltobinary(int source);

vector<int> decimaltobinary_integral(double source);

vector<int> decimaltobinary_fractional(double source);

vector<int> binaryoffset(vector<int> integral, vector<int> fractional, double source);

void error (string s);