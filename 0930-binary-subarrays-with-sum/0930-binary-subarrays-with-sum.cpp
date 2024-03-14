class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int ans=0;
        int sum=0;
        unordered_map<int,int>mp;
        mp.clear();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==goal)
            {
                ans++;
            }
            if(mp.count(sum-goal))
            {
                ans+=mp[sum-goal];
            }
            mp[sum]++;
        }
        return ans;
    }
};