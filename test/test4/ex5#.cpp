// Cho dãy số A có n phần tử và một số nguyên k,
//     chia dãy A thành k mảng con khác rỗng sao cho tổng lớn nhất của bất kỳ mảng con nào là nhỏ
//         nhất.

//     Trả về giá trị tối thiểu của tổng lớn nhất có thể có trong các cách chia.

// left : maxsum với chia n đoạn : là giá trị lớn nhất của mảng
// right : maxsum với chia mảng thành 1 đoạn : là giá trị tổng tất cả phẩn tử mảng
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int splitArray(vector<int>& A, int k) {
    int left = *max_element(A.begin(), A.end());
    int right = accumulate(A.begin(), A.end(), 0);
    while (left < right) {
        int mid = (left + right) / 2;
        int cnt = 1, sum = 0;
        for (int x : A) {
            if (sum + x > mid) {
                cnt++;
                sum = x;
            } else {
                sum += x;
            }
        }
        if (cnt > k) left = mid + 1;
        else right = mid;
    }
    return left;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        a.push_back(x);
    }
    cout << splitArray(a,k) << endl;
}