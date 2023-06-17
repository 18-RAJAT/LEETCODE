class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        set<int> tmp;
        for(int i=0;i<arr2.size();i++) tmp.insert(arr2[i]);
        arr2.clear();
        for(auto it=tmp.begin();it!=tmp.end();++it) arr2.push_back(*it);
        int n=arr1.size(),m=arr2.size();
        vector<vector<int>> dp(n,vector<int>(m,100000));
        for(int i=0;i<m;i++) dp[0][i]=1;
        for(int i=1;i<n;i++){
            if(arr1[i]>arr1[i-1] and arr2[0]>arr1[i-1]) dp[i][0]=1;
            else break;
        }
        vector<int> d(n,100000);
        d[0]=0;
        for(int i=1;i<n;i++)
        {
            if(arr1[i]>arr1[i-1]) d[i]=min(d[i],d[i-1]);
            for(int j=1;j<m;j++)
            {
                if(arr2[j]>arr1[i-1]) dp[i][j]=min(d[i-1]+1,dp[i][j]);
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
                if(arr1[i]>arr2[j-1]) d[i]=min(d[i],dp[i-1][j-1]);
            }
            if(arr1[i]>arr2[m-1]) d[i]=min(d[i],dp[i-1][m-1]);
        }
        if(min(d[n-1],dp[n-1][m-1])>2001) return -1;
        return min(d[n-1],dp[n-1][m-1]);
    }
};