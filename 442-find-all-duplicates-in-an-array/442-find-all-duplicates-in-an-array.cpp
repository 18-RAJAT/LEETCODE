class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      int n=nums.size();
            vector<int>dup;
            sort(nums.begin(),nums.end());
            for(int i=0;i<n-1;++i)
            {
                    if(nums[i]==nums[i+1])
                    {
                            dup.push_back(nums[i]);
                    }
            }
            return dup;
    }
};