class Solution {
public:
    int fUtils(vector<vector<int>>& grid, int row, int col, int rows, int cols)
    {
        //within the bounds, just dont put row check
        if(row < 0 || col < 0 || col >= cols)
        {
            return -1;
        }
        
        //row check for case when ball exits
        if(row == rows)
        {
            return col;
        }
        
        if(grid[row][col] == 1)
        {
            if(col + 1 < cols && grid[row][col+1] == 1)
            {
                return fUtils(grid, row + 1, col + 1, rows, cols);
            }
            else
            {
                //opposite when opposite in V
                return -1;
            }
        }
        else
        {
            if(col - 1 >= 0 && grid[row][col-1] == -1)
            {
                return fUtils(grid, row + 1, col - 1, rows, cols);
            }
            else
            {
                return -1;//stuck when opposite in V
            }
        }
        
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<int> res;
        
        for(int i=0;i<cols;i++)
        {
            //throwing balls from each cols
            int val = fUtils(grid, 0, i, rows, cols);
            res.push_back(val);
        }
        
        return res;
    }
};