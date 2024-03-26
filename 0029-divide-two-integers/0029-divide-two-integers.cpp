class Solution {
public:
    int divide(int dividend, int divisor) {
        bitset<32>bs1(dividend);
        bitset<32>bs2(divisor);
        int sign=(bs1[31]^bs2[31])?-1:1;
        long long a=abs((long long)dividend),b=abs((long long)divisor);
        long long res=0;
        for(int i=31;~i;i--)
        {
            if((a>>i)>=b)
            {
                res+=(1LL<<i);
                a-=(b<<i);
            }
        }
        res*=sign;
        if(res>INT_MAX||res<INT_MIN) return INT_MAX;
        return res;
    }
};