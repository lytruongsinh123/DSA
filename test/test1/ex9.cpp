#include <iostream>
using namespace std;
void printArrow(int n, bool left)
{
    if (!left)
    {
        // Trên
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < (n - i) + 2 * i; j++)
            {
                if (j >= 2 * i)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
        // Dưới
        int k = 1;
        for (int i = n; i < 2 * n - 1; i++)
        {
            for (int j = 0; j < (2 * n - 1) - k; j++)
            {
                if (j >= (2 * n - 2 - 2 * k))
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            k++;
            cout << endl;
        }
    }
    else
    {
        // Trên
        int k = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < (2 * n - 1) - 2 * i; j++)
            {
                if (j >= (2 * n - 1) - 2 * i - k)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            k--;
            cout << endl;
        }
        // Duoi
        int t = 2;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j <= i + t; j++)
            {
                if (j > i)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
            t++;
        }
    }
}