// Cho số nguyên dương N
//  lẻ. Ma trận kì ảo kích thước N×N
//  là bảng vuông chứa các số từ 1
//  đến N×N
//  có tính chất như sau: mỗi số xuất hiện đúng một lần, tổng các số trên mỗi hàng, cột, đường chéo chính, đường chéo phụ đều bằng nhau.
// Viết chương trình in ra ma trận kỳ ảo kích thước N×N
//  với N
//  cho trước.

// Đầu vào
// Đầu vào từ bàn phím chứa duy nhất số nguyên dương N
//  lẻ.

// Đầu ra
// In ra màn hình ma trận kỳ ảo kích thước N×N
// . Phân tách các số trên mỗi dòng bằng một dấu cách duy nhất.
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    if (N % 2 == 0) {
        cout << "Chi chi ho tro N le.\n";
        return 1;
    }

    // Khởi tạo ma trận NxN toàn số 0
    vector<vector<int>> magic(N, vector<int>(N, 0));

    int i = 0, j = N / 2; // Bắt đầu tại hàng đầu tiên, cột giữa

    for (int num = 1; num <= N * N; ++num) {
        magic[i][j] = num;
        int ni = (i - 1 + N) % N; // Lên 1 hàng (vòng lại nếu cần)
        int nj = (j + 1) % N;     // Sang phải 1 cột (vòng lại nếu cần)

        if (magic[ni][nj] != 0) {
            i = (i + 1) % N; // Nếu ô đã điền, xuống 1 hàng
        } else {
            i = ni;
            j = nj;
        }
    }

    // In ma trận
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            cout << magic[row][col];
            if (col != N - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
