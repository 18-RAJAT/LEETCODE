class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int i = m-1;
        int j = 0;
        
        int count = 0;
        
        while(i>=0 and i<m and j>=0 and j<n)
        {
            if(grid[i][j] < 0)
            {
                count = count + (n-j);
                i = i-1;
            }
            
            else
            {
                j = j+1;
            }
        }
        return count;
    }
};