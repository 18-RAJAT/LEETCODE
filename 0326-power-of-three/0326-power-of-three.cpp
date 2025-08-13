class Solution {
public:
    bool isPowerOfThree(int n) {  
        if(n==1 || n==3)return true;
        else
        {
            if(n%3!=0 || n==0)return false;
        }
         return  isPowerOfThree(n/3);
        
    }
};