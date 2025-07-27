#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
class Solution
{
  public:
    long long maxSubarrays(int n, vector<vector<int>> &conflictingPairs)
    {
        int m = conflictingPairs.size();
        for (int i = 0; i < m; i++)
        {
            if (conflictingPairs[i][0] > conflictingPairs[i][1])
                swap(conflictingPairs[i][0], conflictingPairs[i][1]);
        }
        sort(conflictingPairs.begin(), conflictingPairs.end(), [](auto &x, auto &y) { return x[1] != y[1] ? x[1] < y[1] : x[0] < y[0]; });
        int j = 0;
        int mxlb = 1, curlb = 1, cur = -1;
        vector<ll> res(m, 0);
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            while (j < m && conflictingPairs[j][1] <= i)
            {
                if (cur == -1)
                {
                    if (mxlb <= conflictingPairs[j][0])
                    {
                        curlb = conflictingPairs[j][0];
                        cur = j;
                    }
                }
                else if (conflictingPairs[j][0] < curlb)
                {
                    mxlb = max(mxlb, conflictingPairs[j][0] + 1);
                }
                else if (conflictingPairs[j][0] == curlb)
                {
                    mxlb = curlb + 1;
                    cur = -1;
                }
                else
                {
                    mxlb = curlb + 1;
                    curlb = conflictingPairs[j][0];
                    cur = j;
                }
                j++;
            }
            if (cur != -1)
            {
                res[cur] += curlb - mxlb + 1;
            }
            if (cur == -1)
                ans += i - mxlb + 1;
            else
                ans += i - curlb;
        }
        ll resmx = 0;
        for (int i = 0; i < m; i++)
        {
            resmx = max(resmx, res[i]);
        }
        return ans + resmx;
    }
};
int main()
{
    Solution sol;
    int n = 5;                                                       // Example size of the array
    vector<vector<int>> conflictingPairs = {{1, 2}, {3, 4}, {2, 5}}; // Example conflicting pairs

    long long result = sol.maxSubarrays(n, conflictingPairs);
    cout << "Maximum number of subarrays after removing one conflicting pair: " << result << endl;
    return 0;
}