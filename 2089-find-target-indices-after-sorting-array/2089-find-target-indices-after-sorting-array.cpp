class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
     vector<int>result;
            sort(nums.begin(),nums.end());
            for(int i=0;i<nums.size();++i)
            {
                    if(target==nums[i]){result.push_back(i);}
                    if(target<nums[i]){break;}
            }
        return result;
    }
};