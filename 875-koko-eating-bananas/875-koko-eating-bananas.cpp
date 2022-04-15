class Solution {
public:
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1;
        int right = 1000000000;
        
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            
            if(CanEatInTime(piles,mid,h))
            {
                right = mid - 1;
            }
            
            else
            {
                left = mid + 1;
            }
        }
        
        return left;
        
    }
    
     bool CanEatInTime(vector<int>& piles,int k , int h)
     {
         
         int hours = 0;
         
         for(auto pile : piles)
         {
             int res = pile/k;
             
             hours += res;
             
             if(pile % k != 0)
             {
                 hours++;
             }
         }
         return hours <= h;
     }
    
};