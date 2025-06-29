#include <iostream>
using namespace std;
bool check(int n)
{
    int k = n;
    while(k > 0)
    {
        int num = k % 10;
        if(num == 0 || n % num != 0)
        {
            return false;
        }
        k /= 10;
    }
    return true;
}
int* selfDividingNumbers(int left, int right, int* returnSize)
{
    int *result = new int[right - left + 1];
    int count = 0;
    for(int i = left; i <= right; i++)
    {
        if(check(i))
        {
            result[count++] = i;
        }
    }
    *returnSize = count;
    return result;
}