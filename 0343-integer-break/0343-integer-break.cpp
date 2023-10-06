class Solution {
public:
    int integerBreak(int n) {
        if(n<=3)
        {
            return n-1;
        }
        int ans=1;
        while(n>=5)
        {
            ans*=3;
            n-=3;
        }
        ans*=n;
        return ans;
    }
};