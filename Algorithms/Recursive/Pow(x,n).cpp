#include <iostream>
using namespace std;
class Solution
{
  public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n == INT_MIN)
        {
            // Xử lý riêng trường hợp INT_MIN
            return 1.0 / (myPow(x, INT_MAX) * x);
        }
        if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }
        double half = myPow(x, n / 2);
        if (n % 2 == 0)
        {
            return half * half;
        }
        else
        {
            return half * half * x;
        }
    }
};
int main()
{
    Solution solution;
    double x = 2.0;
    int n = 10;
    double result = solution.myPow(x, n);
    cout << "Result: " << result << endl; // Output: 1024
    return 0;
}