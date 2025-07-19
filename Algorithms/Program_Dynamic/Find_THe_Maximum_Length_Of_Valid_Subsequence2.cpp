#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int maximumLength(vector<int> &nums, int k)
    {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int maxLen = 0;

        for (int num : nums)
        {
            for (int j = 0; j < k; ++j)
            {
                int remainder = num % k;
                maxLen = max(maxLen, dp[remainder][j] = dp[j][remainder] + 1);
            }
        }

        return maxLen;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80}; // Example input
    int k = 3;                                              // Example value for k
    int result = sol.maximumLength(nums, k);
    cout << "The maximum length of valid subsequence is: " << result << endl;
    return 0;
}