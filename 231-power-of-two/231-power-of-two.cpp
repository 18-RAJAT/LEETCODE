class Solution {
public:
    bool isPowerOfTwo(int n) {
            
      if(n==1 or n==2)
        {
            return true;
        }
        
        else
        {
            if(n%2!=0 or n==0)
            {
                return false;
            }
        }
        
         return  isPowerOfTwo(n/2);
        
    }
};