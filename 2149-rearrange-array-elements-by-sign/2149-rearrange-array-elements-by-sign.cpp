class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        
        int ctr=0,mve=1;
        
        for(int i=0;i<n;++i)
        {
            if(nums[i]>=0)
            {
                ans[ctr]=nums[i];
                ctr+=2;
            }
            else
            {
                ans[mve]=nums[i];
                mve+=2;
            }
        }
        return ans;
    }
};