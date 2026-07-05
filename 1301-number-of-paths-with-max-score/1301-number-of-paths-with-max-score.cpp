class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size(),MOD=1e9+7;
        vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(n,{-1,0}));
        dp[n-1][n-1]={0,1};
        int dir[3][2]={{1,0},{0,1},{1,1}};
        for(int i=n-1;~i;--i)
        {
            for(int j=n-1;~j;--j)
            {
                if(i==n-1 && j==n-1)continue;
                if(board[i][j]=='X')continue;
                int mx=-1;
                long long ways=0;
                for(auto& it:dir)
                {

                    int X=i+it[0],Y=j+it[1];
                    if(X<n && Y<n && ~dp[X][Y].first)
                    {
                        int score=dp[X][Y].first,cnt=dp[X][Y].second;
                        if(score>mx)
                        {
                            mx=score;
                            ways=cnt;
                        }
                        else if(score==mx)
                        {
                            ways=(ways+cnt)%MOD;
                        }
                    }
                }
                if(~mx)
                {
                    int val=(board[i][j]=='E'?0:board[i][j]-'0');
                    dp[i][j]={mx+val,ways};
                }
            }
        }
        if(dp[0][0].first==-1)return {0,0};
        return {dp[0][0].first,dp[0][0].second};
    }
};