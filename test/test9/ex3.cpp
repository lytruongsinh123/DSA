#include <iostream>
#include <vector>
using namespace std;
void gen(vector<int> & result, int n)
{
    if((int) result.size() == n)
    {
        for(int i = 0; i < n; i++)
        {
            cout << result[i];
        }
        cout << endl;
        return;
    }
    for(int i = 0; i <= 1; i++)
    {
        result.push_back(i);
        gen(result, n);
        result.pop_back();
    }
}
int main()
{
    int n; cin >> n;
    vector<int> result;
    gen(result, n);
}