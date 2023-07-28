class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
		int n=nums.size();
		vector<vector<int>> dp(n,vector<int>(n,0));
		for(int i=0;i<n;i++)
		{
			dp[i][i]=nums[i];
		}
		for(int i=0;i<n-1;i++)
		{
			dp[i][i+1]=max(nums[i],nums[i+1]);
		}
		for(int i=2;i<n;i++)
		{
			for(int j=0;j<n-i;j++)
			{
				int x=nums[j]+min(dp[j+2][j+i],dp[j+1][j+i-1]);
				int y=nums[j+i]+min(dp[j+1][j+i-1],dp[j][j+i-2]);
				dp[j][j+i]=max(x,y);
			}
		}
		int sum=0;
		for(int i=0;i<n;i++)
		{
			sum+=nums[i];
		}
		return dp[0][n-1]>=(sum-dp[0][n-1]);
    }
};