class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                int tot=i*i+j*j,chk=sqrt(tot);
                if(chk*chk==tot && chk<=n)ans++;
            }
        }
        return ans;
    }
};