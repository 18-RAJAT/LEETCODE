class Solution {
public:
        vector<vector<string>>result;
        bool valid(vector<string>&board,int row,int col)
        {
                //column
                 for(int i=row;i>=0;--i)
            if(board[i][col] == 'Q') return false;
                
                //Left Diagonal
                for(int i=row,j=col;i>=0&&j>=0;--i,--j)
            if(board[i][j] == 'Q') return false;
                
                //Right Diagonal
                for(int i=row,j=col;i>=0&&j<board.size();--i,++j)
            if(board[i][j] == 'Q') return false;
                return true;
        }
        
        void dfs(vector<string>&board,int row)
        {
                if(row==board.size())
                {
                        result.push_back(board);
                        return;
                }
                
        for(int i=0;i<board.size();++i)
        {
                if(valid(board,row,i))
                {
                        board[row][i]='Q';//Decision
                        dfs(board,row+1);//Next
                        board[row][i]='.';//backtrack
                }
        }
}
        
    vector<vector<string>> solveNQueens(int n) {
        if(n==0){return{{}};}
            vector<string>board(n,string(n,'.'));
            dfs(board,0);return result;
    }
};