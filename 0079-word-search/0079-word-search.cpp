class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vis[i][j] = true;
                    if (solve(board, word, i, j, 1, vis)) {
                        return true;
                    }
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }

    bool solve(vector<vector<char>> &board, string &word, int row, int col, int st, vector<vector<bool>> &vis) {
        if (st == word.size()) {
            return true;
        }
        
        int m = board.size();
        int n = board[0].size();
        
        // DOWN
        if (row + 1 < m && board[row+1][col] == word[st] && !vis[row+1][col]) {
            vis[row+1][col] = true;
            if (solve(board, word, row+1, col, st+1, vis)) {
                return true;
            }
            vis[row+1][col] = false;
        }
        
        // UP
        if (row - 1 >= 0 && board[row-1][col] == word[st] && !vis[row-1][col]) {
            vis[row-1][col] = true;
            if (solve(board, word, row-1, col, st+1, vis)) {
                return true;
            }
            vis[row-1][col] = false;
        }
        
        // LEFT
        if (col - 1 >= 0 && board[row][col-1] == word[st] && !vis[row][col-1]) {
            vis[row][col-1] = true;
            if (solve(board, word, row, col-1, st+1, vis)) {
                return true;
            }
            vis[row][col-1] = false;
        }
        
        // RIGHT
        if (col + 1 < n && board[row][col+1] == word[st] && !vis[row][col+1]) {
            vis[row][col+1] = true;
            if (solve(board, word, row, col+1, st+1, vis)) {
                return true;
            }
            vis[row][col+1] = false;
        }
        
        return false;
    }
};