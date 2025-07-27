#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    int countHillValley(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0; // No hills or valleys possible with less than 3 elements

        int count = 0;
        int i = 1;
        while (i < n - 1)
        {
            int l = i - 1, r = i + 1;
            // Tìm số khác liền kề bên trái
            while (l >= 0 && nums[l] == nums[i])
                l--;
            // Tìm số khác liền kề bên phải
            while (r < n && nums[r] == nums[i])
                r++;
            if (l >= 0 && r < n)
            {
                if (nums[i] > nums[l] && nums[i] > nums[r])
                    count++; // Hill
                else if (nums[i] < nums[l] && nums[i] < nums[r])
                    count++; // Valley
            }
            // Nhảy qua nhóm bằng nhau
            i = r;
        }
        return count;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {2, 4, 1, 1, 6, 5};
    cout << sol.countHillValley(nums) << endl; // Example usage
    return 0;
}
