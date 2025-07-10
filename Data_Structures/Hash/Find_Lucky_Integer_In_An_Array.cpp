#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int findLucky(vector<int> &arr) {
        vector<int> count(501, 0);
        for (int num : arr) {
            if (num <= 500) {
                count[num]++;
            }
        }

        int luckyInteger = -1;
        for (int i = 1; i <= 500; ++i) {
            if (count[i] == i) {
                luckyInteger = i;
            }
        }
        return luckyInteger;
    }
};
int main()
{
    Solution s;
    std::vector<int> arr = {2, 2, 3, 4};
    int luckyInteger = s.findLucky(arr);
    std::cout << "Lucky Integer: " << luckyInteger << std::endl;
    return 0;
}