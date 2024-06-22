class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0,count=0;
        for(int l=0,r=0;r<n;++r)
        {
            if(nums[r]%2){k--,count=0;}
            while(k==0)
            {
                count++,k+=(nums[l++]%2);
            }
            ans+=count;
        }
        return ans;
    }
};