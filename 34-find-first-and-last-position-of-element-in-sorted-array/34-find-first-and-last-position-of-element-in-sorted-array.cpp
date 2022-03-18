class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
       
        int last =  upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
     
        if (first == last) 
        {
            return {-1, -1};
        }
        
        return {first, last - 1};
    }
    

};