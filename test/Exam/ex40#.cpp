#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Kiểm tra tên hợp lệ
bool Ten(const string& s)
{
    if (s.length() <= 2) return false;
    return s[0] >= 'A' && s[0] <= 'Z';
}

int main()
{
    string path;
    cin >> path;

    ifstream fin(path);
    if (!fin) {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    int N;
    fin >> N;
    fin.ignore(); // Bỏ ký tự newline

    for (int i = 0; i < N; i++) {
        string line;
        getline(fin, line);

        istringstream iss(line);
        string word;
        int count = 0;

        while (iss >> word) {
            if (Ten(word)) count++;
        }

        cout << count << endl;
    }

    fin.close();
    return 0;
}
