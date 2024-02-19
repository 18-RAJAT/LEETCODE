class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(auto& it:nums)
        {
            mp[it]++;
        }
        for(auto& [key,value]:mp)
        {
            if(value==1)
            {
                return key;
            }
        }
        return -1;
    }
};