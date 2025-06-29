#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* next;
};

void printReverse(Node* head, int k) {
    vector<int> vals;
    Node* current = head;

    // Lưu k phần tử đầu tiên vào vector
    for (int i = 0; i < k && current != nullptr; ++i) {
        vals.push_back(current->value);
        current = current->next;
    }

    // In ngược lại
    for (int i = k - 1; i >= 0; --i) {
        cout << vals[i] << " ";
    }
}
