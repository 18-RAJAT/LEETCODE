class Solution {
public:
    int right_shift(int x)
    {
        return x>>1;
    }
    int bitwise_xor(int x,int y)
    {
        return x^y;
    }
    int minimumOneBitOperations(int n) {
        int ans=0;
        while(n)
        {
            ans=bitwise_xor(ans,n);
            n=right_shift(n);
        }
        return ans;
    }
};