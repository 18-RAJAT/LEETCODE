class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();

        int cnt = 0;
        vector<pair<int, int>> deltas{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        vector<vector<int>> vis(rows, vector<int>(cols, -1));

        queue<pair<pair<int, int>, int>> qu; // row, col, k
        qu.push({{0, 0}, k});
        while(!qu.empty()) {
            int sz = qu.size();
            while(sz--) {
                auto & [cell, k_left] = qu.front();
                auto & [row, col] = cell;

                if(row == rows - 1 && col == cols - 1) return cnt;

                for(auto & [dr, dc] : deltas) {
                    int new_row = row + dr, new_col = col + dc;
                    if(new_row < 0 || new_row == rows || new_col < 0 || new_col == cols) continue;

                    int new_k = k_left - grid[new_row][new_col];
                    if(new_k < 0) continue;

                    if(vis[new_row][new_col] >= new_k) continue; // we already have a better path

                    vis[new_row][new_col] = new_k;
                    qu.push({{new_row, new_col}, new_k});
                }

                qu.pop();
            }
            ++cnt;
        }

        return -1;
    }
};