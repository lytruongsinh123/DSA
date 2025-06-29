#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    if (n > m) {
        cout << "NO" << endl;
        return 0;
    }

    // Trường hợp n == m: so sánh toàn bộ
    if (n == m) {
        bool match = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                match = false;
                break;
            }
        }
        cout << (match ? "YES" : "NO") << endl;
        return 0;
    }

    // Tìm đoạn con a[] trong b[]
    for (int i = 0; i <= m - n; i++) {
        bool match = true;
        for (int j = 0; j < n; j++) {
            if (a[j] != b[i + j]) {
                match = false;
                break;
            }
        }
        if (match) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
