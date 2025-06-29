#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    for(auto c : s)
    {
        if(c == 'A')
        {
            cout << 'T';
        }
        if(c == 'G')
        {
            cout << 'X';
        }
        if(c == 'T')
        {
            cout << 'A';
        }
        if(c == 'X')
        {
            cout << 'G';
        }
    }
}