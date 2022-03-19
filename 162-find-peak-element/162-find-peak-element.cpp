class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int left = 0;
        int right = nums.size();
        
        if(right == 1)
            return 0;
        while(left < right){
            int mid = left + (right - left) / 2;
            
            if(mid + 1 < nums.size() and nums[mid] < nums[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};