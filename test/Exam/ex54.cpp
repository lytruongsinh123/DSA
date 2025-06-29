#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e6 + 1;
vector<bool> is_prime(MAX, true);

// Sàng Eratosthenes
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    sieve(); // Đánh dấu các số nguyên tố trước

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    for (int x : a) {
        if (is_prime[x]) cout << x << " ";
    }

    cout << endl;
    return 0;
}
