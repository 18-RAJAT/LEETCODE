class Solution {
public:
    
    bool isvalid(vector<int>& arr,int target,int destination)
    {
        
        int start = 0;
        int end = arr.size()-1;
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            
            if(abs(arr[mid] - target) <= destination)
            {
                return false;
            }
            
            else if(arr[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid -1;
            }
        }
        
        return -1;
    }
    
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        sort(arr2.begin(),arr2.end());
        
        int count = 0;
        
        for(auto num:arr1)
            
        {
            //Funcation call
            if(isvalid(arr2,num,d))
            {
                count++;
            }
        }
        return count;
    }
};