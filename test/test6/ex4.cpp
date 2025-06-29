#include <iostream>
using namespace std;
double* getSquare (double number)
{
    double *result = new double;
    *result = number*number;
    return result;
}