#include <iostream>
using namespace std;
int** transpose(int** matrix, int nRows, int nCols)
{
    int **trans = new int*[nCols];
    for(int i = 0; i < nCols; i++)
    {
        trans[i] = new int[nRows];
    }
    for(int i = 0; i < nCols; i++)
    {
        for(int j = 0; j < nRows; j++)
        {
            trans[i][j] = matrix[j][i];
        }
    }
    return trans;
}