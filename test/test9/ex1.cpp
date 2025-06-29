#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool v[1001] = {false};
void gen(vector<int> & result, int a[], int n)
{ 
    if(n == (int)result.size())
    {
        for(int i = 0; i < (int) result.size() ;i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(!v[a[i]])
        {
            v[a[i]] = true;
            result.push_back(a[i]);
            gen(result, a, n);
            v[a[i]] = false;
            result.pop_back();
        }
    }
}
int main()
{
    int n; cin >> n;
    int a[1001];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+ n, less<int>());
    vector<int> result;
    gen(result, a, n);
}