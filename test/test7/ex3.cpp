#include <iostream>
using namespace std;
int** getImage (int nRows, int nCols) 
{
    int** img = new int*[nRows];
    for(int i = 0; i < nRows; i++)
    {
        img[i] = new int[nCols];
    }
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0; j < nCols; j++)
        {
            cin >> img[i][j];
        }
    }
    return img;
}
void fillImage (int** image, int nRows, int nCols, int threshold)
{
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0; j < nCols; j++)
        {
            if(image[i][j] < threshold)
            {
                image[i][j] = 0;
            }
        }
    }
}
void print (int** image, int nRows, int nCols)
{
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0; j < nCols;j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}