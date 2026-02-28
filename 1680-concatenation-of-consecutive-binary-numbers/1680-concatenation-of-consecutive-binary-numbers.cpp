class Solution {
public:
    int concatenatedBinary(int n) {
        long long int ans=0,cur=0;
        for(int i=1;i<=n;++i)
        {
            if((i&(i-1))==0)cur++;
            ans=(ans<<cur)%1000000007;
            ans+=i%1000000007;
        }
        return ans;
    }
};