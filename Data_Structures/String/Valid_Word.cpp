#include <iostream>
#include <string>
using namespace std;
class Solution
{
  public:
    bool isValid(string word)
    {
        if (word.length() < 3)
            return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char ch : word)
        {
            if (!isalnum(ch))
                return false; // not letter or digit

            if (isalpha(ch))
            {
                char lower = tolower(ch);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                {
                    hasVowel = true;
                }
                else
                {
                    hasConsonant = true;
                }
            }
        }

        return hasVowel && hasConsonant;
    }
};

int main()
{
    Solution sol;
    string word = "example"; // Replace with your test case
    bool result = sol.isValid(word);
    cout << "Is the word valid? " << (result ? "Yes" : "No") << endl;
    return 0;
}