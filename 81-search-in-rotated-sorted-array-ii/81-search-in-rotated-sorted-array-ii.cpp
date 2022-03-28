class Solution {
public:
  
    bool search(vector<int>& nums, int target) {
        
        int start = 0;
        int end = nums.size()-1;
        
        //Using binary search
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            
            if(nums[mid] == target)
            {
                return true;
            }
            
            //Left part sorted
            if(nums[mid] > nums[start])
            {
                if(nums[mid] < target or nums[start] > target)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            
            //Right part sorted
            
            else if(nums[mid] < nums[end])
            {
                if(nums[mid] > target or nums[end] < target)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            
            //Corner cases 
            else
            {
                for(int i=start;i<=end;++i)
                {
                    if(nums[i] == target)
                    {
                        return true;
                    }
                }
                
                return false;
            }
        }
        return false;
    }
};