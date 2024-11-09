class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        long long int index=0,ans=0;
        for(int i=0;i<63;i++)
        {
            if(!((x)&(1ll<<i)))
            {
                if(n&(1ll<<index))
                {
                    ans|=(1ll<<i);
                    
                }
                index++;
            }
        }
        ans|=x;
        return ans;
    }
};