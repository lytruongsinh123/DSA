#include <iostream>
using namespace std;
bool* isHigher (int* arr, int num, int thres)
{
    bool* check = new bool[num];
    for(int i = 0; i < num; i++)
    {
        if(arr[i] >= thres)
        {
            check[i] = true;
        }
        else
        {
            check[i] = false;
        }
    }
    return check;
}