class Solution {
public:
    long long makeTheIntegerZero(long long num1, long long num2) {
        if(num1<num2)return -1;
        for(long long i=0;i<=10005;++i)
        {
            long long expo=num1-num2*i,bt=__builtin_popcountll(expo);
            if(bt<=i && i<=expo)return i;
        }
        return -1;
    }
};