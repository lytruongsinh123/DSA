#include <iostream>
using namespace std;
int *merge(int *firstArr, int lenArr1, int *secondArr, int lenArr2)
{
    int *merge = new int[lenArr1 + lenArr2];
    bool increase = (firstArr[0] < firstArr[1]) ? true : false;
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < lenArr1 && j < lenArr2)
    {
        if (increase)
        {
            if (firstArr[i] < secondArr[j])
            {
                merge[k++] = firstArr[i++];
            }
            else
            {
                merge[k++] = secondArr[j++];
            }
        }
        else
        {
            if (firstArr[i] > secondArr[j])
            {
                merge[k++] = firstArr[i++];
            }
            else
            {
                merge[k++] = secondArr[j++];
            }
        }
    }
    
    while (i < lenArr1)
        merge[k++] = firstArr[i++];
    while (j < lenArr2)
        merge[k++] = secondArr[j++];
    
    return merge;
}
int main()
{
    
}