#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size(), res = 0, t = 0;
        for (int i = 0; i < n; i++) {
            t += endTime[i] - startTime[i];
            int left = i <= k - 1 ? 0 : endTime[i - k];
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            res = max(res, right - left - t);
            if (i >= k - 1) {
                t -= endTime[i - k + 1] - startTime[i - k + 1];
            }
        }
        return res;
    }
};
int main()
{
    Solution sol;
    int eventTime = 10;                // Example value for eventTime
    int k = 3;                         // Example value for k
    vector<int> startTime = {1, 2, 3}; // Example start times
    vector<int> endTime = {4, 5, 6};   // Example end times

    int result = sol.maxFreeTime(eventTime, k, startTime, endTime);
    cout << "Maximum free time: " << result << endl;
    return 0;
}