class Solution {
public:
    int solve(int i,int k,vector<vector<int>>& dp,vector<vector<int>>& piles)
    {
        if(k==0)return 0;
        if(i>=piles.size())return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int np = solve(i+1,k,dp,piles);
        int p=0;
        int sum=0;
        for(int ind=0;ind<piles[i].size() and ind+1<=k;ind++)
        {
            sum+=piles[i][ind];
            p=max(p,sum+solve(i+1,k-ind-1,dp,piles));
            
        }
        return dp[i][k]=max(p,np);
    }
 int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
        return solve(0,k,dp,piles);  
    }
};