#include <iostream>
using namespace std;

int main() {
    int M, N, K;
    cin >> M >> N >> K;

    int max_right = -1;
    int count = 0;

    for (int i = 0; i < K; ++i) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;

        int right = x + w;

        // Bỏ qua các hình có mép phải >= M
        if (right >= M) continue;

        // Cập nhật hình xa nhất bên phải trong phạm vi cho phép
        if (right > max_right) {
            max_right = right;
            count = 1;
        } else if (right == max_right) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
