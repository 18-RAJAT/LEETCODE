class Solution {
public:
    int recur(string &s,int idx,int prev,int k,vector<vector<int>>&dp)
    {
        if(idx==s.size())return 0;
        int &ans=dp[idx][prev];
        if(~ans)return ans;
        int take=0,leave=0;
        if(prev==0 || abs(s[idx]-prev)<=k)
        {
            take=1+recur(s,idx+1,s[idx],k,dp);
        }
        leave=recur(s,idx+1,prev,k,dp);
        return ans=max(take,leave);
    }
    int longestIdealString(string s, int k) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(155,-1));
        return recur(s,0,0,k,dp);
    }
};