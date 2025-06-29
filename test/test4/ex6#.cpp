#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[MAX];
    int dp[MAX];
    int pr[MAX];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i] = 1;
        pr[i] = -1;
    }
    int ei = 0, maxl = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] >= a[j] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                pr[i] = j;
            }
        }
        if (dp[i] > maxl)
        {
            maxl = dp[i];
            ei = i;
        }
    }
    vector<int> list;
    while (ei != -1)
    {
        list.push_back(a[ei]);
        ei = pr[ei];
    }
    for (int i = list.size() - 1; i >= 0; i--)
    {
        cout << list[i] << " ";
    }
}