#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double SumSqrt(double n)
{
    if(n == 1.0) return 1;
    return sqrt(n + SumSqrt(n - 1));
}
int main()
{
    double n; cin >> n;
    cout << fixed << setprecision(2) << SumSqrt(n) << endl;
}
