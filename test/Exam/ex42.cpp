#include <iostream>
#define MAX 100
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    int a[MAX][MAX] = {0};
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] > a[i - 1][j] && 
               a[i][j] > a[i + 1][j] &&
               a[i][j] > a[i][j - 1] &&
               a[i][j] > a[i][j + 1])
            {
                count++;
            }
        }
    }
    cout << count << endl;
}