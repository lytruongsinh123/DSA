#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;cin >> n;
    int a[n];
    map<int, int> f;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        f[a[i]]++;
    }
    bool check = false;
    for(int i = 0; i <= 9; i++)
    {
        if(f[i] == 0)
        {
            check = true;
            cout << i << " ";
        }
    }
    if(check == false) cout << "None";
}