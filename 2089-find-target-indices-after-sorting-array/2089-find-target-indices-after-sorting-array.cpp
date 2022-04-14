class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
      vector<int> v1;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();++i)
        {
            if(target == nums[i])
            {
                v1.push_back(i);
            }
            
            if(target < nums[i])
            {
                break;
            }
        }
        
        return v1;
        
    }
};