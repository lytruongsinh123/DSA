#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        // Bubble sort cơ bản
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - 1 - i; ++j)
            {
                if (nums[j] > nums[j + 1])
                {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
};
int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    Solution s;
    s.sortColors(nums);

    for (int num : nums)
    {
        cout << num << " ";
    }

    return 0;
}