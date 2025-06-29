#include <iostream>
#include <cmath>
#include <iomanip>
#define MAX 1001
using namespace std;
int n;
double a[MAX];
void input()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
double average()
{
    double sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum+=a[i];
    }
    return sum / n;
}
double variance()
{
    double sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum+=pow((a[i] - average()), 2);
    }
    return sum / n;
}
int main()
{
    input();
    cout << fixed << setprecision(2) << variance() << endl;
}