#include <iostream>
#include <map>
using namespace std;
bool phanbiet(int n)
{
    map<int, int> a;
    while(n > 0)
    {
        int k = n % 10;
        a[k]++;
        n /= 10;
    }
    for(auto x : a)
    {
        if(x.second >= 2)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int l, r; cin >> l >> r;
    for(int i = l; i <= r; i++)
    {
        if(phanbiet(i))
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}