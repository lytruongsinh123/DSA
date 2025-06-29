#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string decimal_to_binary(long number) {
    if (number == 0) return "0";

    string result = "";
    while (number > 0) {
        result += (number % 2) + '0'; // thêm bit cuối vào chuỗi
        number /= 2;
    }

    reverse(result.begin(), result.end()); // đảo ngược chuỗi để có kết quả đúng
    return result;
}
int main()
{
    cout << decimal_to_binary(118);
}
