#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
  public:
    long long minimumDifference(vector<int> &nums)
    {
        int n3 = nums.size();
        int n = n3 / 3;

        vector<long long> leftMin(n3, 0), rightMin(n3, 0);

        // Max heap for left part (to remove largest and keep n smallest)
        priority_queue<int> maxHeap;
        long long leftSum = 0;
        for (int i = 0; i < n3; ++i)
        {
            maxHeap.push(nums[i]);
            leftSum += nums[i];
            if (maxHeap.size() > n)
            {
                leftSum -= maxHeap.top();
                maxHeap.pop();
            }
            if (i >= n - 1)
            {
                leftMin[i] = leftSum;
            }
        }

        // Min heap for right part (to remove smallest and keep n largest)
        priority_queue<int, vector<int>, greater<>> minHeap;
        long long rightSum = 0;
        for (int i = n3 - 1; i >= 0; --i)
        {
            minHeap.push(nums[i]);
            rightSum += nums[i];
            if (minHeap.size() > n)
            {
                rightSum -= minHeap.top();
                minHeap.pop();
            }
            if (i <= n3 - n)
            {
                rightMin[i] = rightSum;
            }
        }

        // Find minimum difference between left and right segment sums
        long long result = LLONG_MAX;
        for (int i = n - 1; i <= n3 - n - 1; ++i)
        {
            result = min(result, leftMin[i] - rightMin[i + 1]);
        }

        return result;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {3, 9, 7, 3}; // Example input
    long long result = sol.minimumDifference(nums);

    cout << "The minimum difference is: " << result << endl;
    return 0;
}