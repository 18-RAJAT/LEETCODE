class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(auto& it:nums)
        {
            ans.push_back(it);
        }
        while(n>0)
        {
            vector<int>find;
            for(int i=0;i<ans.size()-1;++i)
            {
                int state=ans[i]+ans[i+1];
                find.push_back(state%10);
            }
            ans.clear();
            for(auto& it:find)
            {
                ans.push_back(it);
            }
            n--;
        }
        return ans[0];
    }
};