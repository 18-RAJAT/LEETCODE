#define pp pair<int , int>

class Solution {
public:
  
    void merge(vector<pp> &arr , vector<int> &count , int l , int mid , int r)
    {
        int i=l , j=mid+1;
        
        vector<pp> temp(r-l+1);
        int k=0;
        
        while(i<=mid && j<=r)
        {
            if(arr[i].first>arr[j].first)
            {
                temp[k++]=arr[i];
				
                count[arr[i].second]+=(r-j+1);
				// as sorted in decresing order , for a value arr[i] , all the values post j will also be smaller 
				// so include all
                i++;
            }
            else
            {
                temp[k++]=arr[j];
                j++;
                
            }
        }
        
        // Now sort in decreasing order
       
        
        while(i<=mid)
        {
           temp[k++]=arr[i];
            i++;
        }
        
        while(j<=r)

        {
            temp[k++]=arr[j];
            j++;
        }
        
        // now put back these dacending sorted value back into arr
        
        for(int i=l;i<=r;i++)
        {
            arr[i]=temp[i-l];
        }
        return ;
    }
    
    void mergesort(vector<pp> &arr , vector<int> &count , int l , int r )
    {
        if(l>=r)
        {
            return ;
        }
        
        int mid=(l+r)/2;
        
        mergesort(arr , count , l , mid);
        mergesort(arr , count , mid+1 , r);
        merge(arr , count , l , mid , r);
        
        
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        
        // The method we use here is Merge sort 
        
        int n=nums.size();
        
        vector<int> count(n , 0);
        
        vector<pp> arr(n);
        
        for(int i=0;i<n;i++)
        {
            arr[i]={nums[i] , i};
        }
        
        
       mergesort(arr , count , 0 , n-1);
        
        return count;
        
        
    }
};