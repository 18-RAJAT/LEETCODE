class Solution{
public:
    int maxWalls(vector<int>& robots,vector<int>& d,vector<int>& walls) {
        int n=robots.size();
        vector<array<int,2>>ar(n);
        for(int i=0;i<n;++i)ar[i][0]=robots[i],ar[i][1]=d[i];
        sort(walls.begin(),walls.end());
        sort(ar.begin(),ar.end());
        ar.push_back({(int)1e9,0});
        auto query=[&](int l,int r)
        {
            if(r<l)return 0;
            auto it1=upper_bound(walls.begin(),walls.end(),r);
            auto it2=lower_bound(walls.begin(),walls.end(),l);
            return (int)(it1-it2);
        };

        vector<array<int,2>>dp(n);
        dp[0][0]=query(ar[0][0]-ar[0][1],ar[0][0]);
        if(n>1)dp[0][1]=query(ar[0][0],min(ar[1][0]-1,ar[0][0]+ar[0][1]));
        else dp[0][1]=query(ar[0][0],ar[0][0]+ar[0][1]);
        for(int i=1;i<n;++i)
        {
            dp[i][1]=max(dp[i-1][1],dp[i-1][0])+query(ar[i][0],min(ar[i+1][0]-1,ar[i][0]+ar[i][1]));
            dp[i][0]=dp[i-1][0]+query(max(ar[i][0]-ar[i][1],ar[i-1][0]+1),ar[i][0]);
            int res=dp[i-1][1]+query(max(ar[i][0]-ar[i][1],ar[i-1][0]+1),ar[i][0])-query(max(ar[i][0]-ar[i][1],ar[i-1][0]+1),min(ar[i-1][0]+ar[i-1][1],ar[i][0]-1));
            dp[i][0]=max(res,dp[i][0]);
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};