#include <iostream>
#include <cmath>
using namespace std;

// Hàm tính ước chung lớn nhất
int gcd(int a, int b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;

    if (b == 0) {
        cout << "Invalid fraction (mau so = 0)" << endl;
        return 0;
    }

    int g = gcd(a, b);
    a /= g;
    b /= g;

    // Đảm bảo mẫu số dương
    if (b < 0) {
        a = -a;
        b = -b;
    }

    // In kết quả
    if (b == 1) {
        cout << a << endl;
    } else {
        cout << a << "/" << b << endl;
    }

    return 0;
}
