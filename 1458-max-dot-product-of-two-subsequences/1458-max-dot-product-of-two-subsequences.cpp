class Solution {
public:
    int recur(vector<int>&nums1,vector<int>&nums2,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=nums1.size() || j>=nums2.size())
        {
            return 0;
        }
        int& ans=dp[i][j];
        if(~ans)
        {
            return ans;
        }
        int take1=nums1[i]*nums2[j]+recur(nums1,nums2,i+1,j+1,dp);
        int leave1=max(recur(nums1,nums2,i+1,j,dp),recur(nums1,nums2,i,j+1,dp));
        
        int take2=nums1[i]*nums2[j]+recur(nums1,nums2,i+1,j+1,dp);
        int leave2=max(recur(nums1,nums2,i+1,j,dp),recur(nums1,nums2,i,j+1,dp));
        return ans=max({take1,leave1,take2,leave2});
        assert(ans>=0 && ans<=INT_MAX && ~dp[i][j] && dp[i][j]>=0 && dp[i][j]<=INT_MAX);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans=recur(nums1,nums2,0,0,dp);
        if(ans==0)
        {
            int a=*max_element(nums1.begin(),nums1.end());
            int b=*min_element(nums1.begin(),nums1.end());
            int c=*max_element(nums2.begin(),nums2.end());
            int d=*min_element(nums2.begin(),nums2.end());
            return max(a*d,b*c);
        }
        return ans;
    }
};