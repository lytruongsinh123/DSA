#include <cmath>
#include <iostream>
#include <string>

using namespace std;
struct Complex
{
    int a;
    int b;
    Complex() : a(0), b(0){};
    Complex(int a_, int b_)
    {
        a = a_;
        b = b_;
    }
    double abs()
    {
        double result = sqrt(pow(a, 2) + pow(b, 2));
        return result;
    }
    void print()
    {
        if (a != 0)
        {
            if (b > 0)
                cout << a << "+" << ((b == 1) ? "" : to_string(b)) << "i" << endl;
            if (b < 0)
                cout << a << ((b == -1) ? "-" : to_string(b)) << "i" << endl;
            if (b == 0)
                cout << a << endl;
        }
        if (a == 0)
        {
            if (b > 0)
                cout << ((b == 1) ? "" : to_string(b)) << "i" << endl;
            if (b < 0)
                cout << ((b == -1) ? "-" : to_string(b)) << "i" << endl;
            if (b == 0)
                cout << endl;
        }
    }
};
Complex add(Complex a, Complex b)
{
    Complex result;
    result.a = a.a + b.a;
    result.b = a.b + b.b;
    return result;
}