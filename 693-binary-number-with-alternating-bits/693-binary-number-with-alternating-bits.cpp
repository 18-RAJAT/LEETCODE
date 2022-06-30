class Solution {
public:
    bool hasAlternatingBits(int n) {
        int tp=n&1;n=n/2;
        while(n>0)
        {
            if((n&1)==tp){return false;}
            tp=n&1;n=n/2;
        }
        return true;
    }
};