#include <iostream>
#include <string>
#include <algorithm> // dùng reverse
using namespace std;

int main() {
    string s;
    cin >> s;

    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());

    string palindrome = s + reversed_s;
    cout << palindrome << endl;

    return 0;
}
