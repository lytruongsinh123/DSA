#include <iostream>
#include <map>
#include <sstream>

using namespace std;
int main()
{
    string line;
    getline(cin, line); // đọc nguyên dòng chứa các số nguyên

    istringstream iss(line);
    map<int, int> f;

    int x;
    while (iss >> x) {
        f[x]++;
    }
    int maxf = 0;
    int number;
    for(auto x : f)
    {
        if(x.second > maxf || (x.second == maxf && x.first < number))
        {
            maxf = x.second;
            number = x.first;
        }
    }
    cout << number << endl;
}