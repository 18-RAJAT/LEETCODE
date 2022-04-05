class Solution {
public:
    int arrangeCoins(int n) {
        
        long left = 1;
        long right = n;
        
        while(left <= right)
        {
            long middle = left + (right - left)/2;
            
            long sum = (middle * (middle + 1)) / 2.0;
            
            if(sum < n)
            {
                left = middle + 1;
            }
            
            else if(sum > n)
            {
                right = middle - 1;
            }
            
            else
            {
                return middle;
            }
        }
        return left - 1;
    }
};