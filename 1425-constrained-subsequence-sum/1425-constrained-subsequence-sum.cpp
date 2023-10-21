class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n);
        deque<int>q;
        int ans=INT_FAST16_MAX;
        for(int i=0;i<n;++i)
        {
            dp[i]=nums[i];//dp[i] is the max sum of subArray ending at i
            if(!q.empty())
            {
                dp[i]=max(dp[i],dp[q.front()]+nums[i]);//dp[i] is the max sum of subArray ending at i
            }
            ans=max(ans,dp[i]);
            while(!q.empty() && dp[q.back()]<=dp[i])
            {
                q.pop_back();
            }
            q.push_back(i);
            if(i-q.front()>=k)//if the size of subArray is larger than k, then pop the front element
            {
                q.pop_front();
            }
        }
        // assert(!q.empty() && q.front()==n-1 && dp[q.front()]==ans);
        return ans;
    }
};