#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Hàm nhân số lớn a (dưới dạng chuỗi) với số nhỏ b (0 < b < 10)
string Nhan(string s, int n) {
    if (n == 0 || s == "0") return "0";

    reverse(s.begin(), s.end());

    int carry = 0;
    string result = "";

    for (char c : s) {
        int digit = c - '0';
        int tich = digit * n + carry;
        result += (tich % 10 + '0');
        carry = tich / 10;
    }

    if (carry > 0) {
        result += (carry + '0');
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string a;
    int b;
    cin >> a >> b;

    string result = Nhan(a, b);
    cout << result << endl;

    return 0;
}
