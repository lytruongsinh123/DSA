#include <iostream>
#include <algorithm>
using namespace std;
bool find(int a[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    while(left <= right)
    {
        int mid = (left + right) /2;
        if(a[mid] == x) return true;
        else
        {
            if(a[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return false;
}
int main()
{
    int n, x; cin >> n >> x;
    int a[100000];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, less<int>());
    if(find(a, n, x)) cout << "YES";
    else cout << "NO";
}