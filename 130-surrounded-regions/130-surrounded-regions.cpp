class Solution {
    bool flag;
    void helper(vector<vector<char>>&board,int i,int j,int r,int c)
    {
        if(i<0 or i>r-1 or j<0 or  j>c-1){return;}
        if(board[i][j]=='X'){return;}
        board[i][j]='X';
        helper(board,i-1,j,r,c);
        helper(board,i+1,j,r,c);
        helper(board,i,j-1,r,c);
        helper(board,i,j+1,r,c);
    }
    void dfs(vector<vector<char>>&board,int i,int j,int r,int c,vector<vector<bool>>& visited)
    {
        if(i<0 or i>r-1 or j<0 or j>c-1)return;
        if(board[i][j]=='X' or visited[i][j])return;
        if(i<=0 or i>=r-1 or j<=0 or j>=c-1)flag=true;
        visited[i][j]=true;
        dfs(board,i-1,j,r,c,visited);
        dfs(board,i+1,j,r,c,visited);
        dfs(board,i,j-1,r,c,visited);
        dfs(board,i,j+1,r,c,visited);
    }
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size();if(r<=1){return;}
        int c=board[0].size();if(c<=1){return;}
        // if(r<=1){return;}if(c<=1){return;}
        vector<vector<bool>>visited(r,vector<bool>(c,false));
        for(int i=1;i<r-1;++i)
        {
            for(int j=1;j<c-1;++j)
            {
                if(board[i][j]=='O' and !visited[i][j])
                {
                    flag=false;
                    dfs(board,i,j,r,c,visited);
                    if(flag==false)
                    helper(board,i,j,r,c);
                    flag=true;
                }
            }
        }
    }
};