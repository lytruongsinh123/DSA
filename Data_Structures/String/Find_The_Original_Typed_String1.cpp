#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int possibleStringCount(string word)
    {
        int n = word.size();
        int res = 0;
        int i = 0;
        while (i < n)
        {
            int j = i;
            while (j < n && word[j] == word[i])
                j++;
            int freq = j - i;
            if (freq > 1)
                res += freq - 1;
            i = j;
        }
        return res + 1;
    }
};
int main()
{
    Solution s;
    string word = "aaabbbccc";
    int count = s.possibleStringCount(word);
    cout << "Possible typed strings: " << count << endl;
    return 0;
}