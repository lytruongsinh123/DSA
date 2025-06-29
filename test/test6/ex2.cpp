#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
void reverse(char *s)
{
    int n = strlen(s) - 1;
    char *left = s;
    char *right = s + n;
    while (left <= right)
    {
        swap(*left, *right);
        left++;
        right--;
    }
}