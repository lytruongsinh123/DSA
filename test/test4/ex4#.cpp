#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n; cin >> n;
    map<int,int> s;
    int a[n+1];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        s[a[i]]++;
    }
    int maxf = 0;
    int number;
    for(auto x : s)
    {
        if(x.second > maxf || (x.second == maxf && x.first < number))
        {
            maxf = x.second;
            number = x.first;
        }
    }
    cout << number << endl;
}