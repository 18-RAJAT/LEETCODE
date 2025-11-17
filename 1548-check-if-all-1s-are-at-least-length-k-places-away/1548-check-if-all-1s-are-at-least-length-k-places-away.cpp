class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size(),cur=-1,pre=-1;
        for(int i=0;i<n;++i)
        {
            if(nums[i]==1)
            {
                pre=cur,cur=i;
            }
            if(~pre && ((cur-pre-1)<k))return false;
        }
        return true;
    }
};