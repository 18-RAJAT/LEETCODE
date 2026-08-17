class Solution {
public:
    int dp[505][505];
    int pre[505];
    int sum(int l,int r)
    {
        return pre[r+1]-pre[l];
    }
    int solve(int l,int r,vector<int>& a)
    {
        if(l>=r)return 0;
        if(~dp[l][r])return dp[l][r];
        int ans=0;

        for(int i=l;i<r;++i)
        {
            int left=sum(l,i),right=sum(i+1,r);
            if(left<right)
            {
                ans=max(ans,left+solve(l,i,a));
            }
            else if(right<left)
            {
                ans=max(ans,right+solve(i+1,r,a));
            }
            else
            {
                ans=max(ans,left+max(solve(l,i,a),solve(i+1,r,a)));
            }
        }
        return dp[l][r]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        pre[0]=0;
        for(int i=0;i<n;++i)pre[i+1]=pre[i]+stoneValue[i];
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,stoneValue);
    }
};