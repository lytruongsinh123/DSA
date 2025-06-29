#include <iostream>
using namespace std;

const int MAX_VAL = 1000000; // giá trị lớn nhất có thể gặp (điều chỉnh tùy đề)

int main() {
    int n;
    cin >> n;
    int a[n];
    bool mark[MAX_VAL + 1] = {false}; // mảng đánh dấu đã thấy phần tử nào

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (mark[a[i]]) {
            cout << "Yes" << endl;
            return 0;
        }
        mark[a[i]] = true;
    }

    cout << "No" << endl;
    return 0;
}
