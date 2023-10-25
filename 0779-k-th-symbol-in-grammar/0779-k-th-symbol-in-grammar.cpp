class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 && k==1)
        {
            return 0;
        }
        function<int(int,int)>power=[&](int x,int n)->int
        {
            if(n==0)
            {
                return 1;
            }
            int y=power(x,n/2);
            if(n%2==0)
            {
                return y*y;
            }
            else
            {
                return x*y*y;
            }
        };
        int x=power(2,n-1);
        if(k<=x/2)
        {
            return kthGrammar(n-1,k);
        }
        else
        {
            return !kthGrammar(n-1,k-x/2);
        }
    }
};