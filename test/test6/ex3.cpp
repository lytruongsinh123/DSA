#include <iostream>
#include <algorithm>
using namespace std;
void inputArray(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        cin >> *(arr + i);
    }
}
int findSecondLargest(int *arr, int size)
{
    if(size == 1)
    {
        return -1;
    }
    for(int i = 0; i < size - 1; i++)
    {
        int minidx = i;
        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] > arr[minidx])
            {
                minidx = j;
            }
        }
        swap(arr[i], arr[minidx]);
    }
    return arr[1];
}