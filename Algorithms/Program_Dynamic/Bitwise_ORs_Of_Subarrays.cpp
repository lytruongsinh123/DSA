#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution
{
  public:
    int subarrayBitwiseORs(vector<int> &arr)
    {
        int n = arr.size();
        unordered_set<int> res, cur, prev;
        for (int i = 0; i < n; ++i)
        {
            cur.clear();
            cur.insert(arr[i]);
            for (int x : prev)
                cur.insert(x | arr[i]);
            for (int x : cur)
                res.insert(x);
            prev = cur;
        }
        return res.size();
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3}; // Example input
    int result = sol.subarrayBitwiseORs(arr);
    cout << "Number of unique bitwise ORs of subarrays: " << result << endl;
    return 0;
}