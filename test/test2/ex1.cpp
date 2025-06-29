#include <iostream>
#include <map>
#include <fstream>
using namespace std;
int main()
{
    string path;
    cin >> path;
    ifstream fin(path);
    map<char, int> a;
    string s;
    while(fin >> s)
    {
        for(auto x : s)
        {
            a[x]++;
        }
    }
    fin.close();
    for(auto x : a)
    {
        cout << x.first << ": " << x.second << endl;
    }
}