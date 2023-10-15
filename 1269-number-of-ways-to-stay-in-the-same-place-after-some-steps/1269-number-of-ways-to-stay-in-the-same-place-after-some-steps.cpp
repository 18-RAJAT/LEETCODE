class Solution {
public:
    int dp[505][505];
    int mod=1000000007;
    int numWays(int steps, int arrLen) {
        function<int(int,int,int)>recur=[&](int pos,int steps,int mod)->int
        {
            //base case
            if(pos>=arrLen || pos<0 || (pos!=0&&steps==0))
            {
                return 0;
            }
            //pruning
            if(pos==0 && steps==0)
            {
                return 1;
            }
            //memo
            int& ans=dp[pos][steps];
            //check with memo+prune
            if(~ans)
            {
                return ans;
            }
            //choices and sol
            int takeStep=recur(pos,steps-1,mod);
            int takeLeft=recur(pos-1,steps-1,mod);
            int takeRight=recur(pos+1,steps-1,mod);
            return ans=((takeStep+takeLeft)%mod+takeRight)%mod;
            
            assert(ans>=0 && dp[pos][steps]<mod);
        };
        memset(dp,-1,sizeof(dp));
        int temp=arrLen;
        int initial=0;
        return recur(initial,steps,mod);
    }
};