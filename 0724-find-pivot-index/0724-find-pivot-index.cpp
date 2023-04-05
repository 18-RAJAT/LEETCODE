class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int right=0,left=0,pivot=0;
        int n=nums.size();
        for(int i=1;i<n;++i)
        {
            right+=nums[i];
        }
        while(pivot<n)
        {
            if(left==right)
            {
                return pivot;
            }
            else if(pivot==n-1)
            {
                return -1;
            }
            else
            {
                left+=nums[pivot];
                right-=nums[1+pivot];
                pivot++;
            }
        }
        return -1;
    }
};