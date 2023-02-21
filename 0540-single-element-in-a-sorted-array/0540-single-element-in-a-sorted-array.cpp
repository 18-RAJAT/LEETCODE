class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        vector<int>cnt(100000,0);
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            cnt[nums[i]]++;
        }
        for(int i=0;i<cnt.size();++i)
        {
            if(cnt[i]==1)
            {
                return i;
            }
        }
        return 0;
    }
};