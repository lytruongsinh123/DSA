#include <iostream>
#include <iomanip>
using namespace std;
double A[10];
void input()
{
    for(int i = 0 ;i < 6; i++)
    {
        cin >> A[i];
    }
}
double Caculate()
{
    return ((A[0] + A[1] + A[2]) + 2*(A[3] + A[4]) + 3*A[5] ) / 10.0;
}
int main()
{
    input();
    cout << fixed << setprecision(2) << Caculate() ;
}