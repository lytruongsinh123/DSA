#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    double a[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int k; cin >> k;
    double sum = 0;
    for(int j = 0; j < m; j++)
    {
        sum+= a[k - 1][j];
    }
    cout << fixed << setprecision(2) << sum << endl;
}