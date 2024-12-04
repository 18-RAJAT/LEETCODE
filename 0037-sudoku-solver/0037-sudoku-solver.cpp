class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board,int i,int j,char ch)
    {
        for(int k=0;k<9;++k)
        {
            if(board[i][k]==ch || board[k][j]==ch)return false;
            if(board[3*(i/3)+k/3][3*(j/3)+k%3]==ch)return false;
        }
        return true;
    }
    int solve(vector<vector<char>>& board)
    {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(board[i][j]=='.')
                {
                    for(char ch='1';ch<='9';++ch)
                    {
                        if(isValidSudoku(board,i,j,ch))
                        {
                            board[i][j]=ch;
                            if(solve(board))return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};