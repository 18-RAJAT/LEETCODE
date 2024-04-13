class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
        {
            return 0;
        }
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(matrix[i][j]=='1')
                {
                    dp[i][j]=1;
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=1;j<m;++j)
            {
                if(dp[i][j]!=0)
                {
                    dp[i][j]+=dp[i][j-1];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                int width=dp[i][j];
                int height=1;
                ans=max(ans,width*height);
                for(int k=i-1;k>=0;--k)
                {
                    if(dp[k][j]==0)
                    {
                        break;
                    }
                    width=min(width,dp[k][j]);
                    height=i-k+1;
                    ans=max(ans,width*height);
                }
            }
        }
        return ans;
    }
};