#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    int maximumLength(int *nums, int numsSize)
    {
        int count_even = 0, count_odd = 0;
        for (int i = 0; i < numsSize; i++)
        {
            if (nums[i] % 2 == 0)
                count_even++;
            else
                count_odd++;
        }

        int even_dp = 0, odd_dp = 0;
        for (int i = 0; i < numsSize; i++)
        {
            if (nums[i] % 2 == 0)
                even_dp = (even_dp > odd_dp + 1) ? even_dp : odd_dp + 1;
            else
                odd_dp = (odd_dp > even_dp + 1) ? odd_dp : even_dp + 1;
        }

        int max_same = (count_even > count_odd) ? count_even : count_odd;
        int max_alt = (even_dp > odd_dp) ? even_dp : odd_dp;
        return (max_same > max_alt) ? max_same : max_alt;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80}; // Example input
    int result = sol.maximumLength(nums.data(), nums.size());
    cout << "The maximum length of valid subsequence is: " << result << endl;
    return 0;
}