class Solution {
public:
    bool isPerfectSquare(int num) {
        
        int start = 0;
        int end = num;
        long long int mid;
        
        while(start <= end)
        {
           mid = start + (end - start)/2;
            
            if(mid * mid == num)
            {
                return true;
            }
            
            else if(mid*mid < num)
            {
                start = mid + 1;
            }
            
            else
            {
                end = mid - 1;
            }
        }
        return false;
    }
};