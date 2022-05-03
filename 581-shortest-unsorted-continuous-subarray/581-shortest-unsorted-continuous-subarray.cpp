class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
            
      vector<int>sorted(nums);
            
            sort(nums.begin(),nums.end());
            
            int n = nums.size();
            int start = 0;
            int end = n-1;
            
            while(start<n and nums[start] == sorted[start])
            {
                    start++;
            }
            
            while(end > start and nums[end] == sorted[end])
            {
                    end--;
            }
          return end + 1 - start;  
    }
};