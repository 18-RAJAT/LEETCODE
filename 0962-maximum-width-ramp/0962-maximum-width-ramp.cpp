class Solution {
public:
    int maxWidthRamp(vector<int>&nums) {
        int n=nums.size(),res=0;
        vector<int>s;
        for(int i=0;i<n;++i)
        {
            if(s.empty()||nums[s.back()]>nums[i]) s.push_back(i);
        }
        for(int i=n-1;i>res;--i)
        {
            while(!s.empty() && nums[s.back()]<=nums[i])
            {
                res=max(res,i-s.back());
                s.pop_back();
            }
        }
        return res;
    }
};