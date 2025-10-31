class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>fz;
        vector<int>ans;
        for(auto& it:nums)
        {
            fz[it]++;
            if(fz[it]==2)ans.push_back(it);
        }
        return ans;
    }
};