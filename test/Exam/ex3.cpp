#include <iostream>
#include <string>
#define MAX 100
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    char a[MAX][MAX] = {'.'};
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    
    string b[MAX][MAX] = {" "};
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] == '*')
            {
                b[i][j] = "*";
            }
            else
            {
                int count = 0;
                if(a[i][j - 1] == '*') count++;
                if(a[i][j + 1] == '*') count++;
                if(a[i + 1][j] == '*') count++;
                if(a[i - 1][j] == '*') count++;
                if(a[i + 1][j - 1] == '*') count++;
                if(a[i + 1][j + 1] == '*') count++;
                if(a[i - 1][j - 1] == '*') count++;
                if(a[i - 1][j + 1] == '*') count++;
                b[i][j] = to_string(count);
            }
        }
    }
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1;j <= m; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}