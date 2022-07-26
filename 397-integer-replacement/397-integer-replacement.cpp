class Solution {
public:
    int integerReplacement(long long int n) {
        int ct=0;
        while(n!=1)
        {
            if(n%2==0)n=n/2;
            else
            {
                if(((n-1)/2)%2==0 or (n-1)/2==1) n=n-1;
                else  n++;
            }
            ct++;
        }
        return ct;
    }
};