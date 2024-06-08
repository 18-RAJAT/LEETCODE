class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        mp[0]=1;
        int init=nums[0]%k;
        for(int i=1;i<nums.size();++i)
        {
            int temp=init;
            init=(init+nums[i])%k;
            if(mp.count(init))return true;
            mp[temp]++;
        }
        return false;
    }
};