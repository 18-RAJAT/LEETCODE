class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size(),ans=0;
        for(int i=0;i<n;++i)
        {
            unordered_map<int,int>mp;
            for(int j=i;j<n;++j)
            {
                mp[nums[j]]++;
                int len=j-i+1;
                if(mp[target]>len/2)ans++;
            }
        }
        return ans;
    }
};