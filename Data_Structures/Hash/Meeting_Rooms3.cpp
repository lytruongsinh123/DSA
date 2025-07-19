#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
  public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        // Đếm số lần sử dụng mỗi phòng
        vector<int> roomCount(n, 0);

        // Sắp xếp các cuộc họp theo thời gian bắt đầu
        sort(meetings.begin(), meetings.end());

        // Min-heap lưu các phòng đang bận: {thời gian kết thúc, số phòng}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

        // Min-heap lưu các phòng trống: số phòng
        priority_queue<int, vector<int>, greater<>> available;
        for (int i = 0; i < n; ++i)
        {
            available.push(i);
        }

        for (auto &meeting : meetings)
        {
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;

            // Giải phóng các phòng đã xong
            while (!busy.empty() && busy.top().first <= start)
            {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty())
            {
                // Có phòng trống
                int room = available.top();
                available.pop();
                ++roomCount[room];
                busy.push({start + duration, room});
            }
            else
            {
                // Không có phòng trống -> đợi phòng sớm nhất trống
                auto [freeTime, room] = busy.top();
                busy.pop();
                ++roomCount[room];
                busy.push({freeTime + duration, room});
            }
        }

        // Tìm phòng có số lần sử dụng nhiều nhất (ưu tiên số phòng nhỏ hơn)
        int maxCount = 0;
        int resultRoom = 0;
        for (int i = 0; i < n; ++i)
        {
            if (roomCount[i] > maxCount)
            {
                maxCount = roomCount[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};
int main()
{
    Solution sol;
    int n = 3;                                                        // Example number of rooms
    vector<vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3, 8}}; // Example meetings

    int result = sol.mostBooked(n, meetings);
    cout << "Most booked room: " << result << endl;
    return 0;
}