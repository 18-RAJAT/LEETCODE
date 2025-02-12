class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>>mp;
        int ans=-1;
        for(int i=0;i<nums.size();++i)
        {
            int sum=0;
            int n=nums[i];
            while(n>0)
            {
                sum+=n%10;
                n/=10;
            }
            mp[sum].push(nums[i]);
            if(mp[sum].size()>=2)
            {
                int p=mp[sum].top();
                mp[sum].pop();
                int q=mp[sum].top();
                mp[sum].push(p);
                ans=max(ans,p+q);
            }
        }
        return ans;
    }
};