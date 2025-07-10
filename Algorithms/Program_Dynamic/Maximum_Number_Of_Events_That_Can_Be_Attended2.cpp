#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    int maxValue(vector<vector<int>> &events, int k)
    {
        int n = events.size();
        // Sắp xếp các sự kiện theo ngày kết thúc
        sort(events.begin(), events.end(), [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

        // dp[i][j] là giá trị tối đa có thể đạt được với i sự kiện và j sự kiện đã chọn
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // Tạo mảng lưu ngày kết thúc để binary search
        vector<int> ends(n);
        for (int i = 0; i < n; ++i)
            ends[i] = events[i][1];
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                // Không chọn sự kiện i
                dp[i][j] = dp[i - 1][j];
                // Chọn sự kiện i
                // Tìm sự kiện gần nhất kết thúc trước khi events[i-1] bắt đầu
                int prev =
                    lower_bound(ends.begin(), ends.begin() + i - 1, events[i - 1][0], [](int endDay, int startDay) { return endDay < startDay; }) -
                    ends.begin() - 1;
                dp[i][j] = max(dp[i][j], dp[prev + 1][j - 1] + events[i - 1][2]);
            }
        }

        return dp[n][k];
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> events = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}};
    int k = 2; // Example value for k
    int result = sol.maxValue(events, k);
    cout << "Maximum value of events: " << result << endl;
    return 0;
}