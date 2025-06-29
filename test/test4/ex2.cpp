#include <iostream>
using namespace std;
int main()
{
    int n; cin >> n;
    int a[1001];
    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = 0; j <= i; j++)
        {
            sum+=a[j];
        }
        cout << sum << " ";
    }
}