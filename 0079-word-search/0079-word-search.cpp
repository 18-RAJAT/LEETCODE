class Solution {
    vector<int>xDirection={0,-1,0,1};
    vector<int>yDirection={1,0,-1,0};
public:
    bool dfs(vector<vector<char>>&board,string& word,int i,int j,int n,int m,int idx)
    {
        int x=word.length();
        if(idx>=x)
        {
            return true;
        }
        if(i<0 or j<0 or i>=n or j>=m or board[i][j]!=word[idx])//board[i][j]=='#')//board[i][j]!=word[idx])
        {
            return false;
        }
        
        //mark the current visited
        board[i][j]='#';
        
        // if(idx==n)
        // {
        //     return true;
        // }
        
        // if(board[i][j]!=word[idx])
        // {
        //     return false;
        // }
        
        for(int k=0;k<4;++k)
        {
            if(dfs(board,word,xDirection[k]+i,yDirection[k]+j,n,m,idx+1))
            {
                return true;
            }
            // else if(board[k][k]!=word[idx])
            // {
            //     return false;
            // }
        }
        // board[i][j]=idx;
        // {
        //     return false;
        // }
        // if(board[i][j]===0)
        // {
        //     return false;
        // }
        board[i][j]=word[idx];
        {
            return false;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        // int idx=0;
        
        for(int i=0;i<n;++i)
        {
            // idx++;
            for(int j=0;j<m;++j)
            {
                // idx++;
                if(board[i][j]==word[0])
                {
                    // cout<<idx<<endl;
                    if(dfs(board,word,i,j,n,m,0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};