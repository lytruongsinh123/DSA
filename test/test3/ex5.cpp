#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[i] && a[j] % 2 != 0 && a[i] % 2 != 0)
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