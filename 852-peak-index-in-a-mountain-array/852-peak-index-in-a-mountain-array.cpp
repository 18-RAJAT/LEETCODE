class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
      /*  1st APPROACH
        
        int left =0;
        while(arr[left] < arr[left+1])
        {
            left++;
        }
        
        return left;
        
        */
        
        
        // 2nd approach using Binary Search 
        
        int start = 0;
        int end = arr.size()-1;
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            
            if(arr[mid] < arr[mid+1])
            {
                start = mid + 1;
            }
            
            else
            {
                end = mid -1; 
            }
        }
        
        return start;
    }
    
};