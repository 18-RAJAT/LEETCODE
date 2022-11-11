class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
            
            int n = nums.size();
          int duplicates=0;
            
            for(int i=1;i<n;++i)
            {
                    if(nums[i] == nums[i-1])
                    {
                            duplicates++;
                    }
                    else
                    {
                            nums[i-duplicates] = nums[i];
                    }
            }
        int ans=n-duplicates;
        return ans;
    }
};