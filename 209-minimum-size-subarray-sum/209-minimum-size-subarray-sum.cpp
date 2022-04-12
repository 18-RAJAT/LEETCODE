class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
     int left = 0;
     int right = 0;
        
        int minLength = INT_MAX;
        
        int sum = 0;
        
        while(right < nums.size())
        {
            sum += nums[right++];
            
            while(sum >= target)
            {
                minLength = min(minLength,right - left);
                
                sum -= nums[left++];
            }
        }
        return(minLength==INT_MAX) ? 0 : minLength;  
    }
};