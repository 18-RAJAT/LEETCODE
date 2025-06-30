class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        if(grid[0][0] == 1 or grid[n-1][n-1] == 1)
            return -1;
        
        queue<pair<int,int>>q;
        
        //Insert starting cell
        q.push(make_pair(0,0));
        
        vector<vector<int>> directions = {{1,1},{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{1,-1},{-1,1}};
        
        grid[0][0] = 1;
        
        while(!q.empty())
        {
            int row = q.front().first;
            int column = q.front().second;
            
            if(row == n-1 and column == n-1)
            {return grid[row][column];}
                
                for(auto direction : directions)
                {
                    int new_row = row + direction[0];
                    int new_column = column + direction[1];
                    
                    if(new_row >= 0 and new_row < n and new_column >= 0 and new_column < n and grid[new_row][new_column] == 0)
                           
                    {
                        q.push(make_pair(new_row,new_column));
                        
                        grid[new_row][new_column] = grid[row][column] + 1;
                    }
         }
        q.pop();
}
         return -1;
        
    }
};