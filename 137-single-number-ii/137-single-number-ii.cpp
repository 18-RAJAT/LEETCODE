class Solution {
public:
    int singleNumber(vector<int>& nums) {
       map<int,int>mp;
            int ct=0;
            for(int i=0;i<nums.size();++i)
                    mp[nums[i]]++;
            for(auto m : mp)if(m.second==1){return m.first;ct++;}
            return 1;
    }
};