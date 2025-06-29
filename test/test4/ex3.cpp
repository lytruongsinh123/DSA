#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    for(unsigned int i = 0; i < s.length(); i++)
    {
        bool check = false;
        for(unsigned int j = 0; j < i; j++)
        {
            if(s[j] == s[i])
            {
                check = true;
                break;
            }
        }
        if(check == false)
        {
            cout << s[i];
        }
    }
}