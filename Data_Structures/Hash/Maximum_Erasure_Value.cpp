#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
  public:
    int maximumUniqueSubarray(vector<int> &nums) {
        unordered_map<int, int> lastIndex;
        int maxSum = 0, currentSum = 0, start = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (lastIndex.count(nums[i]) && lastIndex[nums[i]] >= start) {
                start = lastIndex[nums[i]] + 1;
                currentSum = accumulate(nums.begin() + start, nums.begin() + i + 1, 0);
            } else {
                currentSum += nums[i];
            }
            lastIndex[nums[i]] = i;
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {4, 2, 4, 5, 6};
    int result = solution.maximumUniqueSubarray(nums);
    cout << "Maximum Unique Subarray Sum: " << result << endl;
    return 0;
}