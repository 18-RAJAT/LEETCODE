class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
            vector<int>v1;
       sort(nums.begin(),nums.end());
            for(int i=0;i<n-1;++i)
            {
                    if(nums[i]==nums[i+1])
                            v1.push_back(nums[i]);
            }
            return v1;
    }
};