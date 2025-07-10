#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int romanToInt(string s)
    {
        // Sử dụng map để ánh xạ ký tự sang giá trị
        static const int roman[256] = {};
        static bool initialized = false;
        static int r[256];
        if (!initialized)
        {
            r['I'] = 1;
            r['V'] = 5;
            r['X'] = 10;
            r['L'] = 50;
            r['C'] = 100;
            r['D'] = 500;
            r['M'] = 1000;
            initialized = true;
        }
        int total = 0;
        int prev = 0;
        // Duyệt ngược chuỗi, cộng hoặc trừ dựa vào giá trị trước đó
        for (int i = s.size() - 1; i >= 0; --i)
        {
            int curr = r[s[i]];
            if (curr < prev)
                total -= curr;
            else
                total += curr;
            prev = curr;
        }
        return total;
    }
};
int main()
{
    Solution sol;
    string s = "MCMXCIV"; // Example Roman numeral
    int result = sol.romanToInt(s);
    cout << "The integer value of the Roman numeral " << s << " is: " << result << endl;
    return 0;
}