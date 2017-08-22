// https://leetcode.com/problems/valid-sudoku/#/description
// chi zhang, 2017-7-5

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row
        for (size_t i = 0; i < board.size(); ++i) {
            set<char> tmp;
            for (size_t j = 0; j < board[i].size(); ++j) {
                if (CheckIfExists(tmp, board[i][j])) {
                    return false;
                }
            }
        }
        // column
        for (size_t i = 0; i < board[0].size(); ++i) {
            set<char> tmp;
            for (size_t j = 0; j < board.size(); ++j) {
                if (CheckIfExists(tmp, board[j][i])) {
                    return false;
                }
            }
        }
        // block
        for (size_t i = 0; i < board.size(); i += 3) {
            for (size_t j = 0; j < board[i].size(); j += 3) {
                // check a block
                set<char> tmp;
                for (size_t x = i; x < i + 3; ++x) {
                    for (size_t y = j; y < j + 3; ++y) {
                        if (CheckIfExists(tmp, board[x][y])) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
private:
    bool CheckIfExists(set<char>& tmp, char now) {
        if (now == '.') {
            return false;
        }
        if (tmp.find(now) != tmp.end()) {
            return true;
        } else {
            tmp.insert(now);
            return false;
        }
    }
};
