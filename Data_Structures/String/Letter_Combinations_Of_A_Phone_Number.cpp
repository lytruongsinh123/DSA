#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  private:
    vector<string> result;

  public:
    string Hash(char number)
    {
        switch (number)
        {
        case '2':
            return "abc";
        case '3':
            return "def";
        case '4':
            return "ghi";
        case '5':
            return "jkl";
        case '6':
            return "mno";
        case '7':
            return "pqrs";
        case '8':
            return "tuv";
        case '9':
            return "wxyz";
        }
        return "";
    }
    void Gen(string digits, string words, int index)
    {
        if (digits.length() == words.length())
        {
            result.push_back(words);
            return;
        }
        string digit = Hash(digits[index]);
        for (int j = 0; j < digit.length(); j++)
        {
            int a = index + 1;
            Gen(digits, words + digit[j], a);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if(digits.length() == 0) return result;
        Gen(digits, "", 0);
        return result;
    }
};
int main()
{
    Solution s;
    string digits = "234";
    vector<string> result = s.letterCombinations(digits);
    for (const string &combination : result)
    {
        cout << combination << " ";
    }
    cout << endl;
    return 0;
}