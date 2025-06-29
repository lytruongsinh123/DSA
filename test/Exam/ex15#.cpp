#include <iostream>
#include <cstring>
using namespace std;

void delete_char(char *S, char c) {
    int i = 0, j = 0;
    while (S[i] != '\0') {
        if (S[i] != c) {
            S[j] = S[i];
            j++;
        }
        i++;
    }
    S[j] = '\0';
}

int main() {
    char S[101] = "abcccaa";
    char c = 'a';
    delete_char(S, c);
    cout << S << endl; // Kết quả: "bcdc"
    return 0;
}
