class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>>ar;
        for(int i=0;i<n;++i)ar.push_back({nums[i],i});
        sort(ar.begin(),ar.end());
        vector<int>temp(n),pos(n);
        for(int i=0;i<n;++i)
        {
            temp[i]=ar[i].first;
            pos[ar[i].second]=i;
        }
        int mx=log2(n)+1;
        vector<vector<int>>dp(mx,vector<int>(n,-1));
        for(int i=0;i<n;++i)
        {
            int ind=upper_bound(temp.begin(),temp.end(),temp[i]+maxDiff)-temp.begin()-1;
            dp[0][i]=ind;
        }
        for(int i=1;i<mx;++i)
        {
            for(int j=0;j<n;++j)
            {
                dp[i][j]=dp[i-1][dp[i-1][j]];
            }
        }
        vector<int>ans;
        for(auto& it:queries)
        {
            int u=it[0],v=it[1];
            int a=pos[u],b=pos[v];
            if(a==b)ans.push_back(0);
            else
            {
                if(a>b)swap(a,b);
                int curr=0;
                for(int i=mx-1;~i;--i)
                {
                    if(dp[i][a]<b)
                    {
                        curr+=(1<<i);
                        a=dp[i][a];
                    }
                }
                if(dp[0][a]>=b)ans.push_back(curr+1);
                else ans.push_back(-1);
            }
        }
        return ans;
    }
};