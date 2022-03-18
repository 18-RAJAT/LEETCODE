class Solution {
public:
    int search(vector<int>& nums, int target) {

    
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
           int mid;
        int left = 0;
        int right = n-1;
        

        while(left<=right)
        {
            mid = right + (left-right)/2;
  
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>=nums[left])
            {
                if(target<=nums[mid] and target>=nums[left])
                    right = mid-1;
                else
                    left = mid+1;
            }
            else
            {
                if(target>=nums[mid] and target<=nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        return -1;
    }
};