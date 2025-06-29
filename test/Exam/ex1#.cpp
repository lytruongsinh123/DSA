#include <iostream>
#define MAX 100
using namespace std;

// ✅ Sửa điều kiện: chỉ cần còn 1 ô == 0 → chưa full
bool isfull(int hang, int cot, int a[MAX][MAX])
{
    for (int i = 1; i <= hang; i++)
    {
        for (int j = 1; j <= cot; j++)
        {
            if (a[i][j] == 0)
                return false;
        }
    }
    return true;
}

int main()
{
    int hang, cot;
    cin >> hang >> cot;

    int a[MAX][MAX] = {0};

    int row = 1, col = 1;
    int h = hang, c = cot;

    a[1][0] = 0; // Khởi tạo giá trị đầu tiên để bắt đầu từ 1

    while (true)
    {
        for (int j = col; j <= c; j++)
            a[row][j] = a[row][j - 1] + 1;

        for (int i = row + 1; i <= h; i++)
            a[i][c] = a[i - 1][c] + 1;

        if (h != row)
        {
            for (int j = c - 1; j >= col; j--)
                a[h][j] = a[h][j + 1] + 1;
        }
        if (c != col)
        {
            for (int i = h - 1; i >= row + 1; i--)
                a[i][col] = a[i + 1][col] + 1;
        }

        // ✅ Kiểm tra sau mỗi vòng lặp
        if (isfull(hang, cot, a))
            break;

        row++, col++, h--, c--;
    }

    for (int i = 1; i <= hang; i++)
    {
        for (int j = 1; j <= cot; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
