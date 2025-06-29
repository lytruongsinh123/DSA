#include <iostream>
#include <map>
using namespace std;
bool isprime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    if (n < 2) {
        cout << "Khong co thua so nguyen to." << endl;
        return 0;
    }
    map<int, int> a;
    int i = 2;
    while (n > 1) {
        if (isprime(i)) {
            while (n % i == 0) {
                a[i]++;
                n /= i;
            }
        }
        i++;
    }
    for (auto x : a) {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}
