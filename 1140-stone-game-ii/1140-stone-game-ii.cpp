class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int INF=1e9+7;
        int dp[105][1005][2];
        function<int(int,int,int,vector<int>&)>solve=[&](int index,int m,int player,vector<int>& piles)->int
        {
            if(index==piles.size())
            {
                return 0;
            }
            if(dp[index][m][player]!=-1)
            {
                return dp[index][m][player];
            }
            int ans;
            int sum=0;
            if(player==0) 
            {
                ans=-INF;
                for(int i=index;i<min(index+2*m,(int)piles.size());++i) 
                {
                    sum+=piles[i];
                    ans=max(ans,solve(i+1,max(m,i-index+1),1-player,piles)+sum);
                }
            }
            else 
            {
                ans=INF;
                for(int i=index;i<min(index+2*m,(int)piles.size());++i) 
                {
                    ans=min(ans,solve(i+1,max(m,i-index+1),1-player,piles));
                }
            }
            return dp[index][m][player]=ans;
        };

        memset(dp,-1,sizeof dp);
        return solve(0,1,0,piles);
    }
};