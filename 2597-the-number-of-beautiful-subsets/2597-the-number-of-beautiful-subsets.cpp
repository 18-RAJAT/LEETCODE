class Solution {
public:
    unordered_map<int,int>mp;
    int recur(int idx,int k,vector<int>& nums)
    {
        if(nums.size()<=idx)return 1;
        int ans=0;
        if(!mp[nums[idx]-k])
        {
            mp[nums[idx]]++;
            ans+=recur(idx+1,k,nums);
            mp[nums[idx]]--;
        }
        ans+=recur(idx+1,k,nums);
        return ans;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int subset_ans=0,n=nums.size();
        for(int i=0;i<n;++i)
        {
            mp[nums[i]]++;
            subset_ans+=recur(i+1,k,nums);
            mp[nums[i]]--;
        }
        return subset_ans;
    }
};