class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n=nums.size();
        vector<int>bit(1<<16,0);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                bit[nums[i]&nums[j]]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<(1<<16);++j)
            {
                if((j&(nums[i]))==0)
                {
                    ans+=bit[j];
                }
            }
        }
        bit.clear();
        return ans;
    }
};