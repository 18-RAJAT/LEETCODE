class Solution {
public:
    
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, 
             int i, int j, int m, int n, int val, int& count, int space) {
        
        //cout << i << ":" << j << ":" << ":" << val << endl;
        if (i < 0 || i == m || j < 0 || j == n)  return;
        if (grid[i][j] == -1 || dp[i][j] == 1)   return;
        if (grid[i][j] == 2) {
            if (space == val)   count++;
            return;
        }
        dp[i][j] = 1;
        for (int k = 0; k < dir.size(); k++) {
            int x = i + dir[k][0], y = j + dir[k][1];
            dfs(grid, dp, x, y, m, n, val + 1, count, space);
        }
        dp[i][j] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int space = 0, m = grid.size(), n = grid[0].size(), x, y;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)    space++;
                else if (grid[i][j] == 1)  {
                    x = i; y = j;
                }
            }
        }
        int val = -1, count = 0;
        grid[x][y] = 0;
        dfs(grid, dp, x, y, m, n, val, count, space);
        
        return count;
    }
};