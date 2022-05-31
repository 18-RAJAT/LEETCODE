class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long left =0, right=1e14,mid;
        
        while(left <= right){
            
            mid=(left +right)/2; 
            long long ans=0;                 
            for(int i=0;i<time.size();i++)  
                    
                ans+= mid/time[i];
            
            if(ans < totalTrips) left =mid+1;
            
            else right=mid-1;                 
        }
            
        return left;    
            
        
    }
};
