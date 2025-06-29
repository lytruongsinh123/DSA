#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool isPrime(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n; cin >> n;
    int a[1001];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] > a[j] && isPrime(a[i]) && isPrime(a[j]))
            {
                swap(a[i], a[j]);
            }
        }
    }
     for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
