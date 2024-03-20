class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        int temp=x;
        int rev=0;
        while(x)
        {
            int rem=x%10;
            if(rev>INT_MAX/10 || (rev==INT_MAX/10 && rem>7))
            {
                return false;
            }
            if(rev<INT_MIN/10 || (rev==INT_MIN/10 && rem<-8))
            {
                return false;
            }
            rev=rev*10+rem;
            x/=10;
        }
        return rev==temp?true:false;
    }
};