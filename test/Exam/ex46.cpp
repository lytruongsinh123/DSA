// Tìm các số nguyên dương a, b, c, d và e sao cho:
// a^5+b^5+c^5+d^5=e^5
// Viết chương trình nhận vào từ bàn phím tham số N và tìm tất cả các lời giải với a, b, c, d và e nhỏ hơn hoặc bằng N. In các lời giải ra màn hình.
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

long long power5(int x) {
    return 1LL * x * x * x * x * x;
}

int main() {
    int N;
    cin >> N;

    // Bảng tra e^5 -> e
    unordered_map<long long, int> pow5_map;
    for (int e = 1; e <= N; ++e) {
        pow5_map[power5(e)] = e;
    }

    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            for (int c = 1; c <= N; ++c) {
                for (int d = 1; d <= N; ++d) {
                    long long sum = power5(a) + power5(b) + power5(c) + power5(d);
                    if (pow5_map.count(sum)) {
                        int e = pow5_map[sum];
                        if (e <= N) {
                            cout << "a=" << a << ", b=" << b << ", c=" << c
                                 << ", d=" << d << ", e=" << e << endl;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
