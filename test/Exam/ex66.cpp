#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            if (i != 0)
            {
                if (j == i || j == -i + 2 * (n - 1))
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}