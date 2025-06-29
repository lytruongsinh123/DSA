#include <iostream>
#include <algorithm> // để dùng min và max
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int lonNhat = max({a, b, c});
    int nhoNhat = min({a, b, c});
    int trungGian = a + b + c - lonNhat - nhoNhat;

    cout << lonNhat << " " << trungGian << " " << nhoNhat << endl;

    return 0;
}
