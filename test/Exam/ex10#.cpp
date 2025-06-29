#include <iostream>
#include <vector>
using namespace std;
void printPascal(int n, vector<int>& result)
{
    for(int i = 0; i < result.size(); i++)
    {
        if(result[i] != 0)
        {
            cout << result[i] << " ";
        }
        
    }
    cout << endl;
    if(n == 0) return;
    for(int i = result.size() - 1; i >= 1; i--)
    {
        result[i] = result[i] + result[i - 1];
    }
    result.push_back(0);
    printPascal(n - 1,result);
}
int main()
{
    int n; cin >> n;
    vector<int> result;
    result.push_back(0);
    result.push_back(1);
    result.push_back(0);
    printPascal(n, result);
}