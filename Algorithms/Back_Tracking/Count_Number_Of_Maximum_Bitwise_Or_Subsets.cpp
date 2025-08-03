#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution
{
  public:
    int countMaxOrSubsets(vector<int> &nums) {
        int maxOr = 0;
        int count = 0;

        // Tính toán giá trị OR tối đa
        for (int num : nums) {
            maxOr |= num;
        }

        // Sử dụng bitmask để đếm số lượng tập con có giá trị OR bằng maxOr
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            int currentOr = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    currentOr |= nums[i];
                }
            }
            if (currentOr == maxOr) {
                count++;
            }
        }

        return count;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3}; // Example input
    int result = sol.countMaxOrSubsets(nums);
    cout << "Number of maximum bitwise OR subsets: " << result << endl;
    return 0;
}