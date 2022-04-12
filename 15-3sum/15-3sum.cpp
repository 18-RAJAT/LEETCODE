class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
         vector<vector<int>>answer;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();++i)
        {
            int target = -nums[i];
            
            //Starting position
            int left = i+1;
            //Ending position
            int right = nums.size() - 1;
            
            while(left < right)
            {
                int sum = nums[left] + nums[right];
                
                // Finding answer which start from number num[i]
                if(sum < target)
                    left++;
                
                else if(sum > target)
                    right--;
                
                else
                {
                    vector<int>triplet = {nums[i],nums[left],nums[right]};
                    
                    answer.push_back(triplet);
                    
                    while(left < right and nums[left] == triplet[1])
                        left++;
                    
                    while(left < right and nums[left] == triplet[2])
                        right--;
                }
            }
            while(i+1 < nums.size() and nums[i+1] == nums[i])
                i++;
        }
        
         return answer;
    }
};