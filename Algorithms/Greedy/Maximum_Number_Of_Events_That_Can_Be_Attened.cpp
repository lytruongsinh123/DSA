#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// Tư duy Tham lam ở đây là gì ? Vì mỗi ngày chỉ được tham gia một sự kiện,
// nên ta nên ưu tiên tham gia sự kiện nào kết thúc sớm nhất trước.Điều này giúp "giải phóng" các ngày sớm để tham gia nhiều sự kiện khác về sau.

// Chiến lược Greedy cụ thể
// : Sắp xếp các sự kiện theo ngày bắt đầu(startDay).

//  Duyệt qua từng ngày từ 1 đến max(endDay):

//  Thêm vào hàng đợi các sự kiện có startDay <= current_day.

//  Bỏ qua các sự kiện đã hết hạn(endDay < current_day).

// Tham gia sự kiện có endDay sớm nhất(dùng hàng đợi ưu tiên / min - heap).

// Đếm số sự kiện đã tham gia.

class Solution
{
  public:
    int maxEvents(vector<vector<int>> &events)
    {
        // Sắp xếp các sự kiện theo ngày bắt đầu
        sort(events.begin(), events.end());
        int n = events.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int res = 0, day = 1, i = 0;
        // Tìm ngày kết thúc lớn nhất
        int maxDay = 0;
        for (const auto &event : events)
            maxDay = max(maxDay, event[1]);
        // Duyệt từng ngày
        for (day = 1; day <= maxDay; ++day)
        {
            // Thêm các sự kiện bắt đầu hôm nay vào heap
            while (i < n && events[i][0] == day)
            {
                minHeap.push(events[i][1]);
                ++i;
            }
            // Loại bỏ các sự kiện đã hết hạn
            while (!minHeap.empty() && minHeap.top() < day)
                minHeap.pop();
            // Nếu còn sự kiện, tham gia sự kiện kết thúc sớm nhất
            if (!minHeap.empty())
            {
                minHeap.pop();
                ++res;
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}};
    cout << s.maxEvents(events) << endl; // Example usage
    return 0;
}