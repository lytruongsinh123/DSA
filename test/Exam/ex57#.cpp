#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool used[1001] = {false};
void backtrack(vector<char>& result, string s, int n) 
{
    if((int) result.size() == n)
    {
        for(int i = 0; i < (int) result.size(); i++)
        {
            cout << result[i];
        }
        cout << endl;
        return;
    }
    for(unsigned int i = 0; i < s.length();i++)
    {
        if(!used[s[i] - 'a'])
        {
            used[s[i] - 'a'] = true;
            result.push_back(s[i]);
            backtrack(result,s,n);
            used[s[i] - 'a'] = false;
            result.pop_back();
        }
    }
}

int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<char> result;
    for(int i = 1; i <= n; i++)
    {
        backtrack(result,s,i);
    }
    return 0;
}
