#include <iostream>
#include <vector>
using namespace std;
bool symetric(int n)
{   
    vector<int> number;
    while(n > 0)
    {
        int k = n % 10;
        number.push_back(k);
        n /= 10;
    }
    int t = (int)number.size();
    for(int i = 0; i < t / 2; i++)
    {
        if(number[i] != number[t - i - 1])
        return false;
    }
    return true;
}
int main()
{
    int n; cin >> n;
    while(n > 0)
    {
        int x, y; cin >> x >> y;
        for(int i = x; i <= y; i++)
        {
            if(symetric(i))
            {
                cout << i << " ";
            }
        }
        n--;
    }
}