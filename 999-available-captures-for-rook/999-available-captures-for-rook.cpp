class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        
        
        int x0=0,y0=0,result =0;
        
        for(int i=0;i<8;++i)
        {
            for(int j=0;j<8;++j)
            {
                if(board[i][j] == 'R')
                {
                    x0=i;
                    y0=j;
                }
            }
        }
        
        vector<vector<int>> direction = {{1,0},{0,1},{-1,0},{0,-1}};
        
        for(auto D : direction)
        {
            for(int x = x0+D[0],y = y0+D[1]; 0<=x and x<8 and 0<=y and y<8;x+=D[0],y+=D[1])
            {
                if(board[x][y] == 'p')
                    result++;
                
                if(board[x][y] != '.')
                    break;
            }
        }
        
        return result;
        
    }
};