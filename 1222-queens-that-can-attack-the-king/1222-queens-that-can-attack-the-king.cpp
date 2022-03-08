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





// class Solution {
// public:
//     vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        
//         vector<vector<int>>answer;
        
//         map<pair<int,int>,bool>MP;
        
//         for(auto q : queens)
//         {
//             MP[{q[0],q[1]}] = true;
            
//             int k_row = king[0];
//             int k_column = king[1];
            
//             //TOP
//             for(int r=k_row;r>=0;--r)
//             {
//                 if(MP.find({r,k_column}) != MP.end())
//                 {
//                     answer.push_back({r,k_column});
//                     break;
//                 }
//             }
            
//             //DOWN
//             for(int r=k_row;r<8;++r)
//             {
//                 if(MP.find({r,k_column}) != MP.end())
//                 {
//                     answer.push_back({r,k_column});
//                     break;
//                 }
//             }
            
            
//             //Left
//             for(int c=k_column;c>=0;--c)
//             {
//                 if(MP.find({k_row,c}) != MP.end())
//                 {
//                     answer.push_back({k_row,c});
//                     break;
//                 }
//             }
            
//             //Right 
//             for(int c=k_column;c<8;--c)
//             {
//                 if(MP.find({k_column,c}) != MP.end())
//                 {
//                     answer.push_back({k_column,c});
//                     break;
//                 }
//             }
            
//             //TOP LEFT
//             int c = k_column;
//             for(int r=k_row;r>=0 and c>=0;--r)
//             {
//                 if(MP.find({r,c}) != MP.end())
//                 {
//                     answer.push_back({r,c});
//                     break;
//                 }
                
//                 c--;
//             }
            
//             //TOP RIGHT 
//             for(int r=k_row,c=k_column;r>=0 and c<8;r--,c++)
//             {
//                 if(MP.find({r,c}) != MP.end())
//                 {
//                     answer.push_back({r,c});
//                     break;
//                 }
//             }
            
//             //BOTTOM LEFT
//             for(int r= k_column,c=k_column;r<8 and c>=0;r++,c--)
//             {
//                 if(MP.find({r,c}) != MP.end())
//                 {
//                     answer.push_back({r,c});
//                     break;
//                 }
//             }
            
//             //BOTTOM RIGHT
//             for(int r=k_row,c=k_row;r<8 and c<8;r++,c++)
//             {
//                 if(MP.find({r,c}) != MP.end())
//                 {
//                     answer.push_back({r,c});
//                     break;
//                 }
//             }
//         }
//         return answer;
//     }
// };





















































