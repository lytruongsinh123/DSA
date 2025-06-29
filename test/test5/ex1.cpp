#include <iostream>
using namespace std;
void rotate(int k, int a[], int n)
{
    int lan = 0;
    while(lan < k)
    {
        int key = a[n - 1];
        for(int i = n; i >= 1; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = key;
        lan++;
    }
}
int main()
{
    int n, k; cin >> n >> k;
    int a[10001];
    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    rotate(k,a,n);
     for(int i = 0; i < n; i ++)
    {
        cout << a[i] << " ";
    }
}