class Solution{
public:
    int dp[1005][1005];
    int recur(int i,int prev,vector<int>&nums,int target){
        int n=nums.size();
        if(prev==n-1)return 0;
        if(i==n)return INT_MIN;
        if(~dp[i][prev])return dp[i][prev];
        int take=INT_MIN;
        long long res=nums[i]-nums[prev];
        if(-target<=res && res<=target)
        {
            int tmp=recur(i+1,i,nums,target);
            if(tmp!=INT_MIN)take=1+tmp;
        }
        int leave=recur(i+1,prev,nums,target);
        return dp[i][prev]=max(take,leave);
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int res=recur(1,0,nums,target);
        return res<0?-1:res;
    }
};