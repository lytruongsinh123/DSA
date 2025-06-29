#include <iostream>
#include <iomanip>
using namespace std;
double cn;
double cc;
void input()
{
    cin >> cn >> cc;
}
int main()
{
    input();
    cout << fixed << setprecision(2) << cn / (cc*cc) << endl;
}