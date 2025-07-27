#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    string makeFancyString(string s)
    {
        if (s.length() < 3)
            return s;

        int writePos = 2;
        for (int i = 2; i < s.length(); ++i)
        {
            if (s[i] != s[writePos - 1] || s[i] != s[writePos - 2])
            {
                s[writePos++] = s[i];
            }
        }

        return s.substr(0, writePos);
    }
};
int main()
{
    Solution solution;
    string s = "leeetcode";
    string result = solution.makeFancyString(s);
    cout << "Fancy String: " << result << endl;
    return 0;
}