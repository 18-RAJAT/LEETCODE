class Solution {
public:
    int Mod=1e9+7;
    int recur(int i,int j,int sum,int& k,vector<vector<int>>& ar,vector<vector<vector<int>>>& dp)
    {
        if(i<0 || j<0)return 0;
        if(i==0 && j==0)return(sum+ar[0][0])%k==0;
        if(~dp[i][j][sum])return dp[i][j][sum];
        int x1=recur(i-1,j,(sum+ar[i][j])%k,k,ar,dp),x2=recur(i,j-1,(sum+ar[i][j])%k,k,ar,dp);
        return dp[i][j][sum]=(x1+x2)%Mod;
    }
    int numberOfPaths(vector<vector<int>>& ar, int k)
    {
        int m=ar.size(),n=ar[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k,-1)));
        return recur(m-1,n-1,0,k,ar,dp);
    }
};