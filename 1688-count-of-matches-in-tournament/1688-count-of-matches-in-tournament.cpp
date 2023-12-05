class Solution {
public:
    int numberOfMatches(int n) {
        int count=0;
        while(n>=2)
        {
            int div=n/2,mod=n%2;
            count+=div;
            int total=div+mod;
            n=total;
        }
        return count;
    }
};