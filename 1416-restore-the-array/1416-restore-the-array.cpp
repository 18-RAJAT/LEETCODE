class Solution {
public:
	int numberOfArrays(string s, int k) {
		int n=s.size();
		vector<int>dp(n,-1);
		function<int(int)>Restore=[&](int x)
		{
			if(x==n)
            {
                return 1;
            }
			if(s[x]=='0')
            {
                return 0;
            }
			if(dp[x]>=0)
            {
                return dp[x];
            }
			int ans=0;
			long num=0;
			for(int j=x+1;j<=n;j++)
			{
				num=num*10+(s[j-1]-'0');
				if(num>k) break;
				ans=(ans+Restore(j))%1000000007;
			}
			dp[x]=ans;
			return ans;
		};
        return Restore (0);
	}
};