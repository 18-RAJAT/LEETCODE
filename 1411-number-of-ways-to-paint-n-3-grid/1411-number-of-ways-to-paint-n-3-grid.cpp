class Solution {
public:
    int numOfWays(int n) {
        int same=6,diff=6,mod=1000000007;
        for(int i=2;i<=n;++i)
        {
            int ns=(1LL*same*3+1LL*2*diff)%mod;
            int nd=(1LL*same*2+1LL*2*diff)%mod;
            same=ns,diff=nd;
        }
        return (same+diff)%mod;
    }
};