class Solution {
public:
    bool isHappy(int n) {
        
        while(true)
        {
            long long sum = 0;
            
            while(n != 0)
            {
                int LastDigit = n%10;
                n = n / 10;
                sum = sum + LastDigit * LastDigit;
            }
            
            if(1 <= sum and sum <= 9)
            {
             if(sum == 1 or sum == 7)
             {
                 return true;
             }  
                else
                {
                   return false;
                }
                
            }
            else
            {
                n = sum;
            }
        }
        
    }
};