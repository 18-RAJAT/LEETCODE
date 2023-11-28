class Solution {
public:
    int numberOfWays(string corridor) {
        int n=corridor.size();
        long long int ans=1;
        int cnt=0,seat=0;
        for(int i=0;i<n;++i)
        {
            if(seat%2==0 && seat>=1 && corridor[i]=='P')
            {
                cnt++;
            }
            if(corridor[i]=='S')
            {
                seat++;
                ans*=(cnt+1);
                cnt=0;
                ans%=1000000007;
            }
        }
        return((seat%2==0 && seat>=1)?ans:0);
    }
};