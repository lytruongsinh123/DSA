#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Student {
    int id;
    double T;
    double L;
    double A;
    double TB;

    // Đúng thứ tự khai báo
    Student(int id, double T, double L, double A)
        : id(id), T(T), L(L), A(A) {
        TB = (T + L + A) / 3.0;
    }
};

// Kiểm tra điểm có hợp lệ không
bool checkvalid(const Student& a) {
    return (a.T >= 0 && a.T <= 10 &&
            a.L >= 0 && a.L <= 10 &&
            a.A >= 0 && a.A <= 10);
}

int main() {
    int n;
    cin >> n;

    vector<Student> a;
    for (int i = 0; i < n; i++) {
        double T, L, A;
        cin >> T >> L >> A;
        Student S(i + 1, T, L, A);
        a.push_back(S);
    }

    // Kiểm tra hợp lệ
    for (const auto& s : a) {
        if (!checkvalid(s)) {
            cout << "invalid" << endl;
            return 0;
        }
    }

    // Sắp xếp theo điểm Toán
    cout << "Theo diem mon Toan:" << endl;
    cout << "SV Toan Ly Anh" << endl;
    sort(a.begin(), a.end(), [](const Student& a, const Student& b) {
        return a.T > b.T;
    });
    for (const auto& s : a) {
        cout << s.id << " " << fixed << setprecision(1) << s.T << " " << s.L << " " << s.A << endl;
    }

    cout << endl;

    // Sắp xếp theo điểm Anh
    cout << "Theo diem mon Anh:" << endl;
    cout << "SV Toan Ly Anh" << endl;
    sort(a.begin(), a.end(), [](const Student& a, const Student& b) {
        return a.A > b.A;
    });
    for (const auto& s : a) {
        cout << s.id << " " << fixed << setprecision(1) << s.T << " " << s.L << " " << s.A << endl;
    }

    cout << endl;

    // Sắp xếp theo điểm Trung bình
    cout << "Theo diem trung binh:" << endl;
    cout << "SV TB Toan Ly Anh" << endl;
    sort(a.begin(), a.end(), [](const Student& a, const Student& b) {
        return a.TB > b.TB;
    });
    for (const auto& s : a) {
        cout << s.id << " " << fixed << setprecision(1) << s.TB << " " << s.T << " " << s.L << " " << s.A << endl;
    }

    return 0;
}
