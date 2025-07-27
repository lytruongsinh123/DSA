#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution
{
  public:
    int maximumGain(string s, int x, int y)
    {
        // Greedy: ưu tiên xóa substring có điểm cao hơn trước
        if (x < y)
        {
            swap(x, y);
            // Đổi vai trò 'a' và 'b' nếu "ba" có điểm cao hơn "ab"
            for (char &c : s)
            {
                if (c == 'a')
                    c = 'b';
                else if (c == 'b')
                    c = 'a';
            }
        }

        int score = 0;

        // Xóa "ab" trước (điểm cao hơn)
        string temp = "";
        for (char c : s)
        {
            if (!temp.empty() && temp.back() == 'a' && c == 'b')
            {
                temp.pop_back();
                score += x;
            }
            else
            {
                temp += c;
            }
        }

        // Xóa "ba" sau (điểm thấp hơn)
        string result = "";
        for (char c : temp)
        {
            if (!result.empty() && result.back() == 'b' && c == 'a')
            {
                result.pop_back();
                score += y;
            }
            else
            {
                result += c;
            }
        }

        return score;
    }
};
int main()
{
    Solution sol;
    string s = "aabbcc";
    int x = 1; // Example value for x
    int y = 2; // Example value for y
    int result = sol.maximumGain(s, x, y);
    cout << "Maximum gain: " << result << endl;
    return 0;
}