class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size(),res=1,i=0,j=1;
        while(j<n)
        {
            int ok=32,f=1;
            for(int x=j-1;x>=i && ok;--x)
            {
                if(nums[j]&nums[x])
                {
                    f=0;break;
                }
                ok--;
            }
            (f)?(res=max(res,j-i+1),j++):i++;
        }
        return res;
    }
};