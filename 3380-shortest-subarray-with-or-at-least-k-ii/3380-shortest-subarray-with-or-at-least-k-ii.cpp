class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        bitset<32>val;
        val.reset();
        vector<int>v(32,0);
        int ans=INT_MAX;
        for(int i=0,j=0;i<n;++i)
        {
            val|=nums[i];
            for(int l=0;l<32;++l)
            {
                if(nums[i]&(1<<l))
                {
                    v[l]++;
                }
            }
            while(i>=j && val.to_ulong()>=k)
            {
                ans=min(ans,i-j+1);
                for(int l=0;l<32;++l)
                {
                    if(nums[j]&(1<<l))
                    {
                        v[l]--;
                    }
                }
                val=0;
                for(int l=0;l<32;++l)
                {
                    if(v[l]>0)
                    {
                        val|=(1<<l);
                    }
                }
                j++;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};