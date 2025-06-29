// Cho màn hình kích thước M (rộng) x N (cao). M và N là các số dương không vượt quá 1000.

// Tọa độ điểm trái trên của màn hình là (0,0), tọa độ góc phải dưới là (M,N).  Các tọa độ (x, y) đều có x là trục hoành và y là trục tung.

// Có K hình chữ nhật được vẽ lên màn hình đó. Các tọa độ của các hình chữ nhật có thể nằm trong hoặc nằm ngoài màn hình. 

// Đếm số hình chữ nhật có phần diện tích nằm ngoài màn hình. (chỉ tính những hình có diện tích nằm ngoài màn hình > 0)

// Đầu vào: 

// Dòng đầu chứa 3 số M N K.
// K dòng sau, mỗi dòng chứa 4 số nguyên x y w h lần lượt là toạ độ đỉnh trái trên x, y của hình, chiều rộng w, và chiều cao h của hình.

// Đầu ra:

// 1 dòng chứa số hình chữ nhật có phần diện tích nằm ngoài màn hình.

#include <iostream>
using namespace std;

int main() {
    int M, N, K;
    cin >> M >> N >> K;
    int count = 0;

    for (int i = 0; i < K; ++i) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;

        int x2 = x + w;
        int y2 = y + h;

        // Kiểm tra nếu hình chữ nhật vượt ra khỏi màn hình
        if (x < 0 || y < 0 || x2 > M || y2 > N) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
