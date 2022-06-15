class Solution {
public:
    int singleNumber(vector<int>& nums) {
       map<int,int>mp;
            for(int i=0;i<nums.size();++i)
                    mp[nums[i]]++;
            for(auto m : mp)if(m.second==1){return m.first;}
            return 1;
    }
};