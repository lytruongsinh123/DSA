#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n; cin >> n;
    map<int, int> f;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        f[a[i]]++;
    }
    for(int i = 0; i <= 9; i++)
    {
        cout << i << " : " << f[i] << endl;
    }
}