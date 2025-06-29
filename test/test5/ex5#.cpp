#include <iostream>
#include <vector>
using namespace std;

void backtrack(int n, int sum, int start, vector<int>& current) {
    if (sum == n) {
        // In ra một dãy thỏa mãn
        for (int num : current) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= n - sum; i++) {
        current.push_back(i);
        backtrack(n, sum + i, i, current); // Cho phép chọn lại i (để có các dãy như 2 2)
        current.pop_back(); // Quay lui
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> current;
    backtrack(n, 0, 1, current);
    return 0;
}
