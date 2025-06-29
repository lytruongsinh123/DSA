#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string addBigNumber(string a, string b)
{
    if(a.length() < b.length()) swap(a,b); // Đảm bảo a là chuỗi dài hơn

    // Đảo chuỗi
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string result = "";
    int carry = 0;
    for(size_t i = 0; i < a.length(); i++)
    {
        int digitA = a[i] - '0';
        int digitB = (i < b.length()) ? b[i] - '0' : 0;
        int sum = digitA + digitB + carry;
        result += (sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry) {
        result += (carry + '0');
    }

    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    string a, b;
    cin >> a >> b;

    string sum = addBigNumber(a, b);
    cout << sum << endl;
}