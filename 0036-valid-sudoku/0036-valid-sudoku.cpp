class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        function<bool(int,int)>check=[&](int i,int j)
        {
            for(int k=0;k<9;k++)
            {
                if(k!=j and board[i][k]==board[i][j])
                {
                    return false;
                }
                if(k!=i and board[k][j]==board[i][j])
                {
                    return false;
                }
            }
            int x=i/3;
            int y=j/3;
            for(int k=0;k<3;k++)
            {
                for(int l=0;l<3;l++)
                {
                    if((x*3+k!=i and y*3+l!=j) and board[x*3+k][y*3+l]==board[i][j])
                    {
                        return false;
                    }
                }
            }
            return true;
        };
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.' and not check(i,j))
                {
                    return false;
                }
            }
        }
        return true;
    }
};