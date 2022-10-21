class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;++i)
        {
            if(mp.find(nums[i])==mp.end())
            {
                mp.insert(make_pair(nums[i],i));
            }
            else
            {
                if(abs(mp[nums[i]]-i)<=k)
                {
                    return true;
                }
                else
                {
                    // return false;
                    mp[nums[i]]=i;
                }
            }
        }
        return false;
    }
};