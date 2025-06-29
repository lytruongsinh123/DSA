#include <cstring>
using namespace std;

void rFilter(char *s) {
    int len = strlen(s);
    for (int i = len - 1; i >= 0; --i) {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            break;  // Gặp chữ cái thì dừng lại
        }
        s[i] = '_';  // Thay thế ký tự không phải chữ cái
    }
}
