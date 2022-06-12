class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      vector<int>answer;
            map<int,int>mp;
            for(int i=0;i<nums.size();++i)
            {
                    mp[nums[i]]++;
            }
            for(auto it:mp)
            {
                    if(it.second>(nums.size()/3)){answer.push_back(it.first);}
            }
            return answer;
    }
};