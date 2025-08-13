#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false)); // mảng đánh dấu giá trị trang hàng đã tồn tại
        vector<vector<bool>> cols(9, vector<bool>(9, false)); // mảng đánh dấu giá trị trang cột đã tồn tại
        vector<vector<bool>> boxes(9, vector<bool>(9, false)); // mảng đánh dấu giá trị trang ô đã tồn tại

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int boxIndex = (i / 3) * 3 + (j / 3);

                    // Kiểm tra xem giá trị num đã tồn tại trong hàng, cột hoặc ô chưa
                    if (rows[i][num] || cols[j][num] || boxes[boxIndex][num]) {
                        return false;
                    }
                    
                    // Nếu chưa tồn tại thì đánh dấu
                    rows[i][num] = true; // giá trị num trong hàng i chưa tồn tại thì đánh dấu
                    cols[j][num] = true; // giá trị num trong cột j chưa tồn tại thì đánh dấu
                    boxes[boxIndex][num] = true; // giá trị num trong ô boxIndex chưa tồn tại thì đánh dấu
                }
            }
        }
        return true;
    }
};
int main()
{
    Solution sol;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << sol.isValidSudoku(board) << endl;
    return 0;
}