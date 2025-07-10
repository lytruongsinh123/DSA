#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
  public:
    string HashMap(int num)
    {
        switch (num)
        {
        case 1:
            return "I";
        case 5:
            return "V";
        case 10:
            return "X";
        case 50:
            return "L";
        case 100:
            return "C";
        case 500:
            return "D";
        case 1000:
            return "M";
        }
        return "";
    }
    string intToRoman(int num)
    {
        string result = "";
        int Map[8] = {5000, 1000, 500, 100, 50, 10, 5, 1};
        int Pivot[7] = {4000, 900, 400, 90, 40, 9, 4};
        for (int i = 1; i < 8; i++)
        {
            int pivot = Pivot[i - 1];
            while(num < pivot && num >= Map[i])
            {
                num = num - Map[i];
                result = result + HashMap(Map[i]);
            }
            while(num >= pivot)
            {
                num = num - pivot;
                result = result + HashMap(Map[i - 1] - pivot) + HashMap(Map[i - 1]);
            }
        }
        return result;
    }
};
int main()
{
    Solution s;
    cout << s.intToRoman(1994) << endl;
}