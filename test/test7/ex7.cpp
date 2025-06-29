#include <iostream>
using namespace std;
void sortptr(const int** arr, int size_) {
    for (int i = 0; i < size_ - 1; ++i) {
        for (int j = i + 1; j < size_; ++j) {
            if (*arr[i] > *arr[j]) {
                const int* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
