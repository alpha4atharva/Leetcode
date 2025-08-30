class Solution {
public:
    bool matrixValid(int row, int column, vector<vector<char>>& board) {
        unordered_map<char, int> mp;
        for (int i = row; i < row + 3; i++) {
            for (int j = column; j < column + 3; j++) {
                if (board[i][j] != '.') {
                    if (mp.find(board[i][j]) != mp.end())
                        return false;
                    mp[board[i][j]]++;
                }
            }
        }
        return true;
    }

    bool rowValid(int row, vector<vector<char>>& board) {
        unordered_map<char, int> mp;
        for (int i = 0; i < 9; i++) {
            if (board[row][i] != '.') {
                if (mp.find(board[row][i]) != mp.end())
                    return false;
                mp[board[row][i]]++;
            }
        }
        return true;
    }

    bool colValid(int col, vector<vector<char>>& board) {
        unordered_map<char, int> mp;
        for (int i = 0; i < 9; i++) {
            if (board[i][col] != '.') {
                if (mp.find(board[i][col]) != mp.end())
                    return false;
                mp[board[i][col]]++;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!matrixValid(i, j, board))
                    return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            if (!rowValid(i, board) || !colValid(i, board))
                return false;
        }

        return true;
    }
};