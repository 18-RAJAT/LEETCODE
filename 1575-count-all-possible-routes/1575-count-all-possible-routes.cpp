class Solution {
public:
    //MEMOIZATION
    int MOD=(int)(1e9+7);
    int f(vector<int>& locations,int start,int finish,int fuel,vector<vector<int>>& dp){
        int ans=0;
        if(start==finish) ans++;
        if(dp[start][fuel]!=-1) return dp[start][fuel];
        for(int i=0;i<locations.size();i++){
            if(i==start || abs(locations[i]-locations[start])>fuel) continue;
            ans+=f(locations,i,finish,fuel-abs(locations[i]-locations[start]),dp)%MOD;
            ans%=MOD;
        }
        return dp[start][fuel]=ans%MOD;
    }
    int countRoutes(vector<int>& locations,int start,int finish,int fuel){
        int n=locations.size();
        vector<vector<int>> dp(n, vector<int> (fuel+1,-1));
        return f(locations,start,finish,fuel,dp);
    }
};