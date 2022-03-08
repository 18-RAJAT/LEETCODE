class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
     
       vector<vector<int>> answer;
        
      
        vector<vector<bool>> grid(8, vector<bool>(8, false));
        for(auto v: queens)
        {
            grid[v[0]][v[1]] = true; 
        }
        
        //SAME ROW
        
        // check queens in same row towards right.
        for(int j = king[1] + 1 ; j < 8 ; j++)
        {
            if(grid[king[0]][j] == true) 
            {
                answer.push_back({king[0], j});
                break;
            }
        }
        
        
        // check queens in same row towards left.
        for(int j = king[1] - 1 ; j >= 0 ; j--)
        {
            if(grid[king[0]][j] == true)
            {
                answer.push_back({king[0], j});
                break;
            }
        }
        
        // SAME COLUMN
        // check queens in same col towards down.
        for(int i = king[0] + 1 ; i < 8 ; i++) {
            if(grid[i][king[1]] == true) {
                answer.push_back({i, king[1]});
                break;
            }
        }
        // check queens in same col towards up.
        for(int i = king[0] - 1 ; i >= 0 ; i--) {
            if(grid[i][king[1]] == true) {
                answer.push_back({i, king[1]});
                break;
            }
        }
        
        
        // CHECK DIAGONALS
        // towards top left
        for(int i = king[0], j = king[1] ; i >= 0 && j >= 0 ; i--, j--)
        {
            if(grid[i][j] == true)
            {
                answer.push_back({i, j});
                break;
            }
        }
        
        
        // towards top right
        for(int i = king[0], j = king[1] ; i >= 0 && j < 8 ; i--, j++)
        {
            if(grid[i][j] == true)
            {
                answer.push_back({i, j});
                break;
            }
        }
        
        
        // towards bottom left
        for(int i = king[0], j = king[1] ; i < 8 && j >= 0 ; i++, j--) 
        {
            if(grid[i][j] == true) 
            {
                answer.push_back({i, j});
                break;
            }
        }
        
        
        // towards bottom right
        for(int i = king[0], j = king[1] ; i < 8 && j < 8 ; i++, j++) 
        {
            if(grid[i][j] == true) 
            {
                answer.push_back({i, j});
                break;
            }
        }
        
        return answer;
        
    }
};
